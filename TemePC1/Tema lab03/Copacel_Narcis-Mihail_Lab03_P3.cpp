// Tasca_Andrei-Antonio_Lab03_P3.cpp 
/*În cadrul unei companii de software se pune problema difuzării unor pachete de date la mai multe filiale, 
maxim 7, valoarea fiind introdusă de la intrarea standard. Filialele sunt dispuse în mai multe puncte din lume, 
costurile de transmisie fiind dependente de poziţia lor geografică. Pachetele trebuie să ajungă la fiecare filială 
chiar dacă nu există o legătură directă între toate filialele ci prin intermediul unei alte filiale caz în care 
pachetul va urma o rută ocolitoare. Costurile necesare transmiterii datelor în reţea se introduc iniţial la 
generarea sistemului. Să se determine şi afişeze ruta pe care trebuie transmise pachetele de date astfel încât 
pornind de la filiala i, citită de la intrarea standard pachetul să fie transmis cu cost minim (eventual cu 
confirmare adică pachetul poate să se întoarcă înapoi). Implementarea poate fi recursivă sau nerecursivă.
*/
#include <iostream>
#include <limits.h>
using namespace std;

int* x, n, ** cost, ** drum, * nr_f, * cf;
void backtracking(int k);
int posibil(int k);

void main(void) {
	int fs; //fs reprezinta filiala sursa

	cout << "Introduceti n numarul de filiale (0<n<=7): ";
	cin >> n;
	if (n <= 0 || n > 7)
	{
		cout << "Numarul de filiale nu respecta 0<n<=7 !" << endl;
		cin.ignore();
		cin.get();
		return;
	}
	//alocare dinamica matrice costuri
	if (cost = new int* [n]) //se aloca memorie pentru linii
	{
		//se aloca memorie pentru coloane
		for (int i = 0; i < n; i++)
			if (!(cost[i] = new int[n]))
			{
				cout << "Eroare la alocarea dinamica!";
				cin.ignore();
				cin.get();
				return;
			}
	}
	cout << "Introduceti costurile(daca nu exista legatura directa introduceti 0):" << endl;
	//citire matrice costuri
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				cost[i][j] = 0;
			else {
				cout << "COST intre filiale" << i + 1 << "si" << j + 1 << ":";
				cin >> cost[i][j];
			}
	//afisare matrice costuri
	cout << "Matricea costurilor arata astfel:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << cost[i][j] << ":";
		cout << endl;
	}
	//alocare memorie pt x
	if (!(x = new int[n]))
	{
		cout << "Alocare nereusita!" << endl;
		cin.ignore();
		cin.get();
		return;
	}
	//alocare dinamica pentru matricea drum
	if (drum = new int* [n])//pentru linii
	{
		//pentru coloane
		for (int i = 0; i < n; i++)
			if (!(drum[i] = new int[n]))
			{
				cout << "Eroare la alocarea dinamica!";
				cin.ignore();
				cin.get();
				return;
			}
	}
	if (!(nr_f = new int[n]))
	{
		cout << "Alocare nereusita!" << endl;
		cin.ignore();
		cin.get();
		return;
	}
	if (!(cf = new int[n]))
	{
		cout << "Alocare nereusita!" << endl;
		cin.ignore();
		cin.get();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			drum[i][j] = 0; //initializam matricea drumului cu 0
		nr_f[i] = -1; //initializez nr de filiale cu -1
		cf[i] = INT_MAX;//initializare cost cu nr intreg max posibil
	}
	cout << "Introduceti filiala de la care doriti sa aflati costurile: ";
	cin >> fs;

	fs -= 1;//ajustam indexul, stiind ca indexarea in C++ porneste de la 0 nu de la 1

	x[0] = fs;
	backtracking(1);

	cout << "Drumuri de cost minim!" << endl;

	for (int j = 0; j < n; j++)
		if (j != fs)
		{
			cout << "\nDrum intre " << fs + 1 << "si" << j + 1 << ":";
			if (nr_f[j] == -1)
				cout << "nu se poate ajunge!";
			else
			{
				cout << "\tCost: " << cf[j] << " DRUM: ";
				for (int i = 0; i <= nr_f[j]; i++)
					cout << drum[i][j] + 1 << " ";
			}
		}
	cout << endl;
	cin.ignore();
	cin.get();
}

void backtracking(int k)
{
	for (int i = 0; i < n; i++)
	{
		x[k] = i;
		if (posibil(k))
			backtracking(k + 1);
	}
}
int posibil(int k)
{
	int S = 0;
		//situatiile in care solutia nu este posibila
		if (cost[x[k - 1]][x[k]] == 0) //daca nu exista drum direct
			return 0;
	for (int i = 0; i < k; i++)
		if (x[k] == x[i]) //daca am mai trecut prin acea filiala
			return 0;
	//daca s-a ajuns aici, solutia este posibila
	for (int i = 0; i < k; i++)
		S += cost[x[i]][x[i + 1]];//calculam suma costurilor de la filiala sursa la filiala k
	if (S < cf[x[k]])//daca suma e mai mica decat costul filialei respective
	{
		nr_f[x[k]] = k; //nr de filiale devine egal cu k
		cf[x[k]] = S; //costul min al filialei primeste suma
		for (int j = 0; j <= k; j++)
			drum[j][x[k]] = x[j]; //pe coloana x[k]vom salva drumul parcurs
	}
}