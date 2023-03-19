// Copacel_Narcis-Mihail_Lab09_P4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<malloc.h>
using namespace std;

class Departament;
class Angajat
{
	char* nume;
	float salariu;

public:
	Angajat() {}
	Angajat(const char* , float s);
	char* getNume();
	float getSalariu();

	void setNume(char* nume)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void display()
	{
		cout << "\n\tNume: " << this->nume;
		cout << "\n\tSalariu: " << this->salariu;
	}
	friend class Departament;

	void* operator new(size_t marime);
	void operator delete(void* a);
};

Angajat::Angajat(const char *n, float s)
{
	nume = new char[strlen(n) +1];
	strcpy(nume, n);
	salariu = s;
}

char* Angajat::getNume()
{
	return nume;
}

float Angajat::getSalariu()
{
	return salariu;
}



class Departament
{
	Angajat* a;
	int nrA;
public:
	
	Departament() {}
	Departament(int n);
	void citire()
	{
		char nume[20];
		for (int i = 0; i < nrA; i++)
		{
			cout << endl << "Dati numele: ";
			cin >> nume;
			a[i].setNume(nume);
			cout << endl << "Dati salariul: ";
			cin >> a[i].salariu;
		}
	}

	Angajat operator[](int);

	void* operator new[](size_t marime);
	void operator delete[](void* a);
};

Angajat Departament::operator[](int index)
{
	return a[index - 1];
}

void* Angajat::operator new(size_t marime)
{
	return malloc(marime);
}

void Angajat::operator delete(void* a)
{
	free(a);
}

Departament::Departament(int nr)
{
	nrA = nr;
	a = new Angajat[nrA];
	if (!a)
	{
		cout << "\nNu am putut aloca dinamic memorie!!";
		exit(0);
	}
	}

void* Departament::operator new[](size_t marime)
{
	return malloc(marime);
}

void Departament::operator delete[](void* a)
{
	free(a);
}

void main()
{
	int nr, ind;
	cout << "Dati numarul de angajati: ";
	cin >> nr;

	Angajat* a = new Angajat("Popescu",200 );
	cout << "\nInformatii despre angajat: ";
	a->display();

	Departament ob(nr);
	Departament* ob2 = new Departament[2];
	ob2[0] = Departament(1);
	ob2[1] = Departament(2);

	ob.citire();
	cout << endl << "Dati angajatul cu nr. de ordine: ";
	cin >> ind;
	if (ind >= 1 && ind <= nr)
	{
		cout << "\nAngajatul cu nr de ordine " << ind << " este: \n";
		ob[ind].display();
	}
	else
		cout << "\nNumarul de ordine este invalid!";
	delete a;
	delete[]ob2;

}
