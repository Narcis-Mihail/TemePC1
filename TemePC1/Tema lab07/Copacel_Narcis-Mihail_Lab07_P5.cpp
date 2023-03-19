// Copacel_Narcis-Mihail_Lab07_P5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Punct
{
    float x, y, z;

public:
    Punct(float, float, float);
    Punct(Punct&);
    void init(void);
    void afisare(void);
    void Translatie(float, float, float);
    void dreapta(Punct, Punct);
};

Punct::Punct(float xi = 0, float yi = 0, float zi = 0)
{
    x = xi;
    y = yi;
    z = zi;
}

Punct::Punct(Punct& pct)
{
    x = pct.x;
    y = pct.y;
    z = pct.z;
}

void Punct::init(void)
{
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    cout << "z=";
    cin >> z;
}

void Punct::afisare(void)
{
    cout << "\nCoordonata x este: " << x;
    cout << "\nCoordonata y este: " << y;
    cout << "\nCoordonata z este: " << z;
}

void Punct::Translatie(float a, float b, float c)
{
    x = x + a;
    y = y + b;
    z = z + c;

}

void Punct::dreapta(Punct pct1, Punct pct2)
{
    if ((((x - pct1.x) / (pct2.x - pct1.x)) == ((y - pct1.y) / (pct2.y - pct1.y))) && ((x - pct1.x) / (pct2.x - pct1.x)) == ((z - pct1.y) / (pct2.z - pct1.z)))
        cout << "\nPunctul apartine dreptei date de cele 2 pct! \n";
    else
        cout << "\n Punctul nu apartine dreptei! \n";
}

int main()
{
    Punct p1, p2, p3;
    float a, b, c;
    
    cout << "\nPunctul 1: \n";
    p2.init();

    cout << "\n Introduceti valorile cu care vreti sa translatati coordonatele (x,y,z): ";
    cout << "\n a=";
    cin >> a;
    cout << "\n b=";
    cin >> b;
    cout << "\n c=";
    cin >> c;
    cout << "\n";

    p1 = p2;
    p2.Translatie(a, b, c);
    cout << "\n Coord pct1: ";
    p1.afisare();

    cout << "\nCoord pct 2:";
    p2.afisare();

    cout << "\n Punctul 3: ";
    p3.init();
    cout << "\n Coord pct 3:";
    p3.afisare();

    p3.dreapta(p1, p2);

}

