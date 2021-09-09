#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main() {
	
	cout << "Cantidad de flotantes: ";
	int cant; cin >> cant;
	list<float> l;
	for(int i=0;i<cant;i++) { 
		cout << "Flotante " << i+1 << ": ";
		float aux; cin >> aux;
		l.push_back(aux);
	}
	
	for(auto it=l.begin(); it!=l.end(); ++it) { 
		cout << *it << "  ";
	}
	cout << endl << endl;
	
	
	for(auto it=++l.begin(); it!=l.end(); ++it) { 
		float suma = (*(prev(it)))+(*(it));
		float prom = suma/2.0;
		l.insert(it,prom);
	}
	
	ofstream oarchivo("lista.txt",ios::trunc);
	
	for(auto it=l.begin(); it!=l.end(); ++it) { 
		oarchivo << *it << "  ";
	}
	oarchivo << endl << endl;
	
	oarchivo.close();
	
	return 0;
}

