#include <iostream>
using namespace std;

int main() {
	
	int n;
	cout << "Cantidad de elementos";
	cin >> n;
	int (*v1)[];
	for(int i=0;i<n;i++) { 
		
		(*v1)[i]=rand()%1500+1000;
	}
	int mayor1=0, *cord1;
	for(int i=0;i<n;i++) { 
		if((*v1)[i]>mayor1){
			mayor1 = (*v1)[i];
			cord1 = (&v1);
		}
	}
	cout << "mayor1: " << mayor1 << endl << *cord1;
	return 0;
}

