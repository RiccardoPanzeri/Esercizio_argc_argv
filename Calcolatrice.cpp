#include "Calcolatrice.h"
#include <cstring>

using namespace std;

Calcolatrice :: Calcolatrice(string nMarca, string nModello) {
	marca = nMarca;
	modello = nModello;

}

Calcolatrice::Calcolatrice(string nMarca) {
	marca = nMarca;
}

void Calcolatrice :: setMarca(string newMarca) {
	marca = newMarca;
}

void Calcolatrice::setModello(string newModello) {
	modello = newModello;
}

string Calcolatrice::getMarca() {
	return marca;
}

string Calcolatrice::getModello() {
	return modello;
}

bool Calcolatrice::calcola(float a, float b, char operazione[], char &operatore, float &risultato) {
	if (strcmp(operazione, "somma") == 0) {
		operatore = '+'; // cambio l'operatore 
		risultato = a + b;
		return true;
	}
	else if (strcmp(operazione, "sottrai") == 0) {
		operatore = '-';
		risultato = a - b;
		return true;
	}
	else if (strcmp(operazione, "moltiplica") == 0) {
		operatore = '*';
		risultato = a * b;
		return true;
	}
	else if (strcmp(operazione, "dividi") == 0) {
		operatore = '/';
		if (b == 0) { // il denominatore uguale a zero risulterebbe in un errore di classe runtime_error;
			throw runtime_error("Il denominatore è uguale a zero!\n"); // nel caso ci fosse un errore di classe runtime_error, lancerò l'eccezione;
		}
		risultato = a / b;
		return true;
	}
	else { // se il comando da prompt non corrisponde a una delle opzioni previste, verrà visualizzato un messaggio di errore;
		
		return false; // restituisco esito positivo falso;
	}
}




