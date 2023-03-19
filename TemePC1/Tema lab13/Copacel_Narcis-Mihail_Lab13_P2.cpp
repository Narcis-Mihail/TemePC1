// Copacel_Narcis-Mihail_Lab13_P2.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
    char nume[10];
    fstream fout;
    cout << "Introduceti numele fisierului: ";
    cin >> nume;
    fout.open(nume, ios::out );
    
    if (!fout.is_open())
    {
        cout << "\n\t\tNu se poate deschide fisierul!!!";
        exit(1);
    }

    char sir[100];
    cout << "Introduceti sirul pentru a fi adaugat in fisier: ";
    cin.get();
    cin.get(sir, 100);
    fout.write(sir, strlen(sir));
    fout.close();
   
    fout.open(nume, ios::in);
    char n;
    while (!fout.eof())
    {
        fout.get(n);
        if (fout.eof())
            break;
        cout << n;
    }

    fout.close();
    return 0;

}

