#include <iostream>
using namespace std;

class Racional { 
	int num, den;
public:
	Racional(int n, int d) : num(n), den(d) {}
	int VerNum(){return num;}
	int VerDen(){return den;}
	void CargarNum(int n){num=n;}
	void CargarDen(int d){den=d;}
};

ostream &operator<<(ostream &o,Racional a){
	o << a.VerNum()<< "/" << a.VerDen();
	return o;
}

istream &operator>>(istream &i,Racional &a){
	int n, d;
	i >> n;
	a.CargarNum(n);
	i >> d;
	a.CargarDen(d);
	return i;
}

int main() {
	Racional a(0,0);
	cin >> a;
	cout << a;

	return 0;
}

