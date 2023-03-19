// Tasca_Andrei-Antonio_Lab03_P6.cpp 
/*Scrieţi o aplicaţie care determină c.m.m.d.c. dintr-un tablou unidimensional de numere întregi (max. 2000 de 
valori), utilizând metoda divide et impera. Elementele tabloului se pot citi de la tastatură sau dintr-un fisier.*/

#include <stdio.h>
#include<conio.h>
 
//prototipul functiei recursive
int cmmdc(int v[], int pozi, int len);

void main(void) {
	//declaratii locale
	int n, v[2000], i;

	printf("Introduceti numarul de elemente ale tabloului, n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\n\t\telementul[%d]=", i + 1);
		scanf("%d", &v[i]);
	}
	printf("\nCMMDC al elementelor din tablou este %d\n", cmmdc(v, 0, n));//apelul functiei recursive
	_getch();
}

//functie ce returneaza recursiv cmmdc al elemetelor unui tablou 
int cmmdc(int v[], int pozi, int len)
{
	int a, b, r;
	if (len == 1)
		return v[pozi];
	else
	{
		a = cmmdc(v, pozi, len / 2);
		b = cmmdc(v, len / 2 + pozi, len / 2 + len % 2);

		//determinam cmmdc dintre doua numere
		while (a % b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return b;
	}
}