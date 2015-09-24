#pragma once
#include "AboutUs.h";

namespace ide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  guardarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cortarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copiarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pegarToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  verToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  parametrosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ejecutarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  analisadorLexicograficoToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  verAyudapdfToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreLosProgramadoresToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: String^ bufferedText;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cortarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copiarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pegarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->parametrosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ejecutarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->analisadorLexicograficoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verAyudapdfToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreLosProgramadoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->editarToolStripMenuItem, this->verToolStripMenuItem, this->ejecutarToolStripMenuItem, this->ayudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->guardarToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->fileToolStripMenuItem->Text = L"Archivo";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newToolStripMenuItem.Image")));
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->newToolStripMenuItem->Text = L"Nuevo";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->openToolStripMenuItem->Text = L"Abrir";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::openToolStripMenuItem_Click);
			// 
			// guardarToolStripMenuItem
			// 
			this->guardarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guardarToolStripMenuItem.Image")));
			this->guardarToolStripMenuItem->Name = L"guardarToolStripMenuItem";
			this->guardarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->guardarToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->guardarToolStripMenuItem->Text = L"Guardar";
			this->guardarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::guardarToolStripMenuItem_Click);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"salirToolStripMenuItem.Image")));
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->salirToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::salirToolStripMenuItem_Click);
			// 
			// editarToolStripMenuItem
			// 
			this->editarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->cortarToolStripMenuItem,
					this->copiarToolStripMenuItem, this->pegarToolStripMenuItem
			});
			this->editarToolStripMenuItem->Name = L"editarToolStripMenuItem";
			this->editarToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->editarToolStripMenuItem->Text = L"Editar";
			// 
			// cortarToolStripMenuItem
			// 
			this->cortarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cortarToolStripMenuItem.Image")));
			this->cortarToolStripMenuItem->Name = L"cortarToolStripMenuItem";
			this->cortarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->cortarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cortarToolStripMenuItem->Text = L"Cortar";
			this->cortarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::cortarToolStripMenuItem_Click);
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copiarToolStripMenuItem.Image")));
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copiarToolStripMenuItem->Text = L"Copiar";
			this->copiarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::copiarToolStripMenuItem_Click);
			// 
			// pegarToolStripMenuItem
			// 
			this->pegarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pegarToolStripMenuItem.Image")));
			this->pegarToolStripMenuItem->Name = L"pegarToolStripMenuItem";
			this->pegarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pegarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->pegarToolStripMenuItem->Text = L"Pegar";
			this->pegarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::pegarToolStripMenuItem_Click);
			// 
			// verToolStripMenuItem
			// 
			this->verToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->parametrosToolStripMenuItem });
			this->verToolStripMenuItem->Name = L"verToolStripMenuItem";
			this->verToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->verToolStripMenuItem->Text = L"Ver";
			// 
			// parametrosToolStripMenuItem
			// 
			this->parametrosToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"parametrosToolStripMenuItem.Image")));
			this->parametrosToolStripMenuItem->Name = L"parametrosToolStripMenuItem";
			this->parametrosToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->parametrosToolStripMenuItem->Text = L"Parametros";
			// 
			// ejecutarToolStripMenuItem
			// 
			this->ejecutarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->analisadorLexicograficoToolStripMenuItem });
			this->ejecutarToolStripMenuItem->Name = L"ejecutarToolStripMenuItem";
			this->ejecutarToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->ejecutarToolStripMenuItem->Text = L"Ejecutar";
			// 
			// analisadorLexicograficoToolStripMenuItem
			// 
			this->analisadorLexicograficoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"analisadorLexicograficoToolStripMenuItem.Image")));
			this->analisadorLexicograficoToolStripMenuItem->Name = L"analisadorLexicograficoToolStripMenuItem";
			this->analisadorLexicograficoToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->analisadorLexicograficoToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->analisadorLexicograficoToolStripMenuItem->Text = L"Analizador lexicográfico";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->verAyudapdfToolStripMenuItem,
					this->sobreLosProgramadoresToolStripMenuItem
			});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// verAyudapdfToolStripMenuItem
			// 
			this->verAyudapdfToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"verAyudapdfToolStripMenuItem.Image")));
			this->verAyudapdfToolStripMenuItem->Name = L"verAyudapdfToolStripMenuItem";
			this->verAyudapdfToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->verAyudapdfToolStripMenuItem->Text = L"Ver ayuda.pdf";
			// 
			// sobreLosProgramadoresToolStripMenuItem
			// 
			this->sobreLosProgramadoresToolStripMenuItem->Name = L"sobreLosProgramadoresToolStripMenuItem";
			this->sobreLosProgramadoresToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->sobreLosProgramadoresToolStripMenuItem->Text = L"Sobre los programadores";
			this->sobreLosProgramadoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::sobreLosProgramadoresToolStripMenuItem_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->richTextBox1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->richTextBox2);
			this->splitContainer1->Size = System::Drawing::Size(1008, 513);
			this->splitContainer1->SplitterDistance = 403;
			this->splitContainer1->TabIndex = 4;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Moccasin;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1008, 403);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::InfoText;
			this->richTextBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(0, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(1008, 106);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 537);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CLIPS IDE";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		cerrar();
	}
	private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		salir();
	}

	void salir(){
		if (richTextBox1->Text->Length > 0){ // dummie validacion
			System::Windows::Forms::DialogResult dr;
			dr = MessageBox::Show("Se ha modificado el archivo, desea guardar los cambios?", "Aviso", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (dr == System::Windows::Forms::DialogResult::Yes){
						 // guardo el archivo
			}
			else{
				Application::Exit();
			}
		}
		else {
			Application::Exit();
		}
	}
	void cerrar(){
		if (richTextBox1->Text->Length > 0){ // dummie validacion
			System::Windows::Forms::DialogResult dr;
			dr = MessageBox::Show("Parece que ha estado trabajando, desea guardar los cambios?", "Aviso", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (dr == System::Windows::Forms::DialogResult::Yes){
				// guardo el archivo
			}
			else{
				richTextBox1->Text = "";
			}
		}
		else {
			richTextBox1->Text = "";
		}
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
			richTextBox1->Text = sr->ReadToEnd();
			sr->Close();
		}

	}
	
	private: System::Void copiarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		bufferedText = richTextBox1->SelectedText;
	}

	private: System::Void pegarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!String::IsNullOrEmpty(bufferedText)){
			richTextBox1->SelectedText = bufferedText;
		}
	}
	private: System::Void cortarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		bufferedText = richTextBox1->SelectedText;
		richTextBox1->SelectedText = "";
	}
	private: System::Void guardarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void sobreLosProgramadoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		AboutUs^ au = gcnew AboutUs();
		au->ShowDialog();
	}
};

	
}
