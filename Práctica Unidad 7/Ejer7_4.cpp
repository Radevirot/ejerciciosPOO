#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct par{
	int entero;
	float flotante;
};

struct PuntajeA{
	char n[3];
	int puntos;
};

template<typename T>
class ManejadorArchivo{
	vector<T> v_;
	string nombre_;
	fstream archivo;
public:
	ManejadorArchivo(string nombre){
		nombre_=nombre;
		archivo.open(nombre_,ios::binary|ios::in|ios::ate);
		if(!archivo.is_open()){
			cerr << "No se pudo abrir." << endl;
		} else {
			int size = archivo.tellg()/sizeof(T);
			T aux;
			archivo.seekg(0);
			for(int i=0;i<size;i++) { 
				archivo.read(reinterpret_cast<char*>(&aux),sizeof(T));
				v_.push_back(aux);
			}
		}
		archivo.close();
	}
	T ObtenerDato(int pos){return v_[pos];}
	void ModificarDato(int pos, T dato){
		v_[pos]=dato;
	}
	void GuardarArchivo(){
		archivo.open(nombre_,ios::binary|ios::out|ios::trunc);
		T aux;
		for(size_t i=0;i<v_.size();i++) { 
			aux=v_[i];
			archivo.write(reinterpret_cast<char*>(&aux),sizeof(T));
		}
		archivo.close();
	}
};




int main() {
	
//	ManejadorArchivo<par> test("siexisto.dat");
//	par dato; dato.entero= 15; dato.flotante = 4437.346;
//	test.ModificarDato(4,dato);
//	test.GuardarArchivo();
//	
//	ManejadorArchivo<par> aftertest("siexisto.dat");
//	par afterdato = aftertest.ObtenerDato(4);
//	cout << afterdato.entero << " " << afterdato.flotante << endl;
	
//	ManejadorArchivo<PuntajeA> test("tabla.dat");
//	par dato; dato.entero= 15; dato.flotante = 4437.346;
//	test.ModificarDato(4,dato);
//	test.GuardarArchivo();
	
	ManejadorArchivo<PuntajeA> test("tabla.dat");
	PuntajeA dato = test.ObtenerDato(2);
	cout << dato.puntos << " ";
	for(int i=0;i<3;i++) { 
		cout << dato.n[i];
	}
	cout << endl;
	
	
	
	
	
	
	
	
	
	
	return 0;
}

