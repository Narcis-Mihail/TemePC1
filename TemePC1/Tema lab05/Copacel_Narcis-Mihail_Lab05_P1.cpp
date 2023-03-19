// Copacel_Narcis-Mihail_Lab05_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

struct SCerc {
	int raza;
	float arie(struct Cerc);
	float circumferinta(struct Cerc);
};

struct SCerc c1, c2;
float arie(struct SCerc c);
float circumf(struct SCerc c);


class Cerc {
private:int r;
public:
	Cerc(int raz) {

		r = raz;
	}
	~Cerc(void) { //destructor
		r = 0;
	}
	float arie(); //metoda de calcul a ariei
	float circumf(); //metoda de calcul a circumferintei
	int afisRaza() {//metoda accesor(getter) pentru atributul privat raza
		return r;
	}
};

float Cerc::arie() {
	return 3.14 * r * r;
}
float Cerc::circumf() {
	return 2 * 3.14 * r;
}


int main() 
{
	cout << "\tRezolvarea cu struct:\n";
	cout << "Introduceti raza primului cerc: "; cin >> c1.raza;
	cout << "Introduceti raza celui de-al doilea cerc:"; cin >> c2.raza;
	cout << "\n\tAria primului cerc este:" << arie(c1);
	cout << "\n\tCircumferinta primului cerc este:" << circumf(c1)<<"\n";

	cout << "\n\tAria celui de al doilea cerc este:" << arie(c2);
	cout << "\n\tCircumferinta celui de al doilea cerc este:" << circumf(c2);
	cout << "\n\n";
	
	cout << "\tRezolvarea cu clasa:\n";
	int x, y;
	cout << "Introduceti raza primului cerc: "; cin >> x;
	Cerc c1(x);
	cout << "Introduceti raza celui de-al doilea cerc:"; cin >> y;
	Cerc c2(y);

	cout << "\n\tAria primului cerc este:" << c1.arie();
	cout << "\n\tCircumferinta primului cerc este:" << c1.circumf() << "\n";

	cout << "\n\tAria celui de al doilea cerc este:" << c2.arie();
	cout << "\n\tCircumferinta celui de al doilea cerc este:" << c2.circumf();

	

}

float arie(struct SCerc c) {
	return 3.14 * (c.raza) * (c.raza);
}
float circumf(struct SCerc c) {
	return 2 * 3.14 * (c.raza);
}