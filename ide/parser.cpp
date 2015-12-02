#include "scanner.h"
#include <string.h>
#using <System.dll>
#include <list>

using namespace System::Collections::Generic;

class TDS
{
public:
	TDS();
	~TDS();
	void insert(String^ _nombre, int _tipoVariable, int _tipoRetorno, String^ _valor, int _indiceStack);
	char* getNombre();
	char* getValor();
	int getTipoRetorno();
	int getTipoVariable();
	void setNivel(int _nivel);
	void setValue(String^ valor);

private:
	char nombre[100];
	int tipoRetorno;
	int tipoVariable;			//INTEGER, STRING, BOOLEAN, ...
	int nivel;
	char valor[100];
	int indiceStack;			// posicion en la pila en la que guardara
};

TDS::TDS()
{
}

TDS::~TDS()
{
}
void StringToArray(String^ cad, char* arreglo){
	//char arreglo[100] = { 0 };
	sprintf(arreglo, "%s", cad);
	//return arreglo;
}

void TDS::insert(String^ _nombre, int _tipoVariable, int _tipoRetorno,String^ _valor, int _indiceStack){
	StringToArray(_nombre,nombre);
	tipoVariable = _tipoVariable;
	tipoRetorno = _tipoRetorno;
	StringToArray(_valor, valor);
	indiceStack = _indiceStack;
}

char* TDS::getNombre(){
	return nombre;
}

char* TDS::getValor(){
	return valor;
}

void TDS::setNivel(int _nivel){
	nivel = _nivel;
}

void TDS::setValue(String^ _valor){
	StringToArray(_valor, valor);
}

TDS* tablaDeSimbolos[MAX_SIZE_SYMBOLS];
int indexTablaSimbolos = 0;

int readFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("read")){
		if (temp[index + 2]->Equals(")"))
			return 2;
		if (temp[index + 3]->Equals(")") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}") && !temp[index + 2]->Contains("\"")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 2], STRING, NO_RETORNO, " ", -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					tablaDeSimbolos[i]->setValue(temp[index + 2]);
					existe = true;
					break;
				}
			}
			if (!existe) {
				tablaDeSimbolos[indexTablaSimbolos] = simbolo;
				indexTablaSimbolos++;
			}
			return 3;
		}
	}
	return -1;
}
int openFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("open") 
		&& Regex::IsMatch(temp[index + 2], "[\"].{0,}[\"]") && Regex::IsMatch(temp[index + 3], "[a-zA-Z][a-zA-Z0-9_]{0,}")){
		if (temp[index + 4]->Equals(")")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 3], SYMBOL, NO_RETORNO, temp[index + 2], -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					tablaDeSimbolos[i]->setValue(temp[index + 2]);
					existe = true;
					break;
				}
			}
			if (!existe) {
				tablaDeSimbolos[indexTablaSimbolos] = simbolo;
				indexTablaSimbolos++;
			}
			return 4;
		}
		if (temp[index + 5]->Equals(")") && Regex::IsMatch(temp[index + 4], "[\"]w[\"]")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 3], SYMBOL, NO_RETORNO, temp[index + 2], -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					tablaDeSimbolos[i]->setValue(temp[index + 2]);
					existe = true;
					break;
				}
			}
			if (!existe) {
				tablaDeSimbolos[indexTablaSimbolos] = simbolo;
				indexTablaSimbolos++;
			}
			return 5;
		}
	}
	//bool test = Regex::IsMatch(temp[index + 3], "[a-zA-Z][a-zA-Z0-9_]{0,}");
	return -1;
}
int closeFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("close")){
		if (temp[index + 2]->Equals(")")){
			return 2;
		}
		if (temp[index + 3]->Equals(")") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}") && !temp[index + 2]->Contains("\"")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 2], SYMBOL, NO_RETORNO, temp[index + 2], -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					existe = true;
					break;
				}
			}
			if (!existe) {
				// error en tiempo de ejecucion... la variable no existe
				return -1;
			}
			return 3;
		}
	}
	return -1;
}
int printOutFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("printout") && Regex::IsMatch(temp[index + 2], "[a-zA-Z\"][a-zA-Z0-9_\"]{0,}")){
		if (temp[index + 3]->Equals(")")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 3], SYMBOL, NO_RETORNO, temp[index + 4], -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					existe = true;
					break;
				}
			}
			if (!existe) {
				// error en tiempo de ejecucion... la variable no existe
				return -1;
			}
			return 3;
		}
		if (temp[index + 5]->Equals(")") && Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9_\"]{0,}") && temp[index + 4]->Equals("crlf")){
			TDS* simbolo = new TDS();
			bool existe = false;
			simbolo->insert(temp[index + 3], SYMBOL, NO_RETORNO, temp[index + 4], -1);
			for (int i = 0; i < indexTablaSimbolos; i++){
				if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
					existe = true;
					break;
				}
			}
			if (!existe) {
				// error en tiempo de ejecucion... la variable no existe
				return -1;
			}
			return 5;
		}
	}
	return -1;
}
int single_wildcard(array<String^>^ temp, int index){
	if (temp[index]->Equals("?"))
		return index;
	return -1;
}
int breakFucntion(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("break") && temp[index + 2]->Equals(")"))
		return 2;
	return -1;
}
int returnFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("return")){
		if (temp[index + 2]->Equals(")"))
			return 2;
		if (temp[index + 3]->Equals(")") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9_\"]{0,}"))
			return 3;
	}
		
	return -1;
}
int single_slot_definition(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("slot") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}") && temp[index + 3]->Equals(")"))
		return 3;

	return -1;
}
int propiedad_valor(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && Regex::IsMatch(temp[index + 1], "[a-zA-Z][a-zA-Z0-9_]{0,}") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int retractFucntion(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("retract") && Regex::IsMatch(temp[index + 2], "[0-9]{1,}") && temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int assertFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("assert") && propiedad_valor(temp, index + 2) && temp[index + 6]->Equals(")")){
		TDS* simbolo = new TDS();
		bool existe = false;
		simbolo->insert(temp[index + 3], FACT, NO_RETORNO, temp[index + 4], -1);
		for (int i = 0; i < indexTablaSimbolos; i++){
			if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre())==0){
				tablaDeSimbolos[i]->setValue(temp[index + 4]);
				existe = true;
				break;
			}
		}
		if (!existe) {
			tablaDeSimbolos[indexTablaSimbolos] = simbolo;
			indexTablaSimbolos++;
		}
		return 6;
	}
		
	return -1;
}
int or_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("or") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}")
		&& Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}") && temp[index + 4]->Equals(")"))
		return 4;
	return -1;
}
int and_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("and") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}")
		&& Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}") && temp[index + 4]->Equals(")"))
		return 4;
	return -1;
}
int exists_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("exists") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}")
		&& temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int not_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("not") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}")
		&& temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int logical_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("logical") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}")
		&& temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int mathFunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(")){
		if (temp[index + 1]->Equals("+") || temp[index + 1]->Equals("-") || temp[index + 1]->Equals("*") || temp[index + 1]->Equals("/") || temp[index + 1]->Equals("div") || temp[index + 1]->Equals("max") || temp[index + 1]->Equals("min")){
			if ((Regex::IsMatch(temp[index + 2], "[0-9]{1,}") || Regex::IsMatch(temp[index + 2], "[0-9]{1,}\.[0-9]{1,}")) && (Regex::IsMatch(temp[index + 3], "[0-9]{1,}") || Regex::IsMatch(temp[index + 3], "[0-9]{1,}\.[0-9]{1,}"))){
				if (temp[index + 4]->Equals(")")){
					return 4;
				}
			}
		}
		if (temp[index + 1]->Equals("abs") || temp[index + 1]->Equals("float") || temp[index + 1]->Equals("integer")){
			if (Regex::IsMatch(temp[index + 2], "[0-9]{1,}") || Regex::IsMatch(temp[index + 2], "[0-9]{1,}\.[0-9]{1,}")){
				if (temp[index + 3]->Equals(")")){
					return 3;
				}
			}
		}
	}

	return -1;
}
int predicate_function(array<String^>^ temp, int index){
	if (temp[index]->Equals("(")){
		if (temp[index + 1]->Equals("not") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}") && temp[index+3]->Equals(")")){
			return 3;
		}
		if (temp[index + 1]->Equals("numberp") || temp[index + 1]->Equals("floatp") || temp[index + 1]->Equals("integerp") 
			|| temp[index + 1]->Equals("stringp") || temp[index + 1]->Equals("and") || temp[index + 1]->Equals("or") 
			|| temp[index + 1]->Equals("eq") || temp[index + 1]->Equals("neq")){
			if (Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && temp[index + 4]->Equals(")") 
				&& temp[index + 4]->Equals(")")){
				return 4;
			}
		}
		if (temp[index + 1]->Equals("=") || temp[index + 1]->Equals("<>") || temp[index + 1]->Equals(">") || temp[index + 1]->Equals("<") || temp[index + 1]->Equals(">=") || temp[index + 1]->Equals("<=")){
			if (Regex::IsMatch(temp[index + 2], "[0-9]{1,}") && Regex::IsMatch(temp[index + 3], "[0-9]{1,}") && temp[index + 4]->Equals(")")
				&& temp[index + 4]->Equals(")")){
				return 4;
			}
		}
	}
	return -1;
}
int createA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("create$") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && temp[index + 4]->Equals(")")){
		return 4;
	}
	return -1;
}
int specifying(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("nth$") && Regex::IsMatch(temp[index + 2], "[0-9]{1,}") && createA(temp, index + 3) > 0 && temp[index + 8]->Equals(")")){
		return 8;
	}
	return -1;
}
int memberA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("member$") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && createA(temp, index + 3) > 0 && temp[index + 8]->Equals(")"))
		return 8;
	return -1;
}
int explodeA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("explode$") && Regex::IsMatch(temp[index + 2], "[\"].{0,}[\"]") && temp[index + 3]->Equals(")"))
		return 3;
	return -1;
}
int implodeA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("implode$") && createA(temp, index + 2) > 0 && temp[index + 7]->Equals(")"))
		return 7;
	return -1;
}
int deleteA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("delete$") && createA(temp, index + 2) > 0 && Regex::IsMatch(temp[index + 7], "[0-9]{1,}") && Regex::IsMatch(temp[index + 8], "[0-9]{1,}") && temp[index + 9]->Equals(")"))
		return 9;
	return -1;
}
int replaceA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("replace$") && createA(temp, index + 2) > 0 && Regex::IsMatch(temp[index + 7], "[0-9]{1,}") && Regex::IsMatch(temp[index + 8], "[0-9]{1,}") && Regex::IsMatch(temp[index + 9], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && temp[index + 10]->Equals(")")){
		return 10;
	}
	return -1;
}
int insertA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("insert$") && createA(temp, index + 2) > 0 && Regex::IsMatch(temp[index + 7], "[0-9]{1,}")  && Regex::IsMatch(temp[index + 8], "[a-zA-Z0-9\"][a-zA-Z0-9_\"]{0,}") && temp[index + 9]->Equals(")")){
		return 9;
	}
	return -1;
}
int firstA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("first$") && createA(temp, index + 2) > 0 && temp[index + 7]->Equals(")")){
		return 7;
	}
	return -1;
}
int restA(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("rest$") && createA(temp, index + 2) > 0 && temp[index + 7]->Equals(")")){
		return 7;
	}
	return -1;
}
int functionCall(array<String^>^ temp, int index){
	int index2 = readFunction(temp, index);
	if (index2 < 0) {
		index2 = openFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = closeFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = printOutFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = breakFucntion(temp, index);
	}
	if (index2 < 0) {
		index2 = returnFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = assertFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = or_ce(temp, index);
	}
	if (index2 < 0) {
		index2 = and_ce(temp, index);
	}
	if (index2 < 0) {
		index2 = exists_ce(temp, index);
	}
	if (index2 < 0) {
		index2 = not_ce(temp, index);
	}
	if (index2 < 0) {
		index2 = logical_ce(temp, index);
	}
	if (index2 < 0) {
		index2 = mathFunction(temp, index);
	}
	if (index2 < 0) {
		index2 = predicate_function(temp, index);
	}
	if (index2 < 0) {
		index2 = retractFucntion(temp, index);
	}
	if (index2 < 0) {
		index2 = createA(temp, index);
	}
	if (index2 < 0) {
		index2 = specifying(temp, index);
	}
	if (index2 < 0) {
		index2 = memberA(temp, index);
	}
	if (index2 < 0) {
		index2 = explodeA(temp, index);
	}
	if (index2 < 0) {
		index2 = implodeA(temp, index);
	}
	if (index2 < 0) {
		index2 = deleteA(temp, index);
	}
	if (index2 < 0) {
		index2 = replaceA(temp, index);
	}
	if (index2 < 0) {
		index2 = insertA(temp, index);
	}
	if (index2 < 0) {
		index2 = firstA(temp, index);
	}
	if (index2 < 0) {
		index2 = restA(temp, index);
	}
	if (index2 < 0) {
		if (temp[index]->Equals("(") && Regex::IsMatch(temp[index + 1], "[a-zA-Z][a-zA-Z0-9_]{0,}") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}")
			&& Regex::IsMatch(temp[index + 3], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}") && temp[index + 4]->Equals(")"))
			return 4;
	}
	else{
		return index2;
	}
	return -1;
}

int test_ce(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("test") && functionCall(temp, index + 2) > 0 && temp[index + 7]->Equals(")"))
		return 7;
	return -1;
}
int default_statement(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("default") && functionCall(temp, index + 2) > 0 && temp[index + 7]->Equals(")")){
		return 7;
	}
	return -1;
}
int case_statement(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && Regex::IsMatch(temp[index + 1], "[a-zA-Z0-9][a-zA-Z0-9_\"]{0,}") && temp[index + 2]->Equals("then") && functionCall(temp, index + 3) > 0 && temp[index + 8]->Equals(")")){
		return 8;
	}
	return -1;

}
int switch_function(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("switch") && test_ce(temp, index + 2) > 0 && case_statement(temp, index + 10) > 0 && default_statement(temp, index + 19) > 0 && temp[index + 27]->Equals(")")){
		return 27;
	}
	return -1;
}
int range_spec(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && Regex::IsMatch(temp[index + 1], "[a-zA-Z0-9][a-zA-Z0-9_]{0,}") && Regex::IsMatch(temp[index + 2], "[0-9]{1,}") && Regex::IsMatch(temp[index + 3], "[0-9]{1,}") && temp[index + 4]->Equals(")")){
		return 4;
	}
	if (Regex::IsMatch(temp[index], "[0-9]{1,}")){
		return 0;
	}
	return -1;
}
int loop_for_count(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("loop-for-count")){
		int range = range_spec(temp, index + 2);
		if (range < 0){
			return -1;
		}
		if (temp[index + 4 + range]->Equals(")") && functionCall(temp, index + 3 + range)>0)
			return (4 + range);
	}
	return -1;
}

int global_assignment(array<String^>^ temp, int index){
	
	if (Regex::IsMatch(temp[index], "[?][\*][a-zA-Z][a-zA-Z0-9_]{0,}[\*]") && temp[index + 1]->Equals("=") && Regex::IsMatch(temp[index + 2], "[a-zA-Z0-9_\"]{0,}")){
		TDS* simbolo = new TDS();
		bool existe = false;
		simbolo->insert(temp[index], GLOBAL, NO_RETORNO, temp[index + 2], -1);
		for (int i = 0; i < indexTablaSimbolos; i++){
			if (strcmp(simbolo->getNombre(), tablaDeSimbolos[i]->getNombre()) == 0){
				tablaDeSimbolos[i]->setValue(temp[index + 4]);
				existe = true;
				break;
			}
		}
		if (!existe) {
			tablaDeSimbolos[indexTablaSimbolos] = simbolo;
			indexTablaSimbolos++;
		}
		return 2;
	}
	return -1;
}
int defglobal(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("defglobal")
		&& global_assignment(temp, index + 2) && temp[index + 5]->Equals(")")){
		return 5;
	}
	return -1;
}
int defTemplate(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("deftemplate") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}")
		&& single_slot_definition(temp, index + 3)>0 && temp[index + 7]->Equals(")")){
		return 7;
	}
	return -1;
}
int deffacts(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("deffacts") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}") && functionCall(temp, index + 3) > 0 && temp[index + 8]->Equals(")")){
		return 8;
	}
		
	return -1;
}
int deffunction(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("deffunction") && Regex::IsMatch(temp[index + 2], "[a-zA-Z][a-zA-Z0-9_]{0,}") && temp[index + 3]->Equals("(")
		&& (Regex::IsMatch(temp[index + 4], "[a-zA-Z][a-zA-Z0-9_]{0,}") || Regex::IsMatch(temp[index + 4], "[?][\*][a-zA-Z][a-zA-Z0-9_]{0,}[\*]")) && temp[index + 5]->Equals(")")){
		int f = functionCall(temp, index + 6);
		if (f < 0){
			return -1;
		}
		if (temp[index + f + 7]->Equals(")")){
			return (f + 7);
		}
	}
	return -1;
}
int conditional_element(array<String^>^ temp, int index){
	int index2 = not_ce(temp, index);
	if (index2 < 0){
		index2 = and_ce(temp, index);
	}
	if (index2 < 0){
		index2 = or_ce(temp, index);
	}
	if (index2 < 0){
		index2 = logical_ce(temp, index);
	}
	if (index2 < 0){
		index2 = test_ce(temp, index);
	}
	if (index2 < 0){
		index2 = exists_ce(temp, index);
	}
	if (index2 < 0){
		return -1;
	}
	else{
		return index2;
	}
}
int deffrule(array<String^>^ temp, int index){
	//if (temp[index]->Equals("(") && temp[index + 1]->Equals("defrule") && Regex::IsMatch(temp[index + 4], "[a-zA-Z][a-zA-Z0-9_]{0,}"))
	return -1;
}

int while_function(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("while")){
		int index2 = conditional_element(temp, index + 2);
		if (index2 < 0){
			return -1;
		}
		int index3 = functionCall(temp, index + 3 + index2);
		if (index3<0){
			return -1;
		}
		else{
			return index3 + 1;
		}
	}
	return -1;
}
int if_function(array<String^>^ temp, int index){
	if (temp[index]->Equals("(") && temp[index + 1]->Equals("if")){
		int index2 = conditional_element(temp, index + 1);
		if (index2 < 0){
			return -1;
		}
		int index3 = functionCall(temp, index + 3 + index2);
		if (temp[index + 2 + index2]->Equals("then") && index3 > 0){
			return index3 + 1;
		}
	}
	return -1;
}

String^ generarCodigoP(array<String^>^ codigo, String^ FUENTE_DIR, String^ NOMBRE_FILE){
	String^ nombre;
	
	//sentencias de almacenado de las variables
	for (int i = 0; i < indexTablaSimbolos; i++){
		nombre = gcnew String(tablaDeSimbolos[i]->getNombre());
	}
	return "algo";
}

String^ perteneceSemantico(List<String^>^ tockensIndividuales, System::Windows::Forms::RichTextBox^  richTextBox, array<String^>^ codigoSeparado, String^ FUENTE_DIR, String^ NOMBRE_FILE){
	array<String^>^ temp = tockensIndividuales->ToArray();
	String^ salida = "\n\n***   Estadisticas globales   ***\n";

	bool error = false;
	int index = 0, acumulando=0;
	unsigned cant = temp->Length;
	while (index < cant){
		int index = -1;
		if (index < 0) {
			index = defglobal(temp, acumulando);
		}
		if (index < 0) {
			index = defTemplate(temp, acumulando);
		}
		if (index < 0) {
			index = deffacts(temp, acumulando);
		}
		if (index < 0) {
			index = switch_function(temp, acumulando);
		}
		if (index < 0){
			index = functionCall(temp, acumulando);
		}
		if (index < 0){
			index = loop_for_count(temp, acumulando);
		}
		if (index < 0){
			index = deffunction(temp, acumulando);
		}
		if (index < 0){
			index = while_function(temp, acumulando);
		}
		/*if (index < 0){
			index = deffrule(temp, acumulando);
		}*/


		if (index < 0){ // encontro error, sale
			error = true;
			int indice = richTextBox->Text->IndexOf(temp[acumulando]);
			String^ texto = richTextBox->Text->Substring(indice);
			int indice2 = texto->IndexOf("\n");
			if (indice2 < 0){
				richTextBox->SelectAll();
			}
			else{
				texto = texto->Substring(0, indice2);
				richTextBox->Select(indice, texto->Length);
			}
			
			break;//llega a su fin
		}
		if (index > 0){	//encontro la funcion
			index = index + acumulando + 1;
		}

		
		if (index == cant){
			break;//llega a su fin
		}
		acumulando = index;
	}
	
	if (!error){
		salida = salida + "***  No se detectaron errores ***";
		salida = salida + "\n Generando el codigo P";
		generarCodigoP(codigoSeparado, FUENTE_DIR, NOMBRE_FILE);
	}
	else{
		salida = salida + "Errores detectados\n*****No se genero el ejecutable*****";
	}
	return salida;
}

String^ parsearCodigo(String^ codigoFuente, array<String^>^ codigoSeparado, System::Windows::Forms::RichTextBox^  richTextBox, array <String^>^ codigoP, String^ FUENTE_DIR, String^ NOMBRE_FILE){
	int cantidadParentesisApertura = codigoFuente->Split('(')->Length;
	int cantidadParentesisCierre = codigoFuente->Split(')')->Length;
	
	// revisa que para cada apertura haya un cierre, si no es asi, desde aqui estamos mal
	if (cantidadParentesisApertura != cantidadParentesisCierre){
		return "Error: la cantidad de parentesis de apertura no corresponde con la cantidad de parentesis de cierre";
	}

	
	// separo con espacios 
	array<String^>^ temp;
	List<String^>^ tockensIndividuales = gcnew List<String^>();

	//codigoP a partir de codigoSeparado

	for (int i = 0; i < codigoSeparado->Length; i++){
		codigoSeparado[i] = codigoSeparado[i]->Replace("(", " ( ")->Replace(")", " ) ")->Replace("=", " = ");
		codigoSeparado[i] = codigoSeparado[i]->Replace("+", " + ")->Replace("-", " - ")->Replace("*", " * ")->Replace("/", " / ");
		temp = codigoSeparado[i]->Split(' ');

		for each (String^ lexVar in temp)
		{
			if (!lexVar->Equals("")){
				tockensIndividuales->Add(lexVar);
			}
		}

	}

	
	
	return perteneceSemantico(tockensIndividuales, richTextBox, codigoSeparado, FUENTE_DIR, NOMBRE_FILE);
}
