#include <iostream>
using namespace std;

template<typename T>
void Clamp(T &var,T min,T max){
	if(var>max){
		var=max;
	}
	if(var<min){
		var=min;
	}
}



int main() {
	
	string min="bbb",max="ddd",val;
	cout << "min bbb, max ddd: "; cin >> val;
	Clamp(val,min,max);
	cout << val;
	
	return 0;
}

