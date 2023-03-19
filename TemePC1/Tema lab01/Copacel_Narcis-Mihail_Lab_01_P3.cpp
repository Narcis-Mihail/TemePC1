// Copacel_Narcis-Mihail_Lab_01_P3.cpp 

#include <iostream>
#include <assert.h>
using namespace std;

struct Student 
{
	char nume_prenume[30];
	int nota;

};

int main()
{
	int i=0;
	Student x;
	cout << "Introduceti numele studentului:";
	cin.get(x.nume_prenume, 30);
	while (x.nume_prenume[i]!=0)
	{
		i++;
	}
	assert(i >= 5);
	cout << "Introduceti nota studentului:";
	cin >> x.nota;
	assert(x.nota >= 5 && x.nota <= 10);
	cout << "\nNumele studentului: " << x.nume_prenume<<"\nNota studentului: "<<x.nota;


}
