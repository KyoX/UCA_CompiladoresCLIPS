#include "scanner.h"

/*
Por alguna razon que desconosco, el linker de visual studio se 
apendeja con este archivo y scanner.h ... asi que toca hacer
todas las funciones como static aqui sino da problemas de doble
referencia (la cual no existe, pero bueno)
*/

/*Realiza la busqueda y retorna un tocken si lo encuentra, nullptr en caso contrario*/
static String^ busquedaBinaria(String^ lexeme){
	return lexeme;
}
static String^ removerTabs(String^ fuente){
	fuente = fuente->Replace("\t", "");
	return fuente;
}
static String^ buscarLexemas(String^ fuente){
	// separando por espacios en blanco
	// y quitando '(' y ')' ya que no son necesarias en esta etapa
	fuente = fuente->Replace("(", "");
	fuente = fuente->Replace(")", "");
	
	array<String^>^ pseudoLexeme = fuente->Split(' ');
	String^ resultado = "";
	
	for (unsigned j = 0; j < pseudoLexeme->Length; j++){
		
		// los espacios en blancos, el split los retorna como "", esos no me interesan
		if (!pseudoLexeme[j]->Equals("")){ 
			
		// si es un comentario ignoro todo lo demas... en CLIPS los comentarios inician con ; y solo hay comentarios de linea
			if (pseudoLexeme[j]->StartsWith(";")){
				return resultado;
			}

			resultado = resultado + pseudoLexeme[j] + " -> " + busquedaBinaria(pseudoLexeme[j]) + "\n";
		}
	}
	return resultado;
}

// este metodo se manda a llamar desde el IDE, es el que lo inicializa
static int scannerLexicografico(String^ codigoFuente, System::Windows::Forms::RichTextBox^  richTextBox){
	codigoFuente = removerTabs(codigoFuente);
	array<String^>^ lineas = codigoFuente->Split('\n');
	//recorro todas las lineas para encontrar los lexemas
	String^ salida = "";
	for (unsigned i = 0; i < lineas->Length; i++){
		salida = salida + buscarLexemas(lineas[i]);
	}
	richTextBox->Text = salida;
	return EXITO;
}

