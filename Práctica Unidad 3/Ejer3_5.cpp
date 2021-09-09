#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Monomio{
	float m_coef,m_pot;
public:
	Monomio(float pot, float coef){ m_pot=pot; m_coef = coef; }
	float Evaluar(float x){ return (m_coef*(pow(x,m_pot))); }
	void cambiarCoef(float coef){ m_coef=coef; }
	float ObtenerCoef() { return m_coef; }
	float ObtenerPot() { return m_pot; }
};

class Polinomio{
	vector<Monomio> m_v;
public:
	void AgregarMonomio(Monomio a){ m_v.push_back(a); }
	float Evaluar(float x){
		float resultado=0;
		for(size_t i=0;i<m_v.size();i++) {
			resultado += (m_v[i].ObtenerCoef()*(pow(x,m_v[i].ObtenerPot())));
		}
		return resultado;
	}
	string obtenerPolinomio(){
		string ecuacion="";
		for (size_t i=0;i<m_v.size();++i){
			
			ecuacion += to_string(m_v[i].ObtenerCoef())+"x^"+to_string(m_v[i].ObtenerPot())+"+";
		}
		return ecuacion;
	}
};

int main() {
	
	float coeficiente,potencia,eva;
	
	cout << "coeficiente: ";
	cin >> coeficiente;
	cout << "potencia: ";
	cin >> potencia;
	
	Monomio Johnny(potencia,coeficiente);
	
	cout << "potencia= " << Johnny.ObtenerPot() << "  coeficiente=" << Johnny.ObtenerCoef() << endl;
	cout << "numero para evaluar:";
	cin >> eva;
	cout << "resultado: " << Johnny.Evaluar(eva);
	cout << endl << endl << endl;
	
	//--------------------------------------------------//
	int grado;
	cout << "Ingrese el grado del polinomio: ";
	cin >> grado;
	Polinomio poli;
	
	for (int i=0;i<grado+1;++i){
		float coef;
		cout << "Ingresar coeficiente de potencia " << i << ": ";
		cin >> coef;
		Monomio a(i,coef);
		poli.AgregarMonomio(a);
	}
	
	cout << poli.obtenerPolinomio();
	float valorevaluar;
	cout << "valor para evaluar: " << endl;
	cin >> valorevaluar;
	cout << "resultado: " << poli.Evaluar(valorevaluar);
	
	return 0;
}

