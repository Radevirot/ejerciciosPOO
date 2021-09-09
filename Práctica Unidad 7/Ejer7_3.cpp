#include <iostream>
using namespace std;

template<typename T>
class VectorDinamico{
	int tam_;
	T *v;
public:
	VectorDinamico(int tam,bool random=false){
		tam_=tam;
		v=new T[tam_];
		if(random){
			for(int i=0;i<tam_;i++) { 
				v[i]= rand();
			}
			
		}
	}
	~VectorDinamico(){delete[] v;}
	T &operator[](int pos){
		for(int i=0;i<tam_;i++) { 
			if(i==pos){return v[i];}
		}
		return v[9999];
	}
	
	
	
};

int main() {
	
	VectorDinamico<string> din(2000,true);
	int a=123,b=463,c=486;
/*	din[0]=a;din[1]=b;din[2]=c;*/
	for(int i=0;i<2000;i++) { 
		cout << din[i] << endl;
	}
	
	
	return 0;
}

