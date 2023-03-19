// Tasca_Andrei-Antonio_Lab03_P2.cpp 
/* Fie un sistem de calcul care urmăreşte controlul unui proces de transmisie a datelor pe o linie principală având 
un debit maxim de 40MB / s.Fluxul de date de pe această linie este împărţit de către maxim 10 utilizatori,
traficul pe liniile oferite lor putându - se efectua cu debite între 2 şi 40 MB / s(valori intregi).Impărţirea
debitelor pe cele maxim 10 linii se face în mod dinamic de către sistemul de control considerând pentru fiecare
linie i, o pondere subunitară pi, asociată la configurarea sistemului funcţie de utilizator.Introduceţi iniţial cele
maxim 10 ponderi pi astfel încât suma lor să fie egală cu 1. Dacă această condiţie este verificată generaţi toate
soluţiile posibile considerând că pe linia principală vom avea cel puţin un debit de 2MB / s, deci de 2...40MB / s
determinând în aceste cazuri debitele posibile pe cele maxim 10 linii de intrare ale utilizatorilor(ajustate la intregi MB / s).Se pune pe 0, dacă nu se poate asigura minimul de 2MB / s.Afişaţi aceste soluţii.Implementareapoate fi recursivă sau nerecursivă.*/

#include <iostream>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#define NRCANALE 10

void afis_sol(void);

int x[NRCANALE], n = 1, cont;
float pond[10];
int nmin = 2, nmax = 40;

void main(void)
{
    int k, i;
    float p = 0;
    cout << "Introduceti cele 10 ponderi: \n\n";

    for (i = 0; i < NRCANALE; i++)
    {
        cout << "Ponderea cu numarul " << i + 1 << ":";
        cin >> pond[i];
        p = p + pond[i];
    }
    if ((int)p != 1)
    {
        cout << "\nPonderi gresite"; exit(0);
    };
    cout << "\nIntroduceti debitul pe linia principala(2-40 mbps).Tastati valoarea 0 pentru debita iesi din program";
    while (n != 0)
    {
        cout << "\nDebitul: ";
        cin >> n;
        cout << "\nSolutiile sunt:\n";
        if (n <= nmax)
        {
            cont = 0;
            k = 0;
            x[k] = 0;
                do
                {
                    while (x[k] < nmax)
                    {
                        x[k] = x[k] + 1;
                        if (x[k] > nmin - 1)
                            if (k == (NRCANALE - 1)) afis_sol();
                            else {
                                k++; x[k] = 0;
                            }
                    }
                    k--;
                } while (!(k < 0));
        }//if
        else cout << "\nDebit invalid!";
    }//while
    cin.ignore();
    cin.get();
}//end main
    
void afis_sol(void)
{
    int l, i;
    double fraction, integer;
    double number = 0;

    for (i = 0; i < 10; i++)
        number = (double)(number + pond[i] * x[i]);
    l = (int)number;
    if (l == n)
    {
        for (i = 0; i < NRCANALE; i++)
            cout << x[i] * pond[i] << " ";
        cout << endl;
        cont++;
        if (cont > 20);
        {
            cont = 0; cout << "\nIntrodu un caracter pentru continuare\n";
            _getch();
        }
    }
}//end afis_sol
