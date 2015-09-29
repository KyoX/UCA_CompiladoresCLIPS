#pragma once

namespace ide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Parametros
	/// </summary>
	public ref class Parametros : public System::Windows::Forms::Form
	{
	public:
		Parametros(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Parametros()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	//Declaracion de parametros por defecto
	private: String^ CURRENT_DIR;
	private: unsigned int MAXLINEA;
	private: unsigned int MAXDIGIT;
	private: unsigned int MAXID;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cantidad maxima de caracteres por linea:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Maxima cantidad de digitos por numero:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(307, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Maxima cantidad de caracteres permitidos para un identificador:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(414, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Parametros::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(495, 152);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Parametros::button2_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(414, 40);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(156, 20);
			this->numericUpDown1->TabIndex = 5;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(414, 73);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(156, 20);
			this->numericUpDown2->TabIndex = 6;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(414, 111);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(156, 20);
			this->numericUpDown3->TabIndex = 7;
			// 
			// Parametros
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 185);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Parametros";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Parametros";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Parametros::Parametros_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/*Sets & gets de los parametros*/
	public: void setMaxLinea(unsigned int maxLinea){
		this->MAXLINEA = maxLinea;
	}
	public: void setMaxDigit(unsigned int maxDigit){
		this->MAXDIGIT = maxDigit;
	}
	public: void setMaxId(unsigned int maxId){
		this->MAXID = maxId;
	}
	public: void setCurrentDir(String^ currentDir){
		this->CURRENT_DIR = currentDir;
	}
	public: unsigned int getMaxLinea(){
		return this->MAXLINEA;
	}
	public: unsigned int getMaxDigit(){
		return this->MAXDIGIT;
	}
	public: unsigned int getMaxId(){
		return this->MAXID;
	}
			/************************/

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		MAXLINEA = (unsigned)numericUpDown1->Value;
		MAXDIGIT = (unsigned)numericUpDown2->Value;
		MAXID = (unsigned)numericUpDown3->Value;
		try{
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(CURRENT_DIR + "param.txt");
			sw->WriteLine("MAXLINEA;" + MAXLINEA);
			sw->WriteLine("MAXDIGIT;" + MAXDIGIT);
			sw->WriteLine("MAXID;" + MAXID);
			sw->Close();
		}
		catch (Exception^ e){
			MessageBox::Show("¿Seguro que tiene permisos para escribir en el disco? porque no se pudo crear el archivo de parametros, saliendo de la aplicacion.", "Ocurrio un error con el archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
	private: System::Void Parametros_Load(System::Object^  sender, System::EventArgs^  e) {
		numericUpDown1->Value = MAXLINEA;
		numericUpDown2->Value = MAXDIGIT;
		numericUpDown3->Value = MAXID;
	}
};
}
