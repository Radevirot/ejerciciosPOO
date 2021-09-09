#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct FichaMedico{
	string nombreMedico;
	vector<long> dniPacientes;
};

class Clinica{
	vector<FichaMedico> v;
public:
	Clinica(){
		for(int i=0;i<6;i++) { 
			FichaMedico aux;
			aux.nombreMedico = "Medico " + to_string(i+1);
			v.push_back(aux);
		}
	}
	void AgregarPaciente(int nmedico,long nuevodni){
		v[nmedico].dniPacientes.push_back(nuevodni);
	}
	void Listar(){
		for(int i=0;i<6;i++) { 
			cout << v[i].nombreMedico << ":" << endl;
			for(int x: v[i].dniPacientes){
				cout << x << endl;
			}
		}
	}
	void EliminarPaciente(long dni){
		int nmedico=99;
		for(int i=0;i<6;i++) { 
			for(int x: v[i].dniPacientes){
				if(x==dni){
					nmedico=i;
					break;
				}
			}
		}
		if (nmedico==99){
			cout << "No se encontró." << endl;
		} else {
			auto it = remove(v[nmedico].dniPacientes.begin(),v[nmedico].dniPacientes.end(),dni);
			int size = it-v[nmedico].dniPacientes.begin();
			v[nmedico].dniPacientes.resize(size);
		}
		
	}
};

int main() {
	
	Clinica pija;
	pija.AgregarPaciente(0,4857463);
	pija.AgregarPaciente(0,4857463);
	pija.AgregarPaciente(0,1111111);
	pija.AgregarPaciente(0,2222222);
	pija.AgregarPaciente(0,3333333);
	pija.Listar();
	pija.EliminarPaciente(4857463);
	pija.Listar();
	
	return 0;
}

