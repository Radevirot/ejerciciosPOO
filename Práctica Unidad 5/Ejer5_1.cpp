#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	
	ifstream iarchivo("Ejer5_1.txt");
	string x;
	vector<string> v;
	int i=0;
	while (iarchivo >> x){
		v.push_back(x);
		i++;
	}

	cout << i << endl;
	
	iarchivo.close();
	
	sort(v.begin(),v.end());
	
	ofstream oarchivo("Ejer5_1.txt", ios::trunc);
	if (!oarchivo.is_open()){cerr << "No se pudo abrir el archivo." << endl;}
	for(size_t j=0;j<v.size();j++) { 
		oarchivo << v[j] << endl;
	}
	
	oarchivo.close();
	
	return 0;
}

