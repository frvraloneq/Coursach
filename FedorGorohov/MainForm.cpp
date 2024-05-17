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
	Filter_text->Text = "Строка поиска";
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
	
	if (valueCells == -1) MessageBox::Show("Выберите какой столбец будете фильтровать!","Ошибка!");
	else if (Filter_text->Text == "") MessageBox::Show("Введите данные для поиска в строке поиска!","Ошибка!");
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
	Filter_text->Text = "Строка поиска";
	for (int i = 0; i < dataGridView1->RowCount; i++)
	{
		dataGridView1->Rows[i]->Visible = true;
	}
	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_load_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Подключаемся к БД
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //Открываем сооединение
	String^ query = "SELECT * FROM [table1]"; //Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //Команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//проверка данных
	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка считывания данных!", "Ошибка!");
	}
	else {
		//Заполням данные в таблицу формы
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["FromWhere"], dbReader["Cost"], dbReader["SwimTime"], dbReader["SailDate"], dbReader["sailTime"], dbReader["ArriveTime"], dbReader["VacantSeats"]);
		}
	}

	//Закрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для обновления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	//Индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[7]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!","Внимание!");
		return;
	}

	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
		if ((dataGridView1->Rows[index]->Cells[0]->Value->ToString() == dataGridView1->Rows[i]->Cells[0]->Value->ToString()) && (i != index)) {
			MessageBox::Show("ID Рейса должен быть уникален!", "Внимание!");
			return;
		}

	//Считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ FromTo = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Cost = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ LostTime = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Date = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ TimeGo = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ TimeEnd = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ VacPlace = dataGridView1->Rows[index]->Cells[7]->Value->ToString();

	//Подключаемся к БД
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //Открываем сооединение
	String^ query = "INSERT INTO [table1] VALUES ("+ id +", '"+ FromTo +"', '"+ Cost +"','"+ LostTime +"', '"+ Date +"', '"+ TimeGo +"', '" + TimeEnd + "', "+ VacPlace +")"; //Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //Команда

	//Выполняем запрос
	try {
		if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
		else MessageBox::Show("Данные были добавлены!", "Готово!");

		//Закрываем соединение
		dbConnection->Close();
	}
	catch (OleDbException^ e) {
		MessageBox::Show("Вы ввели некорректные данные! Измените данные и попробуйте снова!", "Ошибка!");
	}


	return System::Void();
}

System::Void FedorGorohov::MainForm::btn_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления 
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для обновления!", "Внимание!");
		return;
	}

	//Индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[7]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
		if ((dataGridView1->Rows[index]->Cells[0]->Value->ToString() == dataGridView1->Rows[i]->Cells[0]->Value->ToString()) && (i != index)) {
			MessageBox::Show("ID Рейса должен быть уникален!", "Внимание!");
			return;
		}

	//Считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ FromTo = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Cost = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ LostTime = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Date = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ TimeGo = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ TimeEnd = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ VacPlace = dataGridView1->Rows[index]->Cells[7]->Value->ToString();

	//Подключаемся к БД
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //Открываем сооединение
	String^ query = "UPDATE [table1] SET FromWhere = '"+FromTo+"', Cost = '"+Cost+"',"+
					"SwimTime = '"+LostTime+"', SailDate = '"+Date+"', SailTime = '"+TimeGo+"',"+
					"ArriveTime = '"+TimeEnd+"', VacantSeats = "+VacPlace+" WHERE ID = "+ id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //Команда

	//Выполняем запрос	
	try {
		if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
		else MessageBox::Show("Данные были изменены!", "Готово!");

		//Закрываем соединение
		dbConnection->Close();
	}
	catch (OleDbException^ e) {
		MessageBox::Show("Вы ввели некорректные данные! Измените данные и попробуйте снова!", "Ошибка!");
	}

	return System::Void();
}

System::Void FedorGorohov::MainForm::dtn_dlt_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для удаления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для удаления!", "Внимание!");
		return;
	}

	//Индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) 
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//Подключаемся к БД
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source = Database1.mdb"; // Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //Открываем сооединение
	String^ query = "DELETE FROM [table1] WHERE ID =" + id; //Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //Команда

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
	{
		MessageBox::Show("Данные удалены!", "Готово!");
		//Удаляем строку из таблицы формы
		dataGridView1->Rows->RemoveAt(index); 
	}
	//Закрываем соединение
	dbConnection->Close();

	return System::Void();
}


