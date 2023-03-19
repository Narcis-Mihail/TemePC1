// Copacel_Narcis-Mihail_Lab09_P3.cpp 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Departament;
class Angajat
{
	char* nume;
	double salariu;

public:
	Angajat() {};
	char* getNume();
	float getSalariu();

	void setNume(char *nume)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void display()
	{
		cout <<"\n\tNume: "<<this->nume;
		cout << "\n\tSalariu: " << this->salariu;
	}
	friend class Departament;
};

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
	Departament(int n)
	{
		nrA = n;
		a = new Angajat[n];
	}
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
};

Angajat Departament::operator[](int index)
{
	return a[index - 1];
}



int main()
{
	int nr, ind;
	cout << "Introduceti numarul de angajati: ";
	cin >> nr;
	Departament ang(nr);
	cin.get();
	ang.citire();

	cout << "\nIntroduceti numarul de ordine al angajatului pentru care doriti informatii: ";
	cin >> ind;
	if (ind >= 1 && ind <= nr)
	{
		cout << "Angajatul cu numarul de ordine " << ind << " este: \n";
		ang[ind].display();
	}
	else
		cout << "\n\t\tNumarul de ordine este invalid!!!";

	return 0;
}
