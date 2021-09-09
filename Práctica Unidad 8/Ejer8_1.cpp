#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;

int main() {
	
	vector<int> v;
	for(int i=0;i<11;i++) { 
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	for(int i=0;i<11;i++) { 
		cout << v[i] << "  ";
	}
	cout << endl << endl;
	
	for(auto it=v.begin(); it!=v.end(); ++it ) { 
		cout << *it << "  ";
	}
	cout << endl << endl;
	
	for(int x:v){
		cout << x << "  ";
	}
	cout << endl << endl;
	
	auto it = max_element(v.begin(), v.end());
	cout << "Maximo: " << *it << endl;
	it = min_element(v.begin(),v.end());
	cout << "Minimo: " << *it << endl;
	
	float suma=accumulate(v.begin(),v.end(),0);
	cout << "Suma: " << suma << endl;
	
	cout << "Promedio: " << suma/v.size() << endl;
	
	it = next(v.begin(),v.size()/2);
	cout << "Mediana: " << *it << endl;
	
	
	
	return 0;
}

