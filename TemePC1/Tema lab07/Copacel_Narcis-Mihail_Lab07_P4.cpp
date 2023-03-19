// Copacel_Narcis-Mihail_Lab07_P4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Student
{
	char nume[20];
	char prenume[20];
	int nr_discipline;
	int* note;

public:
	Student();
	~Student();
	void init(char* n, char* p, int nr);
	float medie();
	char* get_nume() { return nume; }
	char* get_prenume() { return prenume; }
	int get_nr_discipline() { return nr_discipline; }
	void set_nume(char* n) { strcpy(nume, n); }
	void set_prenume(char* p) { strcpy(prenume, p); }
	void set_Nr_discipline(int n) { nr_discipline = n; }
	void restante()
	{
		int ok = 1;
		for (int i = 0; i < nr_discipline; i++)
		{
			if (this->note[i] < 5)
			{
				ok = 0;
				break;
			}
		}
		if (ok == 0)
			cout << " " << nume;
	}

};

Student::Student()
{
	char name[20], lastname[20];
	int nd;
	cout << "Introduceti datele studentului!\n";
	cout << "Nume:";
	cin >> name;
	cout << "Prenume:";
	cin >> lastname;
	cout << "Numar de discipline:";
	cin >> nd;
	init(name, lastname, nd);
}

Student::~Student()
{
	delete[]note;
 }

void Student::init(char* n, char* p, int nr)
{
	strcpy(nume, n);
	strcpy(prenume, p);
	nr_discipline = nr;
	note = new int[nr];
	cout << "Introduceti notele obtinute:\n";
	for (int i = 0; i < nr_discipline; i++)
	{
		cout << "\tNota " << i + 1 << ": ";
		cin >> note[i];
	}
}

float Student::medie()
{
	int S = 0;
	for (int i = 0; i < nr_discipline; i++)
		S += note[i];
	return (float)S / nr_discipline;
}

int main()
{
	int ns, nd, temp;
	float* medii;
	char nume[20], lastname[20], buf[20];

	cout << "Introduceti numarul studentilor din grupa: ";
	cin >> ns;
	Student* grupa = new Student[ns];

	cout << "Stundentii restantieri sunt: ";
	for (int i = 0; i< ns; i++)
	{
		grupa[i].restante();
	}

	medii = new float[ns];
	for (int i = 0; i < ns; i++)
		medii[i] = grupa[i].medie();

	int flag, nrparc = 0;
	for (int i = 0; i < ns; i++)
	{
		flag = 0;
		for (int j = 1; j < ns - nrparc; j++)
		{
			if (medii[j - 1] < medii[j])
			{
				flag = 1;
				temp = medii[j - 1];
				medii[j - 1] = medii[j];
				medii[j] = temp;

				//1.Schimbam numele
				strcpy(buf, grupa[j - 1].get_nume());
				grupa[j - 1].set_nume(grupa[j].get_nume());
				grupa[j].set_nume(buf);

				//2.Schimbam prenumele
				strcpy(buf, grupa[j - 1].get_prenume());
				grupa[j - 1].set_prenume(grupa[j].get_prenume());
				grupa[j].set_prenume(buf);

				//3.Schimbam numarul de discipline
				temp = grupa[j - 1].get_nr_discipline();
				grupa[j - 1].set_Nr_discipline(grupa[j].get_nr_discipline());
			}
		}
		nrparc++;
		if (flag == 0) break;
	}
	if (ns > 3)
	{
		cout << "\nPrimii trei studenti din grupa sunt: \n";
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << ": " << grupa[i].get_nume() << " " << grupa[i].get_prenume() << " Media: " << medii[i];
			cout << "(" << grupa[i].get_nr_discipline() << " discipline)\n";
		}
	}
	else
	{
		cout << "\nToti studentii au intrat in top 3 deoarece grupa contine doar " << ns << " studenti.\n";
		cout << "Top 3 arata astfel: \n";
		for (int i = 0; i < ns; i++)
		{
			cout << i + 1 << ": " << grupa[i].get_nume() << " " << grupa[i].get_prenume() << " Media: " << medii[i];
			cout << "(" << grupa[i].get_nr_discipline() << " discipline)\n";

		}
	}
}
