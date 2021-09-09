#include <iostream>
using namespace std;

class Racional { 
	int num, den;
public:
	Racional(int n, int d) : num(n), den(d) {}
	float VerNum(){return num;}
	float VerDen(){return den;}
	Racional &operator++(){
		num+=den;
		return *this;
	}
	Racional operator++(int){
		Racional anterior = *this;
		num+=den;
		return anterior;
	}
};

Racional operator+(Racional a, Racional b){
	int n=a.VerNum()*b.VerDen()+b.VerNum()*a.VerDen();
	int d=a.VerDen()*b.VerDen();
	Racional c(n,d);
	return c;
}

Racional operator*(Racional a, int b){
	int n=a.VerNum()*b;
	int d=a.VerDen();
	Racional c(n,d);
	return c;
}

Racional operator*(Racional a, Racional b){
	int n=a.VerNum()*b.VerNum();
	int d=a.VerDen()*b.VerDen();
	Racional c(n,d);
	return c;
}

bool operator<(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora<valorb);
}

bool operator<=(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora<=valorb);
}

bool operator>(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora>valorb);
}

bool operator>=(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora>=valorb);
}

bool operator==(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora==valorb);
}

bool operator!=(Racional a, Racional b){
	float valora = a.VerNum()/a.VerDen();
	float valorb = b.VerNum()/b.VerDen();
	return (valora!=valorb);
}

int main() {
	int n1, d1, n2, d2;
	cout << "Racional 1:" << endl;
	cin >> n1 >> d1;
	Racional a(n1,d1);
	cout << "Racional 2:" << endl;
	cin >> n2 >> d2;
	Racional b(n2,d2);
	
	if(a>b){
		cout << "Racional 1 mayor a racional 2." << endl;
	}
	if(a>=b){
		cout << "Racional 1 mayor o igual a racional 2." << endl;
	}
	if(a<b){
		cout << "Racional 1 menor a racional 2." << endl;
	}
	if(a<=b){
		cout << "Racional 1 menor o igual a racional 2." << endl;
	}
	if(a==b){
		cout << "Racional 1 igual a racional 2." << endl;
	}
	if(a!=b){
		cout << "Racional 1 distinto de racional 2." << endl;
	}
	return 0;
}

