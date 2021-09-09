#include <iostream>
#include <fstream>
using namespace std;

struct par{
	int entero;
	float flotante;
};

int main() {
	
	string nombre="Ejer6_1y2.dat";
	fstream archivo(nombre,ios::binary|ios::in|ios::out|ios::ate);
	int pos;
	par a;
	
	archivo.seekg(0);
	for(int i=0;i<200;i++) { 
		archivo.read(reinterpret_cast<char*>(&(a)),sizeof(par));
		cout << i+1 << ") int: " << a.entero << " | float: " << a.flotante << endl;
	}
	
	cout << "entero: "; cin >> a.entero;
	cout << "flotante: "; cin >> a.flotante;
	cout << "pos: "; cin >> pos;
	if(pos>200||pos<1){
		while(pos>200||pos<1){
			cout << "no man qué estás haciendo..." << endl;
			cout << "pos: "; cin >> pos;
		}
	}
	archivo.seekp((pos-1)*sizeof(par),ios::beg);
	archivo.write(reinterpret_cast<char*>(&a),sizeof(par));
	

	archivo.seekg(0);
	for(int i=0;i<200;i++) { 
		archivo.read(reinterpret_cast<char*>(&(a)),sizeof(par));
		cout << i+1 << ") int: " << a.entero << " | float: " << a.flotante << endl;
	}
	
	archivo.close();
	
	return 0;
}

