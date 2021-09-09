#include <iostream>
#include <vector>
using namespace std;

int dma_d(int d, int m, int a);


class Persona {
	string m_ape, m_nombre;
	int m_dni, m_dia, m_mes, m_anio;
	char m_civil;
public:
	Persona(string nombre, string ape, int dni, int dia, int mes, int anio, char civil){
		m_nombre=nombre;
		m_ape=ape;
		m_dni=dni;
		m_dia=dia;
		m_mes=mes;
		m_anio=anio;
		m_civil=civil;
	}
	int ObtenerEdad(){
		return (dma_d(25,9,2020)-dma_d(m_dia,m_mes,m_anio))/365;
	}
		string ObtenerNombre(){
			return m_nombre;
		}
			string ObtenerApellido(){
				return m_ape;
			}
};

class Alumno : public Persona {
	float m_prom;
	int m_cant_aprobadas;
public:
	Alumno(string nombre, string ape, int dni, int dia, int mes, int anio, char civil, float prom, int cant_aprobadas)
		: Persona(nombre, ape, dni, dia, mes, anio, civil), m_prom(prom), m_cant_aprobadas(cant_aprobadas) { }
	float ObtenerMeritoAcademico(){
		return m_prom*m_cant_aprobadas;
	}
	float ObtenerPromedio(){
		return m_prom;
	}
};

class Docente : public Persona {
	int m_diai, m_mesi, m_anioi;
public:
	Docente(string nombre, string ape, int dni, int dia, int mes, int anio, char civil, int diai, int mesi, int anioi)
		: Persona(nombre, ape, dni, dia, mes, anio, civil), m_diai(diai), m_mesi(mesi), m_anioi(anioi) { }
	int ObtenerAntiguedad(){
		return (dma_d(25,9,2020)-dma_d(m_diai,m_mesi,m_anioi))/365;
	}
};

class Curso{
	string m_nombrecurso;
	Docente m_docacargo;
	vector<Alumno> v;
public:
	Curso(string nombrecurso, string nombre, string ape, int dni, int dia, int mes, int anio, char civil, int diai, int mesi, int anioi)
		: m_docacargo(nombre, ape, dni, dia, mes, anio, civil, diai, mesi, anioi), m_nombrecurso(nombrecurso) { }
	void AgregarAlumno(Alumno a){
		if (v.size()<50){
			v.push_back(a);
		} else{
			cout << "El curso está lleno." << endl;
		}
	}
	Alumno MejorPromedio(){
		int mejora=0;
		float mejorprom=0;
		for (size_t i=0;i<v.size();++i){
			if (v[i].ObtenerPromedio() > mejorprom){
				mejorprom = v[i].ObtenerPromedio();
				mejora = i;
			}
		}
		return v[mejora];
	}
};

int main() {
	
	Persona juan("Juan","Perez",42356423,4,3,2001,'C');
	cout << juan.ObtenerNombre() << " " << juan.ObtenerApellido() << " tiene " << juan.ObtenerEdad() << " años." << endl;
	
	Alumno pedro("Pedro","Gonzalez",2583576,5,7,1999,'S',8.5,5);
	Alumno b("b","b",2583576,5,7,1999,'S',9,5);
	Alumno c("c","c",2583576,5,7,1999,'S',5,5);
	cout << pedro.ObtenerNombre() << " " << pedro.ObtenerApellido() << " tiene " << pedro.ObtenerEdad() << " años." << endl;
	cout << "Su mérito académico es " << pedro.ObtenerMeritoAcademico() << "." << endl;
	
	Docente nacho("Ignacio","Hernandez",34698543,2,12,1983,'C',10,3,2010);
	cout << nacho.ObtenerNombre() << " " << nacho.ObtenerApellido() << " tiene " << nacho.ObtenerEdad() << " años." << endl;
	cout << "Tiene " << nacho.ObtenerAntiguedad() << " años de antigüedad." << endl;
	
	Curso poo("Programación Orientada a Objetos", "Pablo", "Novara", 45346323, 1, 1, 1, 'S', 1, 1, 1);
	
	poo.AgregarAlumno(pedro); poo.AgregarAlumno(b); poo.AgregarAlumno(c); 
	Alumno mejor=poo.MejorPromedio();
	
	cout << "El alumno con más promedio es " << mejor.ObtenerNombre() << ", con un promedio de " << mejor.ObtenerPromedio() << "." << endl;
	
	return 0;
}

int dma_d(int d, int m, int a){
	return a*365+m*30+d;
}
	
