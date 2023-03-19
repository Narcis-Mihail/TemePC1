// Tasca_Andrei-Antonio-Lab03-P4.cpp 
/*Problema investirii optime de capital: pentru un investitor cu un capital C şi n oferte la care trebuie avansate 
fondurile fi şi care aduc beneficiile bi, se cere selectarea acelor oferte care îi aduc beneficiul maxim.*/
#include <iostream>
#include <stdio.h>
using namespace std;

void citire();
void back(int k, int fp, int bp);
void save(int k, int max);
void afis();

//n-numarul de oferte
//c-capitalul de care dispunem
//f-sirul fondurilor pentru ofertele existente
//b-sirul beneficiilor corespunzatoare ofertelor
//bm-beneficiul maxim
//m-sirul ofertelor care aduc beneficiul maxim

int n, c, bm, f[20], b[20], m[20], x[20];

void main() {
	citire();
		bm = 0;
		back(1, 0, 0);
		afis();
		cin.ignore();
		cin.get();
}

void afis()
{
	if (bm != 0) {
		cout << "\nBeneficiul maxim este: " << bm << " obtinut investind in ofertele: ";
		for (int i = 1; i <= m[0]; i++)
		{
			cout << m[i] << ",";
		}
		cout << "\b\b \n";
	}
	else
		cout << "\nNu se poate investi in nici o oferta, capitalul este prea mic!";
}
void save(int k, int max)
{
	if (max > bm)
	{
		m[0] = k;
		for (int i = 1; i <= k; i++) m[i] = x[i];
		bm = max;
	}
}

void back(int k, int fp, int bp)
{
	int u[20];
	if (fp > c)
		save(k - 2, bp - b[x[k - 1]]);
	else
		for(int i=1;i<=n;i++)
			if (!u[i])
			{
				x[k] = i;
					u[i] = 1;
					back(k + 1, fp + f[i], bp + b[i]);
					u[i] = 0;
			}
}

void citire()
{
	cout << "Introduceti valoare capitalului: ";
	cin >> c;
	cout << "Introduceti numarul de oferte: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nIntroduceti fondurile necesare si beneficiile aduse pentru oferta " << i;
		cout << "\nfondul f[" << i << "]=";
		cin >> f[i];
		cout << "beneficiul b[" << i << "]=";
		cin >> b[i];
	}
}