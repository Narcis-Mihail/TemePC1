// Copacel_Narcis-Mihail_Lab10_p6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
using namespace std;

#define Pi 3.14

class Forme
{
protected:
    char* nume;
public:
    
    
};

class Cerc : public Forme
{
    int r;
public:
    Cerc(char* n, int r)
    {
        this->nume = new char[strlen(n) + 1];
        strcpy(this->nume, n);
        this->r = r;
    }

    float aria()
    {
        return Pi * pow(r, 2);
    }

    float perimetru()
    {
        return 2 * Pi * r;
    }

    void display()
    {
        cout << "\n\tNumele cercului este: " << nume;
        cout << "\n\tRaza cercului este egala: " << r;

    }
};

class Patrat :public Forme
{
    int lat;
public:
    Patrat(char* n, int lat)
    {
        this->nume = new char[strlen(n) + 1];
        strcpy(this->nume, n);
        this->lat = lat;
    }

    float aria()
    {
        return pow(lat, 2);
    }

    int perimetru()
    {
        return 4 * lat;
    }



};

class Dreptunghi :public Forme
{
    int L, l;
public:
    Dreptunghi(char* n, int L, int l)
    {
        this->nume = new char[strlen(n) + 1];
        strcpy(this->nume, n);
        this->L = L;
        this->l = l;
    }
    float aria()
    {
        return L * l;
    }

    float perimetru()
    {
        return 2 * (L + l);
    }
};


int main()
{
    char nume[30],cont;
    int x,y;
   
    do
    {
        cout << "\n\tCe forma geometrica doriti sa introduceti? (c-cerc/d-dreptunghi/p-patrat/n-niciuna)\n";
        cin >> cont;

        switch (cont)
        {
        case 'c':
        {cout << "\nIntroduceti numele cercului: ";
        cin >> nume;
        cout << "Introduceti raza cercului: ";
        cin >> x;
        Cerc c(nume, x);
        cout << "\n\tPerimetrul cercului este egal cu: " << c.perimetru();
        cout << "\n\tAria cercului este egala cu: " << c.aria(); }
            break;
        case 'p':
        {cout << "\nIntroduceti numele patratului: ";
        cin >> nume;
        cout << "Introduceti latura patratului: ";
        cin >> x;
        Patrat p(nume, x);
        cout << "\n\tPerimetrul patratului este egal cu: " << p.perimetru();
        cout << "\n\tAria patratului este egala cu: " << p.aria(); }
            break;
        case 'd':
        {cout << "\nIntroduceti numele dreptunghilui: ";
        cin >> nume;
        cout << "Introduceti lungimea si latimea dreptunghiului: ";
        cin >> x >> y;
        Dreptunghi d(nume, x, y);
        cout << "\n\tPerimetrul dreptunghiului este egal cu: " << d.perimetru();
        cout << "\n\tAria dreptunghilui este egala cu: " << d.aria(); }
            break;
        case 'n':
            cout << "\n\tIesire din program!!";
            break;
        default:
            cout << "\n\t\tSelectie inexistenta!!";
            break;
        }
    } while (cont != 'n' && cont != 'N');
}
