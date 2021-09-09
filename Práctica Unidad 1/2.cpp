#include <iostream>
using namespace std;

int *memoria(int *v,int size, int num);

int main() {
	int size;
	cout << "tamaño: ";
	cin >> size;
	int *v = new int[size];
	
	for(int i=0;i<size;i++) { 
		v[i] = i;
	}
	for(int i=0;i<size;i++) { 
		cout << v[i] << endl;
	}
	int num;
	cout << "número: ";
	cin >> num;
	
	cout << memoria(v,size,num);
	
	delete []v;
	
	return 0;
}

int *memoria(int *v,int size, int num){
	int *dir;
	for(int i=0;i<size;i++) { 
		if (v[i]==num){
			dir = &v[i];
			return dir;
		}
	}
	dir = nullptr;
	return dir;
}
