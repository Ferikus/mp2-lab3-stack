#pragma once
#include "../../Stack/Calculation.h"
#include <msclr\marshal_cppstd.h>

namespace Forma1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
	private: System::Windows::Forms::TextBox^ textBox_expr;
	private: System::Windows::Forms::Label^ label_enter;
	private: System::Windows::Forms::Label^ label_res;
	private: System::Windows::Forms::Button^ button_calc;

		   // HIDE

	private: System::Windows::Forms::Button^ button_close;


 // MOVE
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gr = CreateGraphics();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_expr = (gcnew System::Windows::Forms::TextBox());
			this->label_enter = (gcnew System::Windows::Forms::Label());
			this->button_close = (gcnew System::Windows::Forms::Button());
			this->label_res = (gcnew System::Windows::Forms::Label());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_expr
			// 
			this->textBox_expr->Location = System::Drawing::Point(206, 66);
			this->textBox_expr->Name = L"textBox_expr";
			this->textBox_expr->Size = System::Drawing::Size(246, 21);
			this->textBox_expr->TabIndex = 11;
			this->textBox_expr->Text = L"0";
			// 
			// label_enter
			// 
			this->label_enter->AutoSize = true;
			this->label_enter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_enter->Location = System::Drawing::Point(24, 66);
			this->label_enter->Name = L"label_enter";
			this->label_enter->Size = System::Drawing::Size(155, 20);
			this->label_enter->TabIndex = 13;
			this->label_enter->Text = L"Enter the expression";
			// 
			// button_close
			// 
			this->button_close->Location = System::Drawing::Point(897, 40);
			this->button_close->Name = L"button_close";
			this->button_close->Size = System::Drawing::Size(75, 72);
			this->button_close->TabIndex = 15;
			this->button_close->Text = L"Close";
			this->button_close->UseVisualStyleBackColor = true;
			this->button_close->Click += gcnew System::EventHandler(this, &MyForm::button_close_Click);
			// 
			// label_res
			// 
			this->label_res->AutoSize = true;
			this->label_res->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_res->Location = System::Drawing::Point(488, 67);
			this->label_res->Name = L"label_res";
			this->label_res->Size = System::Drawing::Size(31, 20);
			this->label_res->TabIndex = 16;
			this->label_res->Text = L"res";
			// 
			// button_calc
			// 
			this->button_calc->Location = System::Drawing::Point(806, 41);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(75, 72);
			this->button_calc->TabIndex = 17;
			this->button_calc->Text = L"Calculate";
			this->button_calc->UseVisualStyleBackColor = true;
			this->button_calc->Click += gcnew System::EventHandler(this, &MyForm::button_calc_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 161);
			this->Controls->Add(this->button_calc);
			this->Controls->Add(this->label_res);
			this->Controls->Add(this->button_close);
			this->Controls->Add(this->label_enter);
			this->Controls->Add(this->textBox_expr);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_calc_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			std::string s;
			s = msclr::interop::marshal_as<std::string>(textBox_expr->Text);
			TCalc expr(s);
			double res = expr.calc();
			label_res->Text = Convert::ToString(res);
		}
		catch (const char* ex)
		{
			label_res->Text = "Wrong expression";
		}
	}
private: System::Void button_close_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
