#include <iostream>
#include <algorithm>
using namespace std;

bool descendiente(int a, int b){
	return a>b;
}

int main() {
	
	int *v = new int[30];
	for(int i=0;i<30;i++){
		*(v+i)=rand()%23 +1;
	}
	
	for(int i=0;i<30;i++){
		cout << *(v+i) << " ";
	}
	cout << endl << endl;
	
	sort(v+9,v+20,descendiente);
	
	for(int i=0;i<30;i++){
		cout << *(v+i) << " ";
	}
	cout << endl << endl;
	
	int *p=new int[11];
	
	copy(v+9,v+20,p);
	
	for(int i=0;i<11;i++){
		cout << *(p+i) << " ";
	}
	cout << endl << endl << "Valor: ";
	
	int valor;
	cin >> valor;
	size_t apariciones = count(v,v+30,valor);
	cout << "Apariciones: " << apariciones << endl;
	
	auto it = remove(v,v+30,valor);
	int tamanio = (it-v);
	cout << tamanio << endl << endl;
	
	int *mecagoenmivida = new int[tamanio];
	
	for(int i=0;i<tamanio;i++) { 
		*(mecagoenmivida+i) = *(v+i);
	}
	
	for(int i=0;i<tamanio;i++) { 
		cout << *(mecagoenmivida+i) << "  ";
	}
	cout << endl;
	
	
	delete[] v; delete[] p; delete[] mecagoenmivida;
	return 0;
}

