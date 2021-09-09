int pos;
bool entra=false;
for(int i=0;i<cant_pos_;i++) { 
	if(v_[i].puntos<a.puntos){
		entra=true;
		pos=i;
		break;
	}
}
if(entra){
	vector<Puntaje> aux(cant_pos_);
	cout << pos << endl << endl;
	for(int i=0;i<pos;i++) { 
		aux[i]=v_[i];
		cout << aux[i].puntos << endl;
	}
	aux[pos]=a; cout << aux[pos].puntos << endl;
	for(int i=pos+1;i<cant_pos_;i++) { 
		aux[i]=v_[i];
		cout << aux[i].puntos << endl;
	}
	v_=aux; v_.;
	replace(v.begin()+pos,)
}




Puntaje a;
a.n="asdasd";
a.puntos=352;
Puntaje b;
b.n="ryrtu";
b.puntos=474;
Puntaje c;
c.n="ouhjg";
c.puntos=7956;
Puntaje d;
d.n="bcncv";
d.puntos=8907;
Puntaje e;
e.n="afhf";
e.puntos=11111;

Tabla ta(pos);
cout << endl;
ta.CargarPuntaje(a);
ta.CargarPuntaje(b);
ta.CargarPuntaje(c);
ta.CargarPuntaje(d);
ta.CargarPuntaje(e);




for(int i=0;i<pos;i++) { 
	Puntaje test = ta.ObtenerPuntaje(i);
	cout << test.n << " " << test.puntos << endl;
}

ta.GuardarEnArchivo("tabla.dat");
