#include "MainForm.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThreadAttribute]
int main(array<String^>^ args) {
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
	FedorGorohov::MainForm form;
	System::Windows::Forms::Application::Run(% form);
}

Void FedorGorohov::MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	Filter_box->Text = "";
	Filter_text->Text = "������ ������";
	return System::Void();
}

System::Void FedorGorohov::MainForm::Filter_text_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Filter_text->Text = "";
	return System::Void();
}

System::Void FedorGorohov::MainForm::Filter_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	int valueCells = -1;
	if (Filter_box->Text == ID->HeaderText) valueCells = 0;
	if (Filter_box->Text == GoingTo->HeaderText) valueCells = 1;
	if (Filter_box->Text == Cost->HeaderText) valueCells = 2;
	if (Filter_box->Text == losttime->HeaderText) valueCells = 3;
	if (Filter_box->Text == date_column->HeaderText) valueCells = 4;
	if (Filter_box->Text == time_go->HeaderText) valueCells = 5;
	if (Filter_box->Text == time_end->HeaderText) valueCells = 6;
	if (Filter_box->Text == vac_seat->HeaderText) valueCells = 7;
	
	if (valueCells == -1) MessageBox::Show("�������� ����� ������� ������ �����������!","������!");
	else if (Filter_text->Text == "") MessageBox::Show("������� ������ ��� ������ � ������ ������!","������!");
	else for (int i = 0; i < dataGridView1->RowCount-1; i++)
	{
		if (!(dataGridView1->Rows[i]->Cells[valueCells]->Value->ToString()->Contains(Filter_text->Text)))
		{
			dataGridView1->Rows[i]->Visible = false;
		}
	}
	return System::Void();
}

System::Void FedorGorohov::MainForm::clear_filter_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	Filter_box->SelectedItem = nullptr;
	Filter_text->Text = "������ ������";
	for (int i = 0; i < dataGridView1->RowCount; i++)
	{
		dataGridView1->Rows[i]->Visible = true;
	}
	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_load_Click(System::Object^ sender, System::EventArgs^ e)
{
	//������������ � ��
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // ������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� �����������
	String^ query = "SELECT * FROM [table1]"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//�������� ������
	if (dbReader->HasRows == false) {
		MessageBox::Show("������ ���������� ������!", "������!");
	}
	else {
		//�������� ������ � ������� �����
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["FromWhere"], dbReader["Cost"], dbReader["SwimTime"], dbReader["SailDate"], dbReader["sailTime"], dbReader["ArriveTime"], dbReader["VacantSeats"]);
		}
	}

	//��������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	//������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[7]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!","��������!");
		return;
	}

	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
		if ((dataGridView1->Rows[index]->Cells[0]->Value->ToString() == dataGridView1->Rows[i]->Cells[0]->Value->ToString()) && (i != index)) {
			MessageBox::Show("ID ����� ������ ���� ��������!", "��������!");
			return;
		}

	//��������� ������
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ FromTo = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Cost = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ LostTime = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Date = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ TimeGo = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ TimeEnd = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ VacPlace = dataGridView1->Rows[index]->Cells[7]->Value->ToString();

	//������������ � ��
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // ������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� �����������
	String^ query = "INSERT INTO [table1] VALUES ("+ id +", '"+ FromTo +"', '"+ Cost +"','"+ LostTime +"', '"+ Date +"', '"+ TimeGo +"', '" + TimeEnd + "', "+ VacPlace +")"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������

	//��������� ������
	try {
		if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("������ ���������� �������!", "������!");
		else MessageBox::Show("������ ���� ���������!", "������!");

		//��������� ����������
		dbConnection->Close();
	}
	catch (OleDbException^ e) {
		MessageBox::Show("�� ����� ������������ ������! �������� ������ � ���������� �����!", "������!");
	}


	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ���������� 
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	//������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[7]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
		if ((dataGridView1->Rows[index]->Cells[0]->Value->ToString() == dataGridView1->Rows[i]->Cells[0]->Value->ToString()) && (i != index)) {
			MessageBox::Show("ID ����� ������ ���� ��������!", "��������!");
			return;
		}

	//��������� ������
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ FromTo = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Cost = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ LostTime = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Date = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ TimeGo = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ TimeEnd = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ VacPlace = dataGridView1->Rows[index]->Cells[7]->Value->ToString();

	//������������ � ��
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // ������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� �����������
	String^ query = "UPDATE [table1] SET FromWhere = '"+FromTo+"', Cost = '"+Cost+"',"+
					"SwimTime = '"+LostTime+"', SailDate = '"+Date+"', SailTime = '"+TimeGo+"',"+
					"ArriveTime = '"+TimeEnd+"', VacantSeats = "+VacPlace+" WHERE ID = "+ id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������

	//��������� ������	
	try {
		if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("������ ���������� �������!", "������!");
		else MessageBox::Show("������ ���� ��������!", "������!");

		//��������� ����������
		dbConnection->Close();
	}
	catch (OleDbException^ e) {
		MessageBox::Show("�� ����� ������������ ������! �������� ������ � ���������� �����!", "������!");
	}

	return System::Void();
}

System::Void FedorGorohov::MainForm::dtn_dlt_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ��������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ��������!", "��������!");
		return;
	}

	//������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) 
	{
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	//��������� ������
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//������������ � ��
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // ������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� �����������
	String^ query = "DELETE FROM [table1] WHERE ID =" + id; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("������ ���������� �������!", "������!");
	else
	{
		MessageBox::Show("������ �������!", "������!");
		//������� ������ �� ������� �����
		dataGridView1->Rows->RemoveAt(index); 
	}
	//��������� ����������
	dbConnection->Close();

	return System::Void();
}


