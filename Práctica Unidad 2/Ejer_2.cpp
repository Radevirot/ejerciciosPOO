#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica{
private:
	float m_a,m_b,m_c,m_r1,m_r2;
	bool m_son_reales;
	void calcular(){
		float d = (m_b*m_b)-(4*m_a*m_c);
		if (d>=0){
			m_son_reales = true;
			m_r1 = (-m_b+sqrt(d))/(2*m_a);
			m_r2 = (-m_b-sqrt(d))/(2*m_a);
		} else {
			m_son_reales = false;
			m_r1 = -m_b/(2*m_a);
			m_r2 = sqrt(-d)/(2*m_a);
		}
	}

public:
	EcuacionCuadratica(float a, float b, float c){
		m_a=a; m_b=b; m_c=c;
		calcular();
	}
	bool TieneRaicesReales(){
		return m_son_reales;
	}
	float VerRaiz1(){
		if (m_son_reales){
			return m_r1;
		} else {
			return 0;
		}
	}
	float VerRaiz2(){
		if (m_son_reales){
			return m_r2;
		} else {
			return 0;
		}
	}
	float VerParteReal(){
		if (!m_son_reales){
			return m_r1;
		} else {
			return 0;
		}
	}
	float VerParteImag(){
		if (!m_son_reales){
			return m_r2;
		} else {
			return 0;
		}
	}
};

int main() {
	
	float a, b, c;
	cout << "Ingrese los 3 coeficientes: " << endl;
	cin >> a >> b >> c;
	EcuacionCuadratica ec(a,b,c);
	if (ec.TieneRaicesReales()){
		cout << "Reales" << endl << "r1= " << ec.VerRaiz1() << endl;
		cout << "r2= " << ec.VerRaiz2() << endl;
	} else {
		cout << "Imaginarias" << endl << "r1= " << ec.VerParteReal() << " + " << ec.VerParteImag() << "i" << endl;
		cout << "r2= " << ec.VerParteReal() << " - " << ec.VerParteImag() << "i" << endl;
	}
	
	
	return 0;
}

