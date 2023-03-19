/*Să se definească o clasă care implementează metodele:
- int plus(int x, int y), care returnează suma valorilor primite la apelul metodei;
- int minus(int x, int y), care returnează diferenta valorilor primite la apelul metodei;
- int inmultit(int x, int y), care returnează produsul valorilor primite la apelul metodei;
- float impartit(int x, int y), care returnează catul valorilor primite la apelul metodei;
şi apoi să se scrie aplicaţia care utilizează această clasă. Considerati si cazul in care in cadrul 
clasei aveti atributele de tip int x si y, caz in care metodele nu vor mai avea parametrii.
Observaţie: În cazul împărţirii, trebuie verificată validitatea operaţiei (împărţitor diferit de 
zero). În cazul în care operaţia este imposibilă, trebuie afişat un mesaj de eroare.*/

#include <iostream>
using namespace std;
#include<stdlib.h>

class Operatii {
public:
	int plus(int x, int y) //returneaza suma valorilor primile la apelul metodei
	{
		return x + y;
	}
	int minus(int x, int y) //returneaza diferenta valorilor primite la apelul metodei
	{
		return x - y;
	}
	int inmultit(int x, int y)//returneaza produsul valorilor primite la apelul metodei
	{
		return x * y;
	}
	int impartit(int x, int y)//returneaza partea intreaga a catului valorilor primite la apelul metodei;
	{
		if (y != 0)
			return x / y;
		else
		{
			cout << endl << "Eroare: numitorul e zero!";
			cin.ignore();
			cin.get();
			exit(0);
		}
	}
};

void main() {
	int x, y;
	Operatii ob1; //declaram obiectul ob1
	Operatii* p = &ob1; //declaram un pointer la un obiect
	cout << "Introduceti primul nr: " << endl;
	cin >> x;
	cout << "Introduceti al doilea nr: " << endl;
	cin >> y;

	cout << "Suma nr este:" << p->plus(x, y) << endl;
	cout << "Diferenta dintre numere este: " << p->minus(x, y) << endl;
	cout << "Produsul numerelor este: " << p->inmultit(x, y) << endl;
	cout << "Catul(parte intreaga) numerelor este: " << p->impartit(x, y) << endl;
	cin.ignore();
	cin.get();
}