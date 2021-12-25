#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>  
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

namespace LebedevaYulia {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	string mas_numbers[10], before = "";
	std::ifstream file("C:/Users/lebed/source/repos/LebedevaYulia/text.txt");

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(39, 33);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(579, 95);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(30, 198);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(362, 223);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(117, 143);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Запустить сортировку";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(440, 198);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(440, 274);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 433);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		string num_s;
		string edstr;
		string num_out;


		label1->Text = "Лебедева Юлия Сергеевна";
		DateTime^ dt = DateTime::Now;
		label2->Text = Convert::ToString(dt);


		if (file.is_open())
		{
			getline(file, num_s);
		}


		richTextBox1->Text = marshal_as <System::String^>(num_s);

		int start = 0;

		for (int i = 0; i < 10; i++) {
			edstr = num_s.substr(start, 10);

			size_t nulls;
			nulls = edstr.find("0");
			if (nulls != std::string::npos) {
				edstr.replace(nulls, 1, "*");

			}
			mas_numbers[i] = edstr;
			start += 11;
		}
		

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {



		string temp;
		for (int i = 0; i < 10 - 1; i++) {
			for (int j = 0; j < 10 - i - 1; j++) {
				if (mas_numbers[j] > mas_numbers[j + 1]) {
					temp = mas_numbers[j];
					mas_numbers[j] = mas_numbers[j + 1];
					mas_numbers[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			before = before + mas_numbers[i] + "\n";
			richTextBox2->Text = marshal_as <System::String^>(before);
		}



		file.close();
	}



	};
};
