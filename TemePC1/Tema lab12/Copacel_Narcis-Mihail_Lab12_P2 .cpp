// Copacel_Narcis-Mihail_Lab12_P2
/*Scrieti o aplicatie C++ in care se citesc de la tastatura date de diferite tipuri, urmand a fi 
afisate pe ecran utilizand manipulatorii standard.
*/

#include <iostream>
#include<iomanip>
using namespace std;

void main() {
	int x;
	float y;
	char cuv[10];
	cout << "\nDati primul numar(int): ";
	cin >> x;
	cout << "\nDati sirul: ";
	cin >> cuv;
	cout << "\nDati al doilea numar(float): ";
	cin >> y;
	//utilizez manupulatorii standard:dec,oct,hex,setfill()
	cout << "\nAfisez nr intreg x in decimal, octal si hexazecimal: ";
	cout << endl << dec << x << " " << oct << x << " " << hex << x;
	cout << "\nAfisez sirul cu dimens 10,spatiile goale umplandu-le cu caracterul '*': ";
	cout << endl << setfill('*') << setw(20) << cuv;
	cout << "\nAfisez nr real cu o precizie de 4 digiti: ";
	cout.setf(ios::fixed);
	cout << endl << setprecision(4) << y << endl;
}