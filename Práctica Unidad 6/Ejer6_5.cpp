#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

struct PuntajeA{
	char n[3];
	int puntos;
};

struct PuntajeM{
	string n;
	int puntos;
};

bool mayorpuntaje(PuntajeM a, PuntajeM b){
	return a.puntos>b.puntos;
}

class Tabla{
	int cant_pos_;
	vector<PuntajeM> v_;
public:
	Tabla(int cant_pos){
		cant_pos_=cant_pos;
		PuntajeM a;
		a.n="asd";
		a.puntos=0;
		vector<PuntajeM> v(cant_pos_,a);
		v_=v;
	}
	void CargarDeArchivo(string nombre){
		fstream archivo(nombre,ios::binary|ios::ate|ios::in);
		if(!archivo.is_open()){
			cout << "No se pudo cargar desde el archivo porque no existe ninguno con ese nombre." << endl;
		} else{
			int arch_cant_pos=archivo.tellg()/sizeof(PuntajeA);
			if(arch_cant_pos!=cant_pos_){
				cout << "No se pudo cargar desde el archivo porque la cant. de" << endl
					<< "puntajes máxima difiere de la cargada." << endl;
			} else{
				archivo.seekg(0);
				PuntajeM x;
				PuntajeA y;
				for(int i=0;i<cant_pos_;i++) { 
					archivo.read(reinterpret_cast<char*>(&y),sizeof(PuntajeA));
					x.puntos=y.puntos;
					
					for(int j=0;j<3;j++) { 
						x.n+=y.n[j];
					}	
					v_[i]=x;
					x.n="";
				}
			}
		}
		
	}
	void GuardarEnArchivo(string nombre){
		fstream archivo(nombre,ios::binary|ios::out|ios::trunc);
		PuntajeM x;
		PuntajeA y;
		for(int i=0;i<cant_pos_;i++) { 
			x=v_[i];
			y.puntos=x.puntos;
			for(size_t j=0;j<sizeof(y.n);j++) { 
				y.n[j]=x.n[j];
			}
			archivo.write(reinterpret_cast<char*>(&y),sizeof(PuntajeA));
		}
	}
	PuntajeM ObtenerPuntaje(int pos){
		if(pos<0||pos>cant_pos_){
			cerr << "no." << endl;
			PuntajeM a;
			a.n="";
			a.puntos=0;
			return a;
		}
		return v_[pos];
	}
	void CargarPuntaje(PuntajeM a){
		v_.push_back(a);
		sort(v_.begin(),v_.end(),mayorpuntaje);
		v_.resize(cant_pos_-1);
	}
};

int main() {
	
	int pos;
	cout << "¿Cuántas posiciones tiene la tabla?: ";
	cin >> pos;
	
	Tabla ta(pos);
//	for(int i=0;i<pos;i++) { 
//		PuntajeM test;
//		cout << "Nombre: "; cin >> test.n;
//		cout << "Puntos: "; cin >> test.puntos;
//		ta.CargarPuntaje(test);
//	}
//	
//
//	ta.GuardarEnArchivo("tabla.dat");
	
	
	ta.CargarDeArchivo("tabla.dat");
	for(int i=0;i<pos;i++) { 
		PuntajeM test = ta.ObtenerPuntaje(i);
		cout << test.n << " " << test.puntos << endl;
	}
	
	
	
	return 0;
}

