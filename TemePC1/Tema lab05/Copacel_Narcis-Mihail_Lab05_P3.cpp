// Copacel_Narcis-Mihail_Lab05_P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <assert.h>
#include "strClass.h"
using namespace std;



int main()
{
	char x[10],c;
	cout << "Introduceti un sir (maxim 10 caractere):"; cin >> x;
	assert(strlen(x) <= 10);
	myString s1;
	s1.Sir(x);

	cout << "\nLungimea sirului este:" << s1.getLungime()<<"\n";
	cin >> c;
	cout << "Ultima aparitie al caracterului " << c << " este pe pozitia:" << s1.getLastIndex(c);
	cout << "\nSirul scris cu caractere majuscule: ";
	s1.Majusc();
	cout << "\nSirul scris cu caractere majuscule: ";
	s1.minus();
	cout << "\nCaracterul " << c << " apare de: " << s1.nrApar(c)<< " ori.";


}

