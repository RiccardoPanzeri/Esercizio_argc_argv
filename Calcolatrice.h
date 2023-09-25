#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
class Calcolatrice
{
private:
	string marca;
	string modello;
	
public:
	//metodi costruttori
	Calcolatrice(string nMarca, string nModello);
	Calcolatrice(string nMarca); // dimostro il principio della sovrapposizione introdotto con la programmazione ad oggetti: in c++ è possibile avere più funzioni con nome uguale;
	//setter
	void setMarca(string newMarca);
	void setModello(string newModello);
	//getter
	string getMarca();
	string getModello();
	//metodi
	bool calcola(float a, float b, char operazione[], char &operatore, float &risultato); // l'operatore passato per riferimento cambierà in base all'operazione selezionata dall'utente; 
	
	
	

};

