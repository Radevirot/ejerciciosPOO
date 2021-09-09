#include <iostream>
#include <cmath>
using namespace std;

class Cilindro {
private:
	float m_r, m_h;
public:
	Cilindro(float r, float h){ m_r=r; m_h=h;}
	float ObtenerVolumen(){
		return 3.14159265358979323846 * (m_r * m_r) * m_h;
	}
};

int main() {
	
	float r_c1,h_c1;
	cout << "radio c1: "; cin >> r_c1;
	cout << "altura c1: "; cin >> h_c1;
	Cilindro c1(r_c1,h_c1),c2(5.3,10.2);
	cout << "volumen c1: " << c1.ObtenerVolumen() << endl << "volumen c2: " << c2.ObtenerVolumen();
	
	return 0;
}

