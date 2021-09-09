#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumno{
	string nombre;
	int n1, n2;
};

bool Reemplazar(string nombre,int n1, int n2){
	
	ifstream iarchivo("Ejer5_2 (lista).txt");
	if (!iarchivo.is_open()){
		cerr << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return false;
	}
	vector<string> v;
	string x;
	while (getline(iarchivo,x)){
		v.push_back(x);
	}
	for(size_t i=0;i<v.size();i+=2){
		if(v[i]==nombre){
			v[i+1] = to_string(n1) + " " + to_string(n2);
		}
	}
	iarchivo.close();
	ofstream oarchivo("Ejer5_2 (lista).txt",ios::trunc);
	if (!oarchivo.is_open()){
		cerr << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return false;
	}
	for(size_t i=0;i<v.size();++i){
		oarchivo << v[i] << endl;
	}
	oarchivo.close();
	return true;
}

void Promedios(){
	
	ifstream iarchivo("Ejer5_2 (lista).txt");
	vector<Alumno> v;
	Alumno x;
	while (getline(iarchivo,x.nombre)){
		iarchivo >> x.n1 >> x.n2;
		iarchivo.ignore();
		v.push_back(x);
	}
	iarchivo.close();
	ofstream oarchivo("Ejer5_2 (Promedios).txt",ios::trunc);
	for(size_t i=0;i<v.size();i++) {
		float prom = (v[i].n1+v[i].n2)/2;
		oarchivo<<setw(15)<<left<<v[i].nombre<<setw(6)<<setprecision(2)<<fixed<<prom;
		if (prom>=70){
			oarchivo<<setw(15)<<right<<"promocion"<<endl;
		} else if (prom>=40){
			oarchivo<<setw(15)<<right<<"regular"<<endl;
		} else {
			oarchivo<<setw(15)<<right<<"libre"<<endl;
		}
	}
	
}
	
	
int main() {
	
	if (Reemplazar("Lopez Javier",50,60)){
		cout << "Se reemplazó correctamente." << endl;
	} else {
		cout << "Hubieron problemitas..." << endl;
	}
	
	if (Reemplazar("Garcia Ana",20,10)){
		cout << "Se reemplazó correctamente." << endl;
	} else {
		cout << "Hubieron problemitas..." << endl;
	}
	
	if (Reemplazar("Farias Daniel",70,80)){
		cout << "Se reemplazó correctamente." << endl;
	} else {
		cout << "Hubieron problemitas..." << endl;
	}
	
	Promedios();
	
	return 0;
}

