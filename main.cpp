#include <iostream>
#include <string> //importo la classe string
#include <cstring> //importo le funzioni per operare con le stringhe trdizionali del c, dato che dovrò lavorare con argv
#include "Calcolatrice.h"
// librerie necessari per rand()
#include <cstdlib> 
#include <ctime>

#include <stdexcept> // libreria necessaria per poter importare le classi delle eccezioni; in questo esercizio userò la classe runtime_error, ovvero la classe di eccezioni che riguardano problemi che possono verificarsi a programma già avviato e dovuti a potenziali errori di input da parte dell'utente o situazioni simili;
using namespace std;

int main(int argc, char** argv) { //argv è un puntatore doppio, ovvero una matrice di caratteri/ array di stringhe; argc invece, indica il numero di parametri che andremo a utilizzare all'avvio da linea di comando, il nome del programma conta come primo parametro;
	//dichiaro le variabili e istanzio un'oggetto di classe Calcolatrice;
	srand(time(0));
	float a = rand() % 101;
	float b = rand() % 101;
	char comando[100] = "";
	float risultato = 0;
	bool esitoPos = true; // variabile booleana che conterrà l'esito dell'operazione; se l'input è corretto e non si effettua una divisione per zero, assumerà valore true;
	char operatore = '/';
	strcpy_s(comando, argv[1]); // inserisco nella stringa ''comando, il valore contenuto alla posizione 1 di argv, ovvero il primo parametro che segue il nome del programma;
	
	Calcolatrice casioFx("Casio", "fx-570ES"); // utilizzo il primo costruttore della classe per assegnare alle proprietà un valore. Ho preso i dati dell mia calcolatrice come esempio;
	
	//eseguo l'operazione con il contenuto della stringa "comando", che ora corrisponde al valore posizionato all'indice [1] di argv:
	
	try { // provo ad richiamare la funzione, sapendo che è possibile un eventuale errore di classe runtime_error ( in questo caso la divisione per 0);
		esitoPos= casioFx.calcola(a, b, comando, operatore, risultato);
	}
	catch (const runtime_error& errore) { // il catch proverà ad intercettare un eventuale errore di classe runtime_error, che in questo caso ho chiamato 'errore';
		cout << "input invalido a causa del seguente errore: " << errore.what() << endl; // il metodo what() mi restituirà la descrizione dell'errore che avevo inserito nel blocco throw;
		esitoPos = false;
	}

	if (esitoPos == true) { // se la chiamata è andata a buon fine e il parametro inserito è valido, allora visualizzerò il risultato.
		cout << a <<  operatore  <<" " << b << " = " << risultato << endl;
	}
	else { //altrimenti visualizzerò un messaggio di errore;
		cout << "Parametro non valido." << endl;
	}

	



	return 0;
}