#include <iostream>
using namespace std;

class Fraccion{
	int m_numerador, m_denominador;
public:
	Fraccion(int num, int den){ m_numerador=num; m_denominador=den; }
	float ConvertirAFloat() {return static_cast<float>(m_numerador) / static_cast<float>(m_denominador);}
	void CambiarNumerador(int num) {m_numerador=num;}
	void CambiarDenominador(int den ) {m_denominador=den;}
	int ObtenerNumerador() {return m_numerador;}
	int ObtenerDenominador() {return m_denominador;}
};

class NumeroMixto{
	int m_entero; Fraccion impropia;
public:
	NumeroMixto(int entero, int num, int den): impropia(num,den) {m_entero=entero;}
	string ObtenerMixto(){
		int num=impropia.ObtenerNumerador(),den=impropia.ObtenerDenominador();
		while(static_cast<float>(num)/static_cast<float>(den)>1){
			num=num-den;
			m_entero++;
		}
		return to_string(m_entero)+" "+to_string(num)+"/"+to_string(den);
	}
	float ConvertirAFloat() {
		int num=impropia.ObtenerNumerador(),den=impropia.ObtenerDenominador();
		return m_entero + static_cast<float>(num) / static_cast<float>(den);
	}
};


int main() {
	
	int num, den, entero;
	cout << "entero, numerador y denominador: " << endl;
	cin >> entero >> num >> den;
	NumeroMixto a(entero,num,den);
	cout << a.ObtenerMixto() << endl << a.ConvertirAFloat();
	
	
	return 0;
}

