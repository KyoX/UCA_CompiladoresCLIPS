#pragma once

namespace ide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Resultado
	/// </summary>
	public ref class Resultado : public System::Windows::Forms::Form
	{
	public:
		Resultado(String^ texto)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->richTextBox1->Text = texto;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Resultado()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::GrayText;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(375, 542);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// Resultado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 542);
			this->Controls->Add(this->richTextBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Resultado";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Salida scanner";
			this->Load += gcnew System::EventHandler(this, &Resultado::Resultado_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void Resultado_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
