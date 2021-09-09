#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	int v[100];
	string nombre="Ejer6_3.dat";
	
	fstream archivo(nombre,ios::binary|ios::trunc|ios::in|ios::out);	//Abro el archivo binario para escribirlo.
	for(int i=0;i<100;i++) {											//Creo el vector est�tico y lo cargo al mismo tiempo en el archivo
		v[i]=(5*i)+5;
		archivo.write(reinterpret_cast<char*>(&(v[i])),sizeof(int));
	}
	
	int x,n,pos;
	archivo.seekg(0);
	cout << "OLD" << endl << endl;
	for(int i=0;i<100;i++) {
		archivo.read(reinterpret_cast<char*>(&(x)),sizeof(int));	//Muestro el vector le�do desde el archivo para comprobar que est� bien
		cout << x << endl;
	}
	
	archivo.seekg(0);												//posiciono cursor de lectura en 0 para leer desde el inicio.
	cout << endl << "numero nuevo: "; cin >> n;						//Pido el n�mero nuevo
	pos=100;														//defaulteo posici�n a la m�s alta por si if no se da para ning�n x
	for(int i=0;i<100;i++) {
		archivo.read(reinterpret_cast<char*>(&(x)),sizeof(int));	//Consigo la posici�n en la que ir�a comparando con cada valor del vec.
		if(x>n){													//(le�do desde el archivo again)
			pos=i;
			break;
		}
	}
	archivo.close();												//Cierro el archivo binario
	
	cout << "NEW" << endl << endl;
	
	archivo.open(nombre,ios::binary|ios::trunc|ios::in|ios::out);	//Abro archivo binario para escribir desde 0 todo
	for(int i=0;i<pos;i++) { 
		archivo.write(reinterpret_cast<char*>(&(v[i])),sizeof(int)); //Reescribo el vector desde la pos. 0 hasta la pos. de n
	}
	archivo.write(reinterpret_cast<char*>(&(n)),sizeof(int));		//le enchufo el valor de n entre medio
	for(int i=pos;i<100;i++) { 
		archivo.write(reinterpret_cast<char*>(&(v[i])),sizeof(int)); //sigo con la reescritura desde donde qued� hasta el final del vec.
	}
	archivo.close();												//IMPORTANTE CERRAR EL ARCHIVO 
	
	archivo.open(nombre,ios::binary|ios::in);						//PARA ABRIRLO EN MODO DE SOLO LECTURA DESPU�S
	archivo.seekg(0);
	for(int i=0;i<101;i++) {
		archivo.read(reinterpret_cast<char*>(&(x)),sizeof(int));	//Leo el vec. nuevo desde el archivo para mostrar el valor nuevo
		cout << x << endl;
	}
	
	//este c�digo de mierda me dio un dolor de cabeza impresionante porque NO ESTABA USANDO
	//LA PUTA L�NEA 48 MAN ME QUIERO MORIR YA ME DUELE EL CEREBRO
	
	
	return 0;
}

