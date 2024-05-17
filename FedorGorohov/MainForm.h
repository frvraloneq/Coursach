#pragma once

namespace FedorGorohov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;







	private: System::Windows::Forms::TextBox^ Filter_text;
	private: System::Windows::Forms::Button^ Filter_btn;





	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ComboBox^ Filter_box;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GoingTo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ losttime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time_go;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time_end;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vac_seat;
	private: System::Windows::Forms::Button^ clear_filter_btn;
	private: System::Windows::Forms::Button^ btn_load;
	private: System::Windows::Forms::Button^ btn_add;
	private: System::Windows::Forms::Button^ btn_update;
	private: System::Windows::Forms::Button^ dtn_dlt;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ действияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьToolStripMenuItem;









	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GoingTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->losttime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time_go = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time_end = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vac_seat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Filter_text = (gcnew System::Windows::Forms::TextBox());
			this->Filter_btn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->действияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Filter_box = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->clear_filter_btn = (gcnew System::Windows::Forms::Button());
			this->btn_load = (gcnew System::Windows::Forms::Button());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->btn_update = (gcnew System::Windows::Forms::Button());
			this->dtn_dlt = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeight = 30;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->ID, this->GoingTo,
					this->Cost, this->losttime, this->date_column, this->time_go, this->time_end, this->vac_seat
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(26, 140);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowHeadersWidth = 10;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1197, 335);
			this->dataGridView1->TabIndex = 0;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID Рейса";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			// 
			// GoingTo
			// 
			this->GoingTo->HeaderText = L"Откуда-Куда";
			this->GoingTo->MinimumWidth = 6;
			this->GoingTo->Name = L"GoingTo";
			// 
			// Cost
			// 
			this->Cost->HeaderText = L"Стоимость";
			this->Cost->MinimumWidth = 6;
			this->Cost->Name = L"Cost";
			// 
			// losttime
			// 
			this->losttime->HeaderText = L"Время плавания";
			this->losttime->MinimumWidth = 6;
			this->losttime->Name = L"losttime";
			// 
			// date_column
			// 
			this->date_column->HeaderText = L"Дата отплытия";
			this->date_column->MinimumWidth = 6;
			this->date_column->Name = L"date_column";
			// 
			// time_go
			// 
			this->time_go->HeaderText = L"Время отплытия";
			this->time_go->MinimumWidth = 6;
			this->time_go->Name = L"time_go";
			// 
			// time_end
			// 
			this->time_end->HeaderText = L"Время прибытия";
			this->time_end->MinimumWidth = 6;
			this->time_end->Name = L"time_end";
			// 
			// vac_seat
			// 
			this->vac_seat->HeaderText = L"Свободных мест";
			this->vac_seat->MinimumWidth = 6;
			this->vac_seat->Name = L"vac_seat";
			// 
			// Filter_text
			// 
			this->Filter_text->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Filter_text->Location = System::Drawing::Point(173, 41);
			this->Filter_text->Name = L"Filter_text";
			this->Filter_text->Size = System::Drawing::Size(403, 22);
			this->Filter_text->TabIndex = 3;
			this->Filter_text->Click += gcnew System::EventHandler(this, &MainForm::Filter_text_Click);
			// 
			// Filter_btn
			// 
			this->Filter_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Filter_btn->Location = System::Drawing::Point(582, 13);
			this->Filter_btn->Name = L"Filter_btn";
			this->Filter_btn->Size = System::Drawing::Size(136, 37);
			this->Filter_btn->TabIndex = 4;
			this->Filter_btn->Text = L"Отфильтровать";
			this->Filter_btn->UseVisualStyleBackColor = true;
			this->Filter_btn->Click += gcnew System::EventHandler(this, &MainForm::Filter_btn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->действияToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1235, 28);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// действияToolStripMenuItem
			// 
			this->действияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->загрузитьToolStripMenuItem,
					this->обновитьToolStripMenuItem, this->добавитьToolStripMenuItem, this->удалитьToolStripMenuItem
			});
			this->действияToolStripMenuItem->Name = L"действияToolStripMenuItem";
			this->действияToolStripMenuItem->Size = System::Drawing::Size(88, 24);
			this->действияToolStripMenuItem->Text = L"Действия";
			// 
			// загрузитьToolStripMenuItem
			// 
			this->загрузитьToolStripMenuItem->Name = L"загрузитьToolStripMenuItem";
			this->загрузитьToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->загрузитьToolStripMenuItem->Text = L"Загрузить";
			this->загрузитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::btn_load_Click);
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->обновитьToolStripMenuItem->Text = L"Обновить";
			this->обновитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::btn_update_Click);
			// 
			// добавитьToolStripMenuItem
			// 
			this->добавитьToolStripMenuItem->Name = L"добавитьToolStripMenuItem";
			this->добавитьToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->добавитьToolStripMenuItem->Text = L"Добавить";
			this->добавитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::btn_add_Click);
			// 
			// удалитьToolStripMenuItem
			// 
			this->удалитьToolStripMenuItem->Name = L"удалитьToolStripMenuItem";
			this->удалитьToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->удалитьToolStripMenuItem->Text = L"Удалить";
			this->удалитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::dtn_dlt_Click);
			// 
			// Filter_box
			// 
			this->Filter_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Filter_box->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Filter_box->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Filter_box->FormattingEnabled = true;
			this->Filter_box->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"ID Рейса", L"Откуда-Куда", L"Стоимость", L"Время плавания",
					L"Дата отплытия", L"Время отплытия", L"Время прибытия", L"Свободных мест"
			});
			this->Filter_box->Location = System::Drawing::Point(6, 41);
			this->Filter_box->Name = L"Filter_box";
			this->Filter_box->Size = System::Drawing::Size(149, 24);
			this->Filter_box->TabIndex = 6;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->clear_filter_btn);
			this->groupBox1->Controls->Add(this->Filter_box);
			this->groupBox1->Controls->Add(this->Filter_btn);
			this->groupBox1->Controls->Add(this->Filter_text);
			this->groupBox1->Location = System::Drawing::Point(26, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(724, 97);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фильтр";
			// 
			// clear_filter_btn
			// 
			this->clear_filter_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->clear_filter_btn->Location = System::Drawing::Point(582, 56);
			this->clear_filter_btn->Name = L"clear_filter_btn";
			this->clear_filter_btn->Size = System::Drawing::Size(136, 35);
			this->clear_filter_btn->TabIndex = 7;
			this->clear_filter_btn->Text = L"Очистка фильтра";
			this->clear_filter_btn->UseVisualStyleBackColor = true;
			this->clear_filter_btn->Click += gcnew System::EventHandler(this, &MainForm::clear_filter_btn_Click);
			// 
			// btn_load
			// 
			this->btn_load->Location = System::Drawing::Point(73, 13);
			this->btn_load->Name = L"btn_load";
			this->btn_load->Size = System::Drawing::Size(116, 37);
			this->btn_load->TabIndex = 8;
			this->btn_load->Text = L"Загрузить";
			this->btn_load->UseVisualStyleBackColor = true;
			this->btn_load->Click += gcnew System::EventHandler(this, &MainForm::btn_load_Click);
			// 
			// btn_add
			// 
			this->btn_add->Location = System::Drawing::Point(73, 50);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(116, 37);
			this->btn_add->TabIndex = 9;
			this->btn_add->Text = L"Добавить";
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &MainForm::btn_add_Click);
			// 
			// btn_update
			// 
			this->btn_update->Location = System::Drawing::Point(195, 13);
			this->btn_update->Name = L"btn_update";
			this->btn_update->Size = System::Drawing::Size(116, 37);
			this->btn_update->TabIndex = 10;
			this->btn_update->Text = L"Обновить";
			this->btn_update->UseVisualStyleBackColor = true;
			this->btn_update->Click += gcnew System::EventHandler(this, &MainForm::btn_update_Click);
			// 
			// dtn_dlt
			// 
			this->dtn_dlt->Location = System::Drawing::Point(195, 50);
			this->dtn_dlt->Name = L"dtn_dlt";
			this->dtn_dlt->Size = System::Drawing::Size(116, 37);
			this->dtn_dlt->TabIndex = 11;
			this->dtn_dlt->Text = L"Удалить";
			this->dtn_dlt->UseVisualStyleBackColor = true;
			this->dtn_dlt->Click += gcnew System::EventHandler(this, &MainForm::dtn_dlt_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dtn_dlt);
			this->groupBox2->Controls->Add(this->btn_update);
			this->groupBox2->Controls->Add(this->btn_add);
			this->groupBox2->Controls->Add(this->btn_load);
			this->groupBox2->Location = System::Drawing::Point(766, 31);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(320, 97);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Действия";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1235, 487);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1253, 534);
			this->Name = L"MainForm";
			this->Text = L"ИС: Порт";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void Filter_text_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Filter_btn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void clear_filter_btn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dtn_dlt_Click(System::Object^ sender, System::EventArgs^ e);
};
}
