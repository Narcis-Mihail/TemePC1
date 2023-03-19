// Copacel_Narcis-Mihail_Lab02_P9.cpp 

#include <iostream>
#include <conio.h>
using namespace std;


int recursiv(int suma, int i);
void afisare(int suma ,int i);

int main()
{
	int suma = 0, i = 0;

	recursiv(suma, i);
	

}

int recursiv(int suma , int i)
{
	cout << "Continuati(D/N): ";
	 char k = _getch();
	int n;
	
	if (k == 'n' || k == 'N')
		 afisare(suma, i);
	else
	{
		if (suma > 30)
			cout << "\nValoare limita depasita!\n";
		else
		{
			cout << "Introduceti o valoare: "; cin >> n;
			return recursiv(suma + n, i + 1);
		
		}
	}
	
}

void afisare(int suma, int i)
{
	cout << "\nSuma este egala cu: " << suma;
	cout << "\nMedia numerelor este egala cu: " << (float)suma / i;
}