#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	int anio=2016;
	char cambio[]="msw10";
	
	for(int i=0;i<78;i++) { 
		string a="design",b=".wds";
		string nombre=a+to_string(i+1)+b;
		cout << nombre << endl;
		fstream archi(nombre,ios::binary|ios::in|ios::out|ios::app);
		archi.seekp(178);
		archi.write(cambio,sizeof(cambio));
		archi.seekp(239);
		archi.write(reinterpret_cast<char*>(&anio),sizeof(int));
		archi.close();
	}
	
	
	
	return 0;
}

