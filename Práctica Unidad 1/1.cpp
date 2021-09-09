#include <iostream>
using namespace std;



int main() {

	
	int est = 10;
	int din;
	cin >> din;
	int *p = new int;
	*p = din;
	cout << "pos est: " << &est << endl;
	cout << "pos din: " << p;
	delete p;
	
	return 0;
}

