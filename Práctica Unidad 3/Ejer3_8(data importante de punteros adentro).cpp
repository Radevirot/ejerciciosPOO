#include <iostream>
#include <cmath>
using namespace std;

class Tanque{
protected:
	float m_peso;
	float m_vol;
public:
	void AsignarPeso(float peso){ m_peso=peso; }
	virtual void CalcularVolumen()=0;
	float VerVolumen() {return m_vol;}
	float VerPeso() {return m_peso;}
	virtual ~Tanque() {}
};

class Cilindro: public Tanque{
	float m_radio,m_altura;
public:
	Cilindro(float radio, float altura, float peso) {m_radio=radio;m_altura=altura;m_peso=peso;}
	void CalcularVolumen() override {m_vol=3.14159265359*pow(2,m_radio);}
};

class Esfera: public Tanque{
	float m_radio;
public:
	Esfera(float radio, float peso) {m_radio=radio;m_peso=peso;}
	void CalcularVolumen() override {m_vol=(4/3)*3.14159265359*pow(3,m_radio);}
};

int main() {
	
	float radio, altura, peso;
	cout << "radio, altura, peso (Cilindro): " << endl;
	cin >> radio >> altura >> peso;
	Tanque *p = new Cilindro(radio,altura,peso);
	(*p).CalcularVolumen(); // IMPORTANTE: Es lo mismo poner "(*p)." que "p->"
//							   Volver a usar el asterisco en el puntero sirve para desreferenciarlo.
//							   Resumiendo: 
//							              - Para crear un puntero se usa un asterisco (*p).
//							              - Para desreferenciar el puntero se puede usar el
//											asterisco nuevamente (*p), o bien la flecha (p->).
//										  - El ampersand cuando operamos punteros es una forma de
//										    decir "la posición en memoria de X", siendo X una variable normal (&X).
	cout << "vol: "<< p->VerVolumen() << endl << "peso: " << p->VerPeso() << "kg" << endl;
	cout << "----------------------------------------" << endl;
	cout << "radio, peso (Esfera): " << endl;
	cin >> radio >> peso;
	p = new Esfera(radio,peso);
	p->CalcularVolumen();
	cout << "vol: "<< p->VerVolumen() << endl << "peso: " << p->VerPeso() << "kg" << endl;
	delete p;
	
	return 0;
}


