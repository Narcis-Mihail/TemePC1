// Copacel_Narcis-Mihail_Lab12_P4
/*Definiti o clasa numita MiscareAccelerata care contine atributele private dc (distanta curenta, 
vc (viteza curenta) si a (acceleratia). atributele dc, vc si a sunt initializate in constructor iar 
valoarea lor este cea data de d0 si v0, si a0 ca si parametri. In clasa sunt supraincarcati 
operatorii de extractie si de inserție pentru a se putea initializa si afisa caracteristicile unei 
instante. Implementati metoda determinaMiscarea care re-calculeaza variabilele dc si vc, pe 
baza unui numar de secunde primit ca parametru si avand in vedere legea miscarii rectilinii 
uniform accelerate cu acceleratie a0.
Instantiati clasa si apoi folositi membrii definiti. */

#include <iostream>
using namespace std;
class MiscareAccelerata {
private:
	float dc;//distanta curenta
	float vc;//viteza curenta
	float a;//acceleratia

public:
	MiscareAccelerata() {}
	MiscareAccelerata(float ac, float v0, float d0) {
		vc = v0;
		dc = d0;
		a = ac;
	}
	void determinaMiscarea(float t) {
		dc = dc + vc * t + a * t * t / 2;
		vc = vc + a * t;
	}
	friend istream& operator>>(istream& stream,  MiscareAccelerata& ob);
	friend ostream& operator<<(ostream& stream,  const MiscareAccelerata& ob);
};

//definirea operatorului de extractie
istream& operator>>(istream& stream,  MiscareAccelerata& ob) {
	cout << "\nDati distanta initiala ";
	stream >> ob.dc;
	cout << "\nDati viteza initiala ";
	stream >> ob.vc;
	cout << "\nDati acceleratia ";
	stream >> ob.a;
	return stream;
}
ostream& operator<<(ostream& stream,  const MiscareAccelerata& ob) {
	stream << "\nAcceleratia: " << ob.a << endl;
	stream << "\nDistanta curenta: " << ob.dc << endl;
	stream << "\nViteza curenta: " << ob.vc << endl;
	return stream;
}

void main() {
	float t;
	MiscareAccelerata ob;
	cin >> ob;
	cout << "\nDati timpul de parcurgere: ";
	cin >> t;
	ob.determinaMiscarea(t);
	cout << "\nDupa intervalul de " << t << "secunde:" << endl;
	cout << ob;
	cin.ignore();
	cin.get();
}