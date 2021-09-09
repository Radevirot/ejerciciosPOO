#include <iostream>
#include <algorithm>
using namespace std;

int rand10(){ return (rand()%21) - 10;}
bool es_par(int x){ return x%2==0;}
bool menor_abs(int a, int b){ return abs(a)<abs(b); }

int main() {
	
	int v[20];
	generate(v,v+20,rand10);
	for(int i=0;i<20;i++) { 
		cout << v[i] << endl;
	}
	
	size_t pares = count_if(v,v+20,es_par);
	cout << "pares: " << pares << endl;
	
	sort(v,v+20,menor_abs);
	
	for(int i=0;i<20;i++) { 
		cout << v[i] << endl;
	}
	cout << endl;
	
	auto it = unique(v,v+20);
	
	for(int i=0;i<(it-v);i++) { 
		cout << v[i] << endl;
	}
	
	return 0;
}

