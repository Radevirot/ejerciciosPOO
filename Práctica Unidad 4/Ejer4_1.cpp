#include <iostream>
using namespace std;

class Racional { 
	int num, den;
public:
	Racional(int n, int d) : num(n), den(d) {}
	int VerNum(){return num;}
	int VerDen(){return den;}
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

int main() {
	
	Racional a(3,5), b(2,3), c(0,1);
	c=a+b;
	cout<<c.VerNum()<<"/"<<c.VerDen()<<endl;
	c=a*b;
	cout<<c.VerNum()<<"/"<<c.VerDen()<<endl;
	c=a+b+c;
	cout<<c.VerNum()<<"/"<<c.VerDen()<<endl;
	c=a*b*c;
	cout<<c.VerNum()<<"/"<<c.VerDen()<<endl;
	b=c++;
	a=++c;
	cout << a.VerNum() << "/" << a.VerDen()<<endl;
	cout << b.VerNum() << "/" << b.VerDen()<<endl;
	
	return 0;
}

