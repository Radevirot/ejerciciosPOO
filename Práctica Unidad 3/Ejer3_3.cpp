#include <iostream>
#include <string>
using namespace std;

struct punto{
	float x;
	float y;
};

class RectaExplicita {
	float m_m, m_b;
public:
	RectaExplicita(punto p, punto q){
		m_m=(q.y-p.y)/(q.x-p.x);
		m_b=p.y-m_m*p.x;
	}
	string obtenerEcuacion(){ return "y="+to_string(m_m)+"x+"+to_string(m_b); }
	float verM(){ return m_m; }
	float verB(){ return m_b; }
};

class RectaGeneral {
	float m_a, m_b, m_c;
public:
	RectaGeneral(punto p, punto q){
		m_a=q.y-p.y;
		m_b=p.x-q.x;
		m_c=-m_a*p.x-m_b*p.y;
	}
	string obtenerEcuacion(){ return to_string(m_a)+"x+"+to_string(m_b)+"y+"+to_string(m_c)+"=0"; }
	float verA(){ return m_a; }
	float verB(){ return m_b; }
	float verC(){ return m_c; }
};

int main() {
	
	punto p,q;
	cout << "Px: "; cin >> p.x;
	cout << "Py: "; cin >> p.y;
	cout << "Qx: "; cin >> q.x;
	cout << "Qy: "; cin >> q.y;
	RectaExplicita expli(p,q);
	RectaGeneral gen(p,q);
	cout << "Explicita: " << expli.obtenerEcuacion();
	cout << "General: " << gen.obtenerEcuacion();
	
	return 0;
}

