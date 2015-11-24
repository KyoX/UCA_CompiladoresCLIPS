#pragma once
#include <windows.h>
#include <iostream>
#include "AboutUs.h"
#include "Resultado.h"
#include "Parametros.h"
#include "scanner.h"
#include "scanner.cpp"
#using <mscorlib.dll>
#using <System.dll>

namespace ide {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Runtime::InteropServices;
	using namespace System::Collections::Generic;

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

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: String^ bufferedText;
	private: Boolean modificado;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	//Declaracion de parametros globales por defecto
	private: String^ CURRENT_DIR;
	private: unsigned int MAXLINEA;
	private: unsigned int MAXDIGIT;
	private: unsigned int MAXID;
	private: array <String^>^ palabrasReservadas;
	private: array <String^>^ TockensPalabrasReservadas;
	private: array <String^>^ operadores;
	private: array <String^>^ TockensOperadores;
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  scannerParserToolStripMenuItem;


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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
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
			this->scannerParserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verAyudapdfToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreLosProgramadoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
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
			this->cortarToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->cortarToolStripMenuItem->Text = L"Cortar";
			this->cortarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::cortarToolStripMenuItem_Click);
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copiarToolStripMenuItem.Image")));
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->copiarToolStripMenuItem->Text = L"Copiar";
			this->copiarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::copiarToolStripMenuItem_Click);
			// 
			// pegarToolStripMenuItem
			// 
			this->pegarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pegarToolStripMenuItem.Image")));
			this->pegarToolStripMenuItem->Name = L"pegarToolStripMenuItem";
			this->pegarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pegarToolStripMenuItem->Size = System::Drawing::Size(151, 22);
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
			this->parametrosToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->parametrosToolStripMenuItem->Text = L"Parametros";
			this->parametrosToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::parametrosToolStripMenuItem_Click);
			// 
			// ejecutarToolStripMenuItem
			// 
			this->ejecutarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->analisadorLexicograficoToolStripMenuItem,
					this->scannerParserToolStripMenuItem
			});
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
			this->analisadorLexicograficoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::analisadorLexicograficoToolStripMenuItem_Click);
			// 
			// scannerParserToolStripMenuItem
			// 
			this->scannerParserToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scannerParserToolStripMenuItem.Image")));
			this->scannerParserToolStripMenuItem->Name = L"scannerParserToolStripMenuItem";
			this->scannerParserToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F6;
			this->scannerParserToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->scannerParserToolStripMenuItem->Text = L"Scanner - parser";
			this->scannerParserToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::scannerParserToolStripMenuItem_Click);
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
			this->verAyudapdfToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->verAyudapdfToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->verAyudapdfToolStripMenuItem->Text = L"Ver ayuda.pdf";
			this->verAyudapdfToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::verAyudapdfToolStripMenuItem_Click);
			// 
			// sobreLosProgramadoresToolStripMenuItem
			// 
			this->sobreLosProgramadoresToolStripMenuItem->Name = L"sobreLosProgramadoresToolStripMenuItem";
			this->sobreLosProgramadoresToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->sobreLosProgramadoresToolStripMenuItem->Text = L"Sobre los programadores";
			this->sobreLosProgramadoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::sobreLosProgramadoresToolStripMenuItem_Click);
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
			// richTextBox1
			// 
			this->richTextBox1->AcceptsTab = true;
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Moccasin;
			this->richTextBox1->Location = System::Drawing::Point(0, 24);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1008, 513);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Main::richTextBox1_TextChanged_1);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(908, 441);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(100, 96);
			this->richTextBox2->TabIndex = 5;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Visible = false;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 537);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CLIPS IDE";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void guardar(Boolean bajoDemanda){
		Boolean guardar = false;
		if (modificado && !bajoDemanda){
			if (MessageBox::Show("El archivo parece haber sido modificado, ¿desea guardar los cambios?", "Cambios sin guardar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
				guardar = true;
			}
		}
		if (bajoDemanda || guardar){
			saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Title = "Guardar archivo";
			saveFileDialog1->ShowDialog();
			if (saveFileDialog1->FileName != ""){
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);
				sw->Write(richTextBox1->Text);
				sw->Close();
				modificado = false;
			}
		}
	}
	void salir(){
		if (modificado){ // dummie validacion
			guardar(false);
			Application::Exit();
		}
		else {
			Application::Exit();
		}
	}
	void cerrar(){
		if (modificado){ // dummie validacion
			guardar(false);
			richTextBox1->Text = "";
		}
		else {
			richTextBox1->Text = "";
		}
	}
	/*
		por falta de tiempo y debido a que visual studio me saco el dedo
		toco inicializar de forma sucia el arreglo 
		¯\_(-_-)_/'
	*/
	void inicializarPalabrasReservadas(){
		palabrasReservadas =  gcnew array<String^>(20);

		palabrasReservadas[0] = "defmodule";
		palabrasReservadas[1] = "deftemplate";
		palabrasReservadas[2] = "defmethod";
		palabrasReservadas[3] = "deffunction";
		palabrasReservadas[4] = "multislot";
		palabrasReservadas[5] = "slot";
		palabrasReservadas[6] = "deffacts";
		palabrasReservadas[7] = "defrule";
		palabrasReservadas[8] = "declare";
		palabrasReservadas[9] = "test";
		palabrasReservadas[10] = "assert";
		palabrasReservadas[11] = "import";
		palabrasReservadas[12] = "export";
		palabrasReservadas[13] = "type";
		palabrasReservadas[14] = "range";
		palabrasReservadas[15] = "retract";
		palabrasReservadas[16] = "modify";
		palabrasReservadas[17] = "bind";
		palabrasReservadas[18] = "printout";
		palabrasReservadas[19] = "read";
		// lo ordeno alfabeticamente, para la busqueda binaria
		ordenarArreglo(palabrasReservadas,true);
		
	}

	//Misma historia que arriba... espero que no se note cuando "amo" visual studio ...
	void inicializarTockensPalRes(){
		TockensPalabrasReservadas = gcnew array<String^>(20);
		TockensPalabrasReservadas[0] = "defmoduleTock";
		TockensPalabrasReservadas[1] = "deftemplateTock";
		TockensPalabrasReservadas[2] = "defmethodTock";
		TockensPalabrasReservadas[3] = "deffunctionTock";
		TockensPalabrasReservadas[4] = "multislotTock";
		TockensPalabrasReservadas[5] = "slotTock";
		TockensPalabrasReservadas[6] = "deffactsTock";
		TockensPalabrasReservadas[7] = "defruleTock";
		TockensPalabrasReservadas[8] = "declareTock";
		TockensPalabrasReservadas[9] = "testTock";
		TockensPalabrasReservadas[10] = "assertTock";
		TockensPalabrasReservadas[11] = "importTock";
		TockensPalabrasReservadas[12] = "exportTock";
		TockensPalabrasReservadas[13] = "typeTock";
		TockensPalabrasReservadas[14] = "rangeTock";
		TockensPalabrasReservadas[15] = "retractTock";
		TockensPalabrasReservadas[16] = "modifyTock";
		TockensPalabrasReservadas[17] = "bindTock";
		TockensPalabrasReservadas[18] = "printoutTock";
		TockensPalabrasReservadas[19] = "readTock";
		//tiene que hacer juego con el de palabras reservadas
		ordenarArreglo(TockensPalabrasReservadas, true);
	}

	//La historia se repite, suerte que tengo Sublime para hacer esto
	void inicializarOperadores(){
		operadores = gcnew array<String^>(17);
		operadores[0] = "!=";
		operadores[1] = "*";
		operadores[2] = "=>";
		operadores[3] = "+";
		operadores[4] = "-";
		operadores[5] = "/";
		operadores[6] = "<";
		operadores[7] = "<=";
		operadores[8] = "&";
		operadores[9] = "=";
		operadores[10] = ">";
		operadores[11] = ">=";
		operadores[12] = "?";
		operadores[13] = "(";
		operadores[14] = ")";
		operadores[15] = "~";
		operadores[16] = "\"";
		
		//ordenarArreglo(operadores, true);
	}

	//Ultima inicializacion forzada... espero
	void inicializarTockensOpe(){
		TockensOperadores = gcnew array<String^>(17);
		TockensOperadores[0] = "!=_OpTock";
		TockensOperadores[1] = "*_OpTock";
		TockensOperadores[2] = "=>_OpTock";
		TockensOperadores[3] = "+_OpTock";
		TockensOperadores[4] = "-_OpTock";
		TockensOperadores[5] = "/_OpTock";
		TockensOperadores[6] = "<_OpTock";
		TockensOperadores[7] = "<=_OpTock";
		TockensOperadores[8] = "&_OpTock";
		TockensOperadores[9] = "=_OpTock";
		TockensOperadores[10] = ">_OpTock";
		TockensOperadores[11] = ">=_OpTock";
		TockensOperadores[12] = "?_OpTock";
		TockensOperadores[13] = "(_OpTock";
		TockensOperadores[14] = ")_OpTock";
		TockensOperadores[15] = "~_OpTock";
		TockensOperadores[16] = "\"_OpTock";
		
		//ordenarArreglo(TockensOperadores, true);
	}

	void ordenarArreglo(array <String^>^ arreglo, bool recursivo){
		String^ temp;
		for (int i = 1; i < arreglo->Length; i++){
			temp = arreglo[i-1];
			
			// veo si la posicion anterior es mayor a la actual
			if (temp->CompareTo(arreglo[i]) > 0){
				arreglo[i - 1] = arreglo[i];
				arreglo[i] = temp;
				i = 1;// vuelvo a la posicion inicial para dar otra pasada
			}
		}

		if (recursivo){
			// volviendo a pasar para evitar dejar algo de lado
			ordenarArreglo(arreglo, false);
		}
	}

	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		cerrar();
	}
	private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (modificado){
			guardar(false);
		}
		openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Title = "Abrir archivo";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			try{
				System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
				richTextBox1->Text = sr->ReadToEnd();
				sr->Close();
				modificado = false;	//solo lo ha abierto, aun no hay cambios
			}
			catch (Exception^ e){
				MessageBox::Show("Lamentablemente no se pudo abrir el archivo: " + openFileDialog1->FileName, "Ocurrio un error con el archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
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
		guardar(true);
	}
	private: System::Void sobreLosProgramadoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		AboutUs^ au = gcnew AboutUs();
		au->ShowDialog();
	}
	private: System::Void verAyudapdfToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Process^ ayudaPdf = gcnew Process();
		try {
			ayudaPdf->StartInfo->FileName = "ayuda.pdf";
			ayudaPdf->Start();
		}
		catch (Exception^ e){
			MessageBox::Show("No se pudo abrir el archivo ayuda.pdf", "Hay un problema", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		modificado = true; //marco que ha hecho algun cambio en el codigo
	}

	private: System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
		try{

			/*Inicializacion de parametros por defecto que no dependen del contexto*/
			modificado = false;
			MAXLINEA = 500;
			MAXDIGIT = 11;
			MAXID = 100;
			
			/* Inicializacion del contexto: directorio actual y posicion del scanner*/
			char buffer[MAX_PATH];
			GetCurrentDirectoryA(MAX_PATH, buffer);
			CURRENT_DIR = gcnew String(buffer);
			CURRENT_DIR = CURRENT_DIR + "\\"; //ya inicialice el directorio local, ahora a intentar leer el archivo

			//fuerzo la inicializacion de los arreglos
			inicializarPalabrasReservadas();
			inicializarTockensPalRes();
			inicializarOperadores();
			inicializarTockensOpe();
			
			/**********************************************************************/
			
			System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(CURRENT_DIR + "param.txt");
			String^ temp;
			array<String^>^ keyValue;
			while (sr->Peek() >= 0){
				temp = sr->ReadLine();
				keyValue = temp->Split(';');
				if (String::Compare(keyValue[0],"MAXLINEA")==0){
					MAXLINEA = System::Convert::ToInt32(keyValue[1]);
				}
				if (String::Compare(keyValue[0], "MAXDIGIT") == 0){
					MAXDIGIT = System::Convert::ToInt32(keyValue[1]);
				}
				if (String::Compare(keyValue[0], "MAXID") == 0){
					MAXID = System::Convert::ToInt32(keyValue[1]);
				}
			}
			sr->Close();
		}
		catch (Exception^ e){ // fallo al leer el archivo
			// tratando de crear un nuevo archivo de parametros
			MessageBox::Show("Lamentablemente no se pudo abrir el archivo de parametros creando uno nuevo", "Ocurrio un error con el archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
			try{
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(CURRENT_DIR + "param.txt");
				sw->WriteLine("MAXLINEA;" + MAXLINEA);
				sw->WriteLine("MAXDIGIT;" + MAXDIGIT);
				sw->WriteLine("MAXID;" + MAXID);
				sw->Close();
			}
			catch (Exception^ e){
				MessageBox::Show("¿Seguro que tiene permisos para escribir en el disco? porque no se pudo crear el archivo de parametros, saliendo de la aplicacion.", "Ocurrio un error con el archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
				modificado = false;
				salir();
			}
		}
	}
	private: System::Void Main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (modificado){
			guardar(false);
		}
	}
	private: System::Void parametrosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Parametros^ params = gcnew Parametros();
		params->setCurrentDir(this->CURRENT_DIR);
		params->setMaxLinea(this->MAXLINEA);
		params->setMaxDigit(this->MAXDIGIT);
		params->setMaxId(this->MAXID);
		
		params->ShowDialog();

		MAXLINEA = params->getMaxLinea();
		MAXDIGIT = params->getMaxDigit();
		MAXID = params->getMaxId();

	}
	private: System::Void analisadorLexicograficoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int result = scannerLexicografico(richTextBox1->Text, richTextBox2, palabrasReservadas, 
										TockensPalabrasReservadas, operadores, TockensOperadores,
										MAXLINEA, MAXDIGIT, MAXID,0,richTextBox1);
		if (result == ERROR){
			MessageBox::Show("Ocurrio un error en el analizador lexicografico", "Algo salio mal", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else{
			Resultado^ res = gcnew Resultado(richTextBox2->Text);
			res->ShowDialog();
		}
		
	}
	// codigo para el resaltado de las palabras clave, aun no funcional, por eso esta comentado
	private: System::Void richTextBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		

		/*String^ texto = richTextBox1->Text;
		int idex = -1;
		array<Char>^ copyText = texto->ToCharArray();
		
		String^ palabaABuscar = "Hola";
		int indicePivote = 0;

		richTextBox1->SelectAll();
		richTextBox1->SelectionColor = Color::Moccasin;
		richTextBox1->DeselectAll();
		
		do{
			idex = texto->IndexOf(palabaABuscar);
			if (idex >= 0 && (copyText[indicePivote + idex-1] == ' ' || copyText[indicePivote + idex-1] == '\t' || copyText[indicePivote + idex-1] == '\n')
				&& (copyText[indicePivote + idex + palabaABuscar->Length - 1] == ' ' || copyText[indicePivote + idex + palabaABuscar->Length - 1] == '\t' 
				|| copyText[indicePivote + idex + palabaABuscar->Length - 1] == '\n' || copyText->Length==(indicePivote+idex+palabaABuscar->Length))){
				
				richTextBox1->Select(indicePivote + idex, indicePivote + idex + palabaABuscar->Length-1);
				richTextBox1->SelectionColor = Color::Green;
				richTextBox1->Select(indicePivote + idex + palabaABuscar->Length,richTextBox1->Text->Length);
				richTextBox1->SelectionColor = Color::Moccasin;
				richTextBox1->DeselectAll();

				indicePivote = indicePivote + idex + palabaABuscar->Length-1;

				if ((idex + palabaABuscar->Length-1) <= texto->Length){
					texto = texto->Substring(idex + palabaABuscar->Length - 1);
				}
				else {
					idex = -1;
				}
			}
		} while (idex >= 0);
		
		richTextBox1->Select(copyText->Length, copyText->Length);*/
				
	}
	private: System::Void scannerParserToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		int result = scannerLexicografico(richTextBox1->Text, richTextBox2, palabrasReservadas,
			TockensPalabrasReservadas, operadores, TockensOperadores,
			MAXLINEA, MAXDIGIT, MAXID, 1, richTextBox1);
		
		Resultado^ res = gcnew Resultado(richTextBox2->Text);
		switch (result)	{
		case ERROR:
			MessageBox::Show("Ocurrio un error en el analizador lexicografico", "Algo salio mal", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		case ERROR_PARSER:
			res->ShowDialog();
			break;
		default:
			res->ShowDialog();
		}
	}
};

	
}
