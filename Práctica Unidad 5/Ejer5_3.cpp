#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 
using namespace std;

vector<string> ObtenerVector(){
	ifstream iarchivo("Ejer5_3 (inscriptos).txt");
	if (!iarchivo.is_open()){
		cerr << "NO SE PUDO ABRIR EL ARCHIVO." << endl;
		vector<string> vacio;
		return vacio;
	}
	
	vector<string> v; string x;
	while(getline(iarchivo,x)){v.push_back(x);}
	return v;
}

int main() {
	
	int cant_alumnos = v.size();
	int comisiones, alumnos_por_comision;
	bool sobra_uno=false;
	
	if (cant_alumnos<=30){
		comisiones=1;
		alumnos_por_comision=cant_alumnos;
	} else if (cant_alumnos%30==0) {
		comisiones=cant_alumnos/30;
		alumnos_por_comision=30;
	} else {
		comisiones=(cant_alumnos/30)+1;
		alumnos_por_comision=(cant_alumnos/comisiones);
		if(cant_alumnos%comisiones!=0){
			sobra_uno=true;
		}
	}
	
	for(int i=1;i<comisiones+1;i++) { 
		string s;
		s = "Ejer5_3 (comision" + to_string(i) + ").txt";
		ofstream oarchivo(s,ios::trunc);
		for(int j=((i-1)*alumnos_por_comision);j<(i*alumnos_por_comision);++j){oarchivo << v[j] << endl;}
	}
	
	if(sobra_uno){
		ofstream oarchivo("Ejer5_3 (comision1).txt",ios::app);
		oarchivo << v[cant_alumnos-1] << endl;
	}
	
	return 0;
}

