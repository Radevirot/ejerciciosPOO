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
	float &operator[](int i){
		if(i==0){
			return Re_m;
		} else{
			return Im_m;
		};
	}
};

ostream &operator<<(ostream &o,Complejo c){
	o << c.VerParteReal() << "+" << c.VerParteImag() << "i";
	return o;
}


int main() {
	
	Complejo a;
	a[0]=2;a[1]=3;
	
	cout << a[0] << "+" << a[1] << "i" << endl;
	
	return 0;
}

