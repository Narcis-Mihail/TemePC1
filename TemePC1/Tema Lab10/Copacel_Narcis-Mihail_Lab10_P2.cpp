// Copacel_Narcis-Mihail_Lab10_P2.cpp 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class BazaCod{

protected:
    char initial[20];
    char codat[20];
public:
    BazaCod(char sir[])
    {
        strcpy(initial, sir);
    }

    void codare()
    {
        int i;
        char c = 3;
        for (i = 0; i <= strlen(initial)-1; i++)
            codat[i] = initial[i] + c;
        codat[strlen(initial)] = '\0';
    }

    void afisare()
    {
        cout << "\nSirul initial este: " << initial;
        codare();
        cout << "\nSirul codat este: " << codat << endl;
    }

};

class DerivataCod :public BazaCod
{
public:
    DerivataCod(char a[]) :BazaCod(a) {}
    
    void scrieFisier(int nr_inregistrare)
    {
        ofstream out("a.txt");
        if (!out)
            cout << "\n\tEroare la deschiderea fisierului!";
        else
        {
            codare();
            out << nr_inregistrare << ": " << codat << endl;
            out.close();
        }
    
    }
    
};


void main()
{
    char a[20];
    int opt;
    int contor = 1;
    char cont;

    remove("a.txt");

    do{
        cout << "Introduceti un sir: ";
        cin >> a;
        DerivataCod ob(a);
        cout << "1 - afisarea pe ecran a sirului codat\n2 - scrierea in fisier a fisierului codat\n";
        cin >> opt;
        switch (opt)
        {
        case 1: ob.afisare();
            break;
        case 2:
            ob.scrieFisier(contor);
            contor++;
            break;
        default:cout << "Nu ati ales un sir corespunzator!!\n";
            break;
        }
        cout << "Mai doriti sa codati alt sir? y/n :";
        cin >> cont;

    } while (cont == 'y');

}
