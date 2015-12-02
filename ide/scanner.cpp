#include <math.h>
//#include "scanner.h"
#include "parser.cpp"
#using <System.dll>
/*
Por alguna razon que desconosco, el linker de visual studio se 
apendeja con este archivo y scanner.h ... asi que toca hacer
todas las funciones como static aqui sino da problemas de doble
referencia (la cual no existe, pero bueno)

actualizacion: poniendo la opcion /FORCE en el linker se quita el problema aparentemente
*/

String^ busquedaBinariaAux(String^ lexeme, array <String^>^ palabrasReservadas, array <String^>^ TockensPalabrasReservadas){
	int liminiteInf = 0,aux;
	int limiteSup = palabrasReservadas->Length;
	int indice=liminiteInf;
	float div;
	
	div = (limiteSup - liminiteInf) / 2;
	indice = liminiteInf + ceil(div);

	while (liminiteInf < limiteSup && indice<limiteSup && indice>liminiteInf){
		aux = lexeme->CompareTo(palabrasReservadas[indice]);
		if (aux == 0){
			return TockensPalabrasReservadas[indice];
		}

		if (aux > 0)
			liminiteInf = indice;
		else
			limiteSup = indice;

		div = (limiteSup - liminiteInf) / 2;
		indice = liminiteInf + ceil(div);
	}


	aux = lexeme->CompareTo(palabrasReservadas[0]);
	if (aux == 0){
		return TockensPalabrasReservadas[0];
	}
	return nullptr;
	
}

/*Realiza la busqueda y retorna un tocken si lo encuentra, nullptr en caso contrario*/
String^ busquedaBinaria(String^ lexeme, array <String^>^ palabrasReservadas, array <String^>^ TockensPalabrasReservadas,
								array <String^>^  operadores, array <String^>^  TockensOperadores, unsigned MAXDIGIT, unsigned MAXID, unsigned MAXLINEA){
	String^ tocken = nullptr;
	
	tocken = busquedaBinariaAux(lexeme,palabrasReservadas,TockensPalabrasReservadas);
	
	// revisa si es operador
	if (tocken == nullptr){
		for (int i = 0; i < operadores->Length; i++){
			if (lexeme->CompareTo(operadores[i]) == 0){
				tocken = TockensOperadores[i];
			}
		}
	}
	
	//revisa si es string
	if (tocken == nullptr && Regex::IsMatch(lexeme, "[\"].{0,}[\"]")){
		tocken = "stringTock";
	}

	// verificando que sea numero real
	if (tocken == nullptr && Regex::IsMatch(lexeme, "[0-9]{1,}\.[0-9]{1,}") && lexeme->Length<=MAXDIGIT){
		tocken = "realTock";
	}
	
	// revisa si es entero
	if (tocken == nullptr && Regex::IsMatch(lexeme, "[0-9]{1," + MAXDIGIT + "}")){
		tocken = "enteroTock";
	}

	//revisa si es identificador
	if (tocken == nullptr && Regex::IsMatch(lexeme, "[a-zA-Z][a-zA-Z0-9_]{0,}")){
		tocken = "identTock";
	}

	// si no es ninguna de las anteriores
	if (tocken == nullptr){
		tocken = "nulo";
	}
	

	return tocken;
}
String^ removerTabs(String^ fuente){
	fuente = fuente->Replace("\t", "");
	return fuente;
}
String^ separarOperadores(String^ fuente, array <String^>^  operadores){
	for (int i = 0; i < operadores->Length; i++){
		fuente = fuente->Replace(operadores[i], " " + operadores[i] + " ");
	}

	return fuente;
}

String^ buscarLexemas(String^ fuente, array <String^>^ palabrasReservadas, array <String^>^ TockensPalabrasReservadas,
							array <String^>^  operadores, array <String^>^  TockensOperadores, unsigned MAXDIGIT, unsigned MAXID, unsigned MAXLINEA,unsigned nivel){
	// separando por espacios en blanco
	if (fuente->Length > MAXLINEA){
		return "nulo";
	}

	fuente = separarOperadores(fuente,operadores);

	array<String^>^ pseudoLexeme = fuente->Split(' ');
	String^ resultado = "";
	
	for (unsigned j = 0; j < pseudoLexeme->Length; j++){
		
		// los espacios en blancos, el split los retorna como "", esos no me interesan
		if (!pseudoLexeme[j]->Equals("")){ 
			
		// si es un comentario ignoro todo lo demas... en CLIPS los comentarios inician con ; y solo hay comentarios de linea, ejemplo:
		// ladoIzquierdo ; ladoDerecho
		// solo toma en cuenta el ladoIzquierdo, lo demas lo ignora y pasa a la siguiente linea
			if (pseudoLexeme[j]->StartsWith(";")){
				return resultado;
			}

			resultado = resultado + pseudoLexeme[j] + "\t -> \t" + busquedaBinaria(pseudoLexeme[j], palabrasReservadas, 
																TockensPalabrasReservadas, operadores, TockensOperadores, MAXDIGIT, MAXID,MAXLINEA) + "\n";
		}
	}
	return resultado;
}

// este metodo se manda a llamar desde el IDE, es el que lo inicializa
int scannerLexicografico(String^ codigoFuente, System::Windows::Forms::RichTextBox^  richTextBox, array <String^>^ _palabrasReservadas,
								array <String^>^ _TockensPalabrasReservadas, array <String^>^ _operadores, array <String^>^ _TockensOperadores,
								unsigned MAXLINEA, unsigned MAXDIGIT, unsigned MAXID, unsigned nivel, System::Windows::Forms::RichTextBox^  richTextBoxOriginal,
								array <String^>^codigoP, String^ FUENTE_DIR, String^ NOMBRE_FILE){

	try{
		array <String^>^ palabrasReservadas;
		array <String^>^ TockensPalabrasReservadas;
		array <String^>^ operadores;
		array <String^>^ TockensOperadores;

		palabrasReservadas = _palabrasReservadas;
		TockensPalabrasReservadas = _TockensPalabrasReservadas;
		operadores = _operadores;
		TockensOperadores = _TockensOperadores;

		codigoFuente = removerTabs(codigoFuente);
		array<String^>^ lineas = codigoFuente->Split('\n');
		//recorro todas las lineas para encontrar los lexemas
		String^ salida = "";
		for (unsigned i = 0; i < lineas->Length; i++){
			
			//quitando los comentarios
			if (lineas[i]->Contains(";")){
				unsigned pos = lineas[i]->IndexOf(";");
				lineas[i] = lineas[i]->Substring(0, pos);
			}

			salida = salida + buscarLexemas(lineas[i], palabrasReservadas, TockensPalabrasReservadas, operadores, TockensOperadores, MAXDIGIT, MAXID, MAXLINEA, nivel);
		}
		if (nivel == 0){
			richTextBox->Text = salida;
			return EXITO;
		}else{
			try{
				salida = parsearCodigo(codigoFuente, lineas, richTextBoxOriginal, codigoP, FUENTE_DIR, NOMBRE_FILE);
				richTextBox->Text = salida;
			}
			catch (Exception^ e){
				String^ salida = "\n\n***   Estadisticas globales   ***\n";
				salida = salida + "Errores detectados\n*****No se genero el ejecutable*****";
				richTextBox->Text = salida;
				return ERROR_PARSER;
			}

		}
	}
	catch (Exception^ e){
		return ERROR;
	}
}

