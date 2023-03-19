// Copacel_Narcis-Mihail_Lab09_P2.cpp 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


const int linii = 2;
const int coloane = 3;
class Matrix {
	int rows;
	int cols;
	int* elems;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix&);
	~Matrix(void) { delete[] elems; }
	int& operator () (int row, int col);
	Matrix& operator=(const Matrix&);
	friend Matrix operator+(Matrix&, Matrix&);
	friend Matrix operator-(Matrix&, Matrix&);
	friend Matrix operator*(Matrix&, Matrix&);
	int getRows(void) { return rows; }
	int getCols(void) { return cols; }
	void init(int r, int c);
	void citire();
	void afisare();
	void diag();
};//Matrix

Matrix::Matrix() : rows(linii), cols(coloane)
{
	elems = new int[rows * cols];
}

Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
	elems = new int[rows * cols];
}

Matrix::Matrix(const Matrix& m) : rows(m.rows), cols(m.cols)
{
	int n = m.rows * m.cols;
	elems = new int[n];
	for (int i = 0; i < n; i++)
		elems[i] = m.elems[i];
}

Matrix& Matrix:: operator=(const Matrix& m) {
	if (this != &m) {
		delete[] elems;// this-> ~Matrix();
		rows = m.rows; cols = m.cols;
		int n = rows * cols;
		elems = new int[n];
		for (int i = 0; i < n; i++)
			elems[i] = m.elems[i];
	}
	return *this;
}

void Matrix::init(int r, int c) {
	rows = r;
	cols = c;
	elems = new int[rows * cols];
}

int& Matrix:: operator()(int row, int col)
{
	return elems[row * cols + col];
}

Matrix operator+(Matrix& p, Matrix& q) {
	Matrix m(p.rows, p.cols);
	for (int r = 0; r < p.rows; ++r)
		for (int c = 0; c < p.cols; ++c)
			m(r, c) = p(r, c) + q(r, c);
	return m;
}

Matrix operator-(Matrix& p, Matrix& q) {
	Matrix m(p.rows, p.cols);
	for (int r = 0; r < p.rows; ++r)
		for (int c = 0; c < p.cols; ++c)
			m(r, c) = p(r, c) - q(r, c);
	return m;
}//op

Matrix operator*(Matrix& p, Matrix& q) {
	Matrix m(p.rows, q.cols);
	for (int r = 0; r < p.rows; ++r)
		for (int c = 0; c < q.cols; ++c) {
			m(r, c) = 0;
			for (int i = 0; i < p.cols; ++i)
				m(r, c) += p(r, i) * q(i, c);
		}
	return m;
}//op*

void Matrix::citire() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			cout << "Dati elem. [" << i << "][" << j << "] ";
			cin >> elems[cols * i + j];
		}
}//citire

void Matrix::afisare() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << elems[cols * i + j] << "\t";
		cout << endl;
	}
}//afisare

void Matrix::diag()
{
	if (getRows() == getCols())
	{
		cout << "\nElementele de pe diagonala principala sunt:\n";
		int i = 0;
		while (i < getRows())
		{
			cout << elems[cols * i + i] << "\t";
			i++;
		}

		cout << "\nElementele de pe diagonala secundara sunt: \n";
		for (i = 0; i < getRows(); i++)
			for (int j = 0; j < getRows(); j++)
				if (i + j == getRows() - 1)
					cout << elems[cols * i + j] << "\t";
	}
	else
	
		cout << "\t\tMatricea nu este patratica!! Oprire program";
	
}

int main() {
	int i, j;
	//Matrix m(linii, coloane);
	//cout << endl << "Supraincarcarea operatorului() pentru atribuirea unei valori pentru fiecare element din matrice: \n";
	//	for (int i = 0; i < linii; i++)
	//		for (int j = 0; j < coloane; j++)
	//			m(i, j) = i + (j + 1) * 10;
	//for (i = 0; i < linii; i++)
	//{
	//	for (j = 0; j < coloane; j++)
	//		cout << m(i, j) << "\t";
	//	cout << endl;
	//}
	int l, c;
	//cout << "Verificarea supraincarcarii operatorului () pentru un element de pe o pozitie citita de la tastatura" << endl;
	//cout << "Dati numarului liniei (>=1): ";
	//cin >> l;
	//cout << "Dati numarului coloanei (>=1): ";
	//cin >> c;
	//if ((l >= 1 && l <= m.getRows()) && (c >= 1 && c <= m.getCols()))
	//	cout << "Elementul m[" << l << "," << c << "]=" << m(l - 1, c - 1) << endl;
	//else
	//	cout << "Indici eronati!" << endl;
	//cout << endl << "Utilizare constructor de copiere:" << endl;
	//if (m.getRows() > 0 && m.getCols() > 0) {
	//	Matrix mcopy = m;
	//	cout << "Matricea \"mcopy\" este:" << endl;
	//	mcopy.afisare();
	//}
	//else cout << "Dimensiuni invalide pentru matricea care se copiaza la instantiere!" << endl;
	//cout << endl << "Instantiem un nou obiect matrice \"n\" ";
	//Matrix n(linii, coloane);
	//cout << endl << "Dati matricea:" << endl;
	//n.citire();
	//cout << endl << "Matricea \"n\" este:" << endl;
	//n.afisare();
	//cout << endl << "Supraincarcarea operatorului =, copiere matrice \"m\" in matrice \"n\"" << endl;
	//if (m.getRows() == n.getRows() && m.getCols() == n.getCols()) {
	//	n = m;
	//	//n.afisare();
	//	for (i = 0; i < linii; i++) {
	//		for (j = 0; j < coloane; j++)
	//			cout << n(i, j) << "\t";//afisare prin Supraincarcarea operatorului()
	//		cout << endl;
	//	}///end for
	//}
	//else
	//	cout << "Matricile nu au aceleasi dimensiuni, deci nu pot fi copiate" << endl;
	//cout << endl << "Instantiem un nou obiect matrice \"m1\" ";
	//Matrix m1(linii, coloane);
	//cout << endl << "Dati matricea:" << endl;
	//m1.citire();
	//cout << endl << "Matricea \"m1\" este:" << endl;
	//m1.afisare();
	//Matrix m2(linii, coloane);
	//cout << endl << "Supraincarcarea operatorului +" << endl;
	//if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
	//	m2 = m + m1;
	//	cout << endl << "Matricea rezultata din suma matricilor m+m1 este: " << endl;
	//}
	//m2.afisare();
	//cout << endl << "Supraincarcarea operatorului - " << endl;
	//if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
	//	m2 = m - m1;
	//	cout << endl << "Matricea rezultata din diferenta matricilor m-m1 este: " << endl;
	//}
	//m2.afisare();
	///*matricea m are 2 linii si 3 coloane deci pentru a fi posibil produsul m3 trebuie sa aiba 3 linii si 2 coloane*/
	cout << endl << "Dati matricea pentru produs \"m3\' (matricea trebuie sa aiba numarul de linii egal cu numarul de coloane al matricii \"m\")" << endl;
	cout << "Numar de linii: ";
	cin >> l;
	cout << "Numar coloane: ";
	cin >> c;
	Matrix m3;
	if (l > 0 && c > 0) m3.init(l, c);
	else cout << endl << "Dimensiuni negative (gresite)! Se vor folosi pentru instantiere valorile initiale implicite(2 linii, 3 coloane)" << endl;
		m3.citire();
	cout << endl << "Matricea \"m3\" este:" << endl;
	m3.afisare();
	/*cout << endl << "Supraincarcarea operatorului * ";*/
	// pentru inmultire m*m3 nr. de coloane al matricii m trebuie sa fie egal cu numarul de randuri al matricii m3
	/*if (m.getCols() == m3.getRows())
	{
		Matrix m4(m.getRows(), m3.getCols());
		m4 = m * m3;
		cout << endl << "Matricea rezultata prin inmultirea matricilor m*m3 este: " << endl;
		m4.afisare();
	}
	else
		cout << endl << "Matricile nu pot fi inmultite - numarul de linii nu e egal cu numarul de coloane";*/
	
	m3.diag();
	return 0;
}//end main
