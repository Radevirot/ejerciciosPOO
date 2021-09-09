#include <iostream>
#include <string>
using namespace std;

struct punto{
	float x;
	float y;
};

class Recta{
public:
	virtual string obtenerEcuacion()=0;
	bool pertenece();
};

class RectaExplicita:public Recta {
	float m_m, m_b;
public:
	RectaExplicita(punto p, punto q) {
		m_m=(q.y-p.y)/(q.x-p.x);
		m_b=p.y-m_m*p.x;
	}
	string obtenerEcuacion() override{ return "y="+to_string(m_m)+"x+"+to_string(m_b); }
	float verM(){ return m_m; }
	float verB(){ return m_b; }
};

class RectaGeneral:public Recta {
	float m_a, m_b, m_c;
public:
	RectaGeneral(punto p, punto q){
		m_a=q.y-p.y;
		m_b=p.x-q.x;
		m_c=-m_a*p.x-m_b*p.y;
	}
	string obtenerEcuacion() override{ return to_string(m_a)+"x+"+to_string(m_b)+"y+"+to_string(m_c)+"=0"; }
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
	Recta *expli = new RectaExplicita(p,q);
	RectaGeneral gen(p,q);
	Recta *pgen = &gen;
	cout << "Explicita: " << expli->obtenerEcuacion() << endl;
	cout << "General: " << pgen->obtenerEcuacion();
	cout << gen.verA() << " " << gen.verB() << " " << gen.verC() ;
	
	return 0;
}

