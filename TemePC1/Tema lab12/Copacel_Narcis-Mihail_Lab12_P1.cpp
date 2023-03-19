// Copacel_Narcis-Mihail_Lab12_P1
/*Scrieţi un program C++ în care afişaţi diferite valori în zecimal, octal şi hexazecimal. Afişaţi 
valorile aliniate la dreapta, respectiv la stânga într-un câmp de afişare cu dimensiunea 15. 
Utilizaţi manipulatorul setfill( ) pentru stabilirea caracterului de umplere şi metodele width( )
şi precision( ) pentru stabilirea dimensiunii câmpului de afişare şi a preciziei. */

#include<iomanip>
#include<iostream>
#include<conio.h>
using namespace std;

void main() {
	int x, y;
	float z;
	cout << "\nCititi prima valoare(nr intreg pozitiv): ";
	cin >> x;
	cout << "\nCititi a doua valoare(nr intreg negativ): ";
	cin >> y;
	cout << "\nCititi o valoare reala: ";
	cin >> z;
	cout << "\nPrima valoare afisata in zecimal: " << dec << x;//afisare in zecimal
	cout << "\nPrima valoare afisata in octal: " << oct << x;//afisare in octal
	cout << "\nPrima valoare afisata in hexazecimal: " << hex << x;//afisare in hexazecimal
	cout << "\nA doua valoare afisata in zecimal: " << dec << y;
	cout << "\nA doua valoare afisata in octal: " << oct << y;
	cout << "\nA doua valoare afisata in hexazecimal: " << hex << y;
	cout.setf(ios::dec);//voi afisa valorile urmatoare in zecimal

	//stabilesc caracterul de umplere '*', latimea la 15
	cout << "\nAfisarea primei valori intregi cu aliniere stanga/dreapta";
	cout << setfill('*');
	cout.width(15); //se stabileste latimea
	cout.setf(ios::left);
	cout << endl << x << endl;//afisez prima valoare alineata la stanga cu dimensiune 15 si precizie 3
	cout.width(15);//se stabileste latimea
	cout.setf(ios::left);
	cout << y << endl;//afisam prima valoare aliniata la stg cu dimensiune 15 si precizie 3
	cout.unsetf(ios::left);

	cout << "\nAfisarea celei de a doua valori intregi cu aliniere stanga/dreapta\n";
	cout.width(15); //se stabileste latimea
	cout.setf(ios::right);
	cout << x << endl; //afisez a doua valoare aliniata la stg cu dimensiune 15 si precizie 3
	cout.unsetf(ios::right);

	//latimea campului 15, precizie 3
	cout << "Afisarea valorii reale:\n";
	cout.width(15); //se stabileste latimea
	cout.setf(ios::fixed);
	cout.precision(3); //se stabileste precizia
	cout.setf(ios::right);
	cout << z << endl; //Afisez valoarea reala aliniata la dreapta cu dimensiune 15 si precizie 3
	cin.ignore();
	cin.get();
}