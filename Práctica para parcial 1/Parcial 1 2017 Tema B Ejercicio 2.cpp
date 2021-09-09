#include <iostream>
using namespace std;

int Medir(int *inicio, int *fin){  // Innecesario, es únicamente
	return fin-inicio;			   // una prueba de sintaxis.
}

int *find_if_even(int *inicio, int *fin){
	for (int *i=inicio;i<fin;++i){			// Se desreferencia el puntero i del for usando nuevamente asterisco.
		if ((*i)%2==0){						// Si el resto de mod 2 es 0, el número es par.
			return i;						// Si eso pasa se devuelve el puntero i.
		}
	}
	return nullptr;							// Si son todos impares se devuelve el nulo.
}

int main() {
	int *p = new int[10];					// Arreglo dinámico de 10 enteros creado con puntero.
	for(int i=0;i<10;i++) { cin >> *(p+i); }	// Se ingresan los datos.
	for(int i=0;i<10;i++) { cout << *(p+i) << endl; } // Test para ver que se ingresaron bien los datos.
	int *c = find_if_even(p,p+10);			// Se asignó el resultado de la función a un nuevo puntero.
	// cout << "mide " << Medir(p,p+10) << endl; // Test de la función innecesaria.
	if (c!=nullptr){							// Si el puntero no es nulo:
		cout << "primer par: " << (*c) << endl; // Se muestra el primer par.
	} else {									// Si el puntero es nulo:
		cout << "no hay." << endl;				// No hay pares.
	}

	delete p; delete c;							// Se borran los punteros (IMPORTANTE).
	return 0;
}

