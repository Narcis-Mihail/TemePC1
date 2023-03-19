// Copacel_Narcis-Mihail_Lab12_P3
/*Considerati achizitia de date de la un dispozitiv electronic (10 date). Afisati folosind un mesaj 
adecvat datele primite considerand un format minimal (partea intreaga). Determinati media 
acestor valori, iar daca depaseste un prag stabilit anterior, afisati aceste date in format detaliat 
considerand ca avem date de tip real, cu o precizie de 8 digiti.
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

void main(void) {
	int i, prag;
	float v[10], s = 0;
	cout << "\nIntroduceti cele 10 date:" << endl;
	for (i = 0; i < 10; i++) {
		cout << "v[" << i + 1 << "]=";
		cin >> v[i];
		s = s + v[i];

	}
	cout << "\nAfisare cele 10 valori, doar partea intreaga";
	for (i = 0; i < 10; i++) {
		cout << " " << (int)v[i];
	}
	cout << endl;
	cout << "\nAfisare cele 10 valori, in format complet";
	for(i = 0; i < 10;i++){
		cout << " " << v[i];
	}
	cout << "\nIntroduceti pragul:";
	cin >> prag;
	if (s / 10 > prag) {
		cout << "\nA depasit pragul,deci in format detaliat valorile sunt:";
		cout << setprecision(8);
		for (i = 0; i < 10; i++) {
			cout << v[i] << " ";
		}
	}
	else
		cout << "\nPragul nu a fost depasit, nu mai afisam nimic ";
	cin.ignore();
	cin.get();
}