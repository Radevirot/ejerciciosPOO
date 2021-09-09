#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class ConfigFile{
	struct conf{
		string campo, valor;
	};
	vector<conf> v;
public:
	ConfigFile(string archivo){
		ifstream iarchivo(archivo);
		string aux;
		while(getline(iarchivo,aux)){
			if(aux[0]!='#'){ // igual es solamente este if de mierda el que lo hace
				size_t pos_igual = aux.find('=');
				if(pos_igual!=string::npos){
					conf x;
					x.campo=aux.substr(0,pos_igual); //lo jodido fue separar el string en 2 strings:
					x.valor=aux.substr(pos_igual+1,(aux.length()-x.campo.length())); // campo y valor
					v.push_back(x);												
				} else {
					cerr << "FALTO = EN ALGUNA LINEA" << endl << endl;
				}
			}
		}
		iarchivo.close();
	}
	string ObtenerValor(string fcampo){
		for(size_t i=0;i<v.size();i++) {
			if(fcampo==v[i].campo){return v[i].valor;}
		}
		return "";
	}
	void ModificarValor(string fcampo, string newvalor){
		for(size_t i=0;i<v.size();i++) {
			if(fcampo==v[i].campo){v[i].valor=newvalor;}
		}
	}
	void GuardarArchivo(string archivo){
		ofstream oarchivo(archivo,ios::trunc);
		for(size_t i=0;i<v.size();i++) {
			oarchivo << v[i].campo << "=" << v[i].valor << endl;
		}
		oarchivo.close();
	}
	
	void MetodoDePrueba(){
		for(size_t i=0;i<v.size();i++) {
			cout << v[i].campo << "=" << v[i].valor << endl;
		}
	}
	
};


int main() {
	
	
	ConfigFile test("Ejer5_4 (before).txt");
	cout << "BEFORE" << endl;
	test.MetodoDePrueba();
	cout << endl << "obtenervalor: " << test.ObtenerValor("nro_unidad") << endl << endl;
	test.ModificarValor("universidad","ninguna");
	cout << "AFTER" << endl;
	test.MetodoDePrueba();
	test.GuardarArchivo("Ejer5_4 (after).txt");
	
	return 0;
}

