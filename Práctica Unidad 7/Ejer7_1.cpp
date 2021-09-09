#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template<typename T>
T Mayor(T a,T b){
	if(a>b){
		return a;
	} else {
		return b;
	}
}
template<typename T>
T Mayor(vector<T> v){
	T may = v[0];
	for(size_t i=0;i<v.size();i++) { 
		if(v[i]>may){
			may=v[i];
		}
	}
	return may;
}
struct Persona{
	string nombre, apellido;
	int dni;
};
bool operator>(Persona a, Persona b){
	return a.apellido>b.apellido;
}

int main() {
	
	string a="hola",b="asd",c=Mayor(a,b);
	cout << c << endl;
	int x=20,y=30,d=Mayor(x,y);
	cout << d << endl;
	float z=1.5,w=1.2,j=Mayor(z,w);
	cout << j << endl << endl;
	
	vector<int> v(5);
	for(int i=0;i<5;i++) { 
		v[i] = rand() % 100 + 1;
		cout << v[i] << "  ";
	}
	cout << endl;
	int may=Mayor(v);
	cout << "mayor: " << may << endl << endl;
	
	vector<Persona> persv;
	
	for(int i=0;i<3;i++) { 
		Persona x;
		cout << "nom ape dni: " << endl;
		cin >> x.nombre >> x.apellido >> x.dni;
		persv.push_back(x);
	}
	
	Persona persmay = Mayor(persv);
	cout << persmay.apellido << " " << persmay.nombre << " | " << persmay.dni << endl;
	return 0;
}

