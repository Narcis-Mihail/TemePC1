// Copacel_Narcis-Mihail_Lab01_P6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdarg.h>
using namespace std;

float minim(int x, ...);

int main()
{
	float v[10], min1, min2;
	int i;

	cout << "Introduceti cele 10 numere:";
	for (i = 0; i < 10; i++)
		cin >> v[i];
	min1 = minim(7, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
	min2 = minim(3, v[7], v[8], v[9]);

	if (min1 > min2)
		cout << "Minimul sirului de numere este: " << min2;
	else
		cout << "Minimul sirului de numere este: " << min1;

}

float minim(int x, ...)
{
	va_list ap;
	float coef, min;
	int i;
	va_start(ap, x);
	min = HUGE_VAL;
	for (i = 0; i < x; i++)
	{
		coef = va_arg(ap, double);
		if (coef < min);
		min = coef;
	}
	va_end(ap);
	return min;
}