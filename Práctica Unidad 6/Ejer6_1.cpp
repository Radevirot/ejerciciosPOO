#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>     
#include <fstream>  
using namespace std;

struct par{
	int entero;
	float flotante;
};


int main() {
	
	par v[200];
	string nombre="Ejer6_1y2.dat";
	
	fstream archivo(nombre,ios::binary|ios::trunc|ios::in|ios::out);
	for(int i=0;i<200;i++) {
		v[i].entero=rand()%100 +1;
		v[i].flotante=(rand()%100 +1.0)/100.0;
		archivo.write(reinterpret_cast<char*>(&(v[i])),sizeof(par));
	}
	archivo.close();
	
	ifstream iarchivo(nombre,ios::binary|ios::ate);
	int tamanio = iarchivo.tellg();
	int cant_de_pares = tamanio/sizeof(par);
	iarchivo.close();
	
	cout << "Se escribieron " << cant_de_pares << " pares." << endl;
	
	
	return 0;
}

