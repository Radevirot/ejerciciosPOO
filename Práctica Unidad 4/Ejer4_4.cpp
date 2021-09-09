#include <iostream>
using namespace std;

class Complejo{
	float Re_m, Im_m;
public:
	Complejo(float Re, float Im){Re_m = Re; Im_m=Im;}
	Complejo(){}
	float VerParteReal(){return Re_m;}
	float VerParteImag(){return Im_m;}
	void CargarParteReal(float Re){Re_m = Re;}
	void CargarParteImag(float Im){Im_m = Im;}
};

Complejo operator+(Complejo a, Complejo b){
	float Re = a.VerParteReal()+b.VerParteReal();
	float Im = a.VerParteImag()+b.VerParteImag();
	Complejo c(Re,Im);
	return c;
}

Complejo operator-(Complejo a, Complejo b){
	float Re = a.VerParteReal()-b.VerParteReal();
	float Im = a.VerParteImag()-b.VerParteImag();
	Complejo c(Re,Im);
	return c;
}

Complejo operator*(Complejo a, Complejo b){
	float Re = a.VerParteReal()*b.VerParteReal()-a.VerParteImag()*b.VerParteImag();
	float Im = a.VerParteReal()*b.VerParteImag()+a.VerParteImag()*b.VerParteReal();
	Complejo c(Re,Im);
	return c;
}

ostream &operator<<(ostream &o,Complejo c){
	o << c.VerParteReal() << "+" << c.VerParteImag() << "i";
	return o;
}

bool operator==(Complejo a, Complejo b){
	return (a.VerParteReal() == b.VerParteReal() && a.VerParteImag() == b.VerParteImag());
}

istream &operator>>(istream &i,Complejo &c){
	float Re, Im;
	i >> Re;
	c.CargarParteReal(Re);
	i >> Im;
	c.CargarParteImag(Im);
	return i;
}



int main() {
	Complejo a, b;
	cout << "Complejo 1:" <<endl;
	cin >> a;
	cout << a << endl;
	cout << "Complejo 2:" <<endl;
	cin >> b;
	cout << b << endl;
	if(a==b){
		cout << "Complejo 1 y Complejo 2 son iguales." << endl << endl;
	} else {
		cout << "Complejo 1 y Complejo 2 no son iguales." << endl << endl;
	}
	cout << "Complejo 1 + Complejo 2: " << a+b << endl;
	cout << "Complejo 1 * Complejo 2: " << a*b << endl;
	return 0;
}

