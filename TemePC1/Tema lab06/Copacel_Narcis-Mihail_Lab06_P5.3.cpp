// Copacel_Narcis-Mihail_Lab06_P5.3.cpp 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
using namespace std;

class Matrix {
	//atribute
	int* p, dim1, dim2;
	//declararea metodei de afisare a unui element
	int returnElement(int row, int column);
public:
	//constructor explicit cu parametri – recomandat a folosi o metoda diferita a citi valorile
	Matrix(int dim1, int dim2) {
		//variabile locale
		int i, j;
		this->dim1 = dim1;
		this->dim2 = dim2;
		p = (int*)malloc(dim1 * dim2 * sizeof(int));

		cout << "\nIntroduceti elementele matricii: ";
		for (i = 0; i < dim1; i++) {
			for (j = 0; j < dim2; j++) {
				cout << "\nmatrix[" << i << "][" << j << "] = ";

				scanf("%d", (p + i * dim2 + j));

			}
		}
	}
	//metoda de afisare a matricii din clasa; implementare in cadrul clasei
	void displayMatrix() {
		//variabile locale
		int i, j;
		cout << "\nElementele matricii: ";
		for (i = 0; i < dim1; i++) {
			cout << "\n";
			for (j = 0; j < dim2; j++) {
				//apelul metodei private care returneaza valoarea unui element din matrice
				cout << returnElement(i, j) << " ";
			}
		}
		cout << endl;
	}
	//declararea metodei de afisare a elementelor unei coloane
	void displayColumn(int col);
	void displayScdDiag();
	void displayMatrix01(int x);
};
void Matrix::displayMatrix01(int x)
{
	for (int i = 0; i < dim1; i++)
	{
		for (int j = 0; j < dim2; j++)
			if (*(p + i * dim1 + j) > x)
				cout << "0" << " ";
			else
				cout << "1" << " ";
		cout << endl;
	}
}
void Matrix::displayScdDiag()
{
	if (dim1 != dim2)
		cout << "\n\nMatricea nu este patratica!!!";
	else
	{
		cout << "\n\nElementele de pe coloana secundara sunt: ";
		for (int i = 0; i < dim1; i++)
			for (int j = 0; j < dim1; j++)
			{
				if (i + j == dim1 - 1)
					cout << returnElement(i, j) << " ";
			}
	}
}
//implementarea externa a metodelor (publice sau private) declarate in clasa
void Matrix::displayColumn(int col) {
	if (col < 0 || col >= dim2) {
		cout << "\nColoana cu numarul " << col << " nu exista in matricea din clasa!\n";
	}
	else {
		cout << "\nElementele coloanei " << col << ": ";
		for (int i = 0; i < dim1; i++) {
			cout << returnElement(i, col) << " ";
		}
	}
}
int Matrix::returnElement(int row, int column) {
	return *(p + row * dim1 + column);
}
int main() {
	int dim1, dim2;
	cout << "\nIntroduceti dimensiunile 1 si 2 ale matricii: (<=10):\n";
	cin >> dim1;
	cin >> dim2;

	Matrix m1(dim1, dim2),*p;
	p = &m1;
	//instantiere cu citire valori
	p->displayMatrix();
	int c;
	cout << "\nIntroduceti un numar de coloana ale carei elemente vor fi afisate: (<dim2) ";
	cin >> c;
	p->displayColumn(c);
	p->displayScdDiag();
	cout << "\n\nIntroduceti o valoare: ";
	int x;
	cin >> x;
	p->displayMatrix01(x);
	//incercare (imposibila) de a accesa direct un membru privat al clasei
	//m1.returnElement(0, 0);
}
