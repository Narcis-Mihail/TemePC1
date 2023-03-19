// Copacel_Narcis-Mihail_Lab10_P5.cpp 


#include <iostream>
#include <math.h>
using namespace std;

class Triangle
{
protected:
    float a, b, c;
public:
    Triangle(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }

    float perimetru()
    {
        return a + b + c;
    }
};

class TriangleExtended :public Triangle
{
public:
    TriangleExtended(float x, float y, float z) :Triangle(x, y, z) {}
    float aria()
    {
        float p;
        p = perimetru() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void inaltime()
    {
        char car;
        cout << "\nInaltimea corespunzatoare carei laturi doriti sa o aflati? :";
        cin >> car;
        switch (car)
        {
        case 'a':
            cout << "Inaltimea din varful A este: \n" << 2 * aria() / a << endl;
            break;
        case 'b':
            cout << "Inaltimea din varful B este: \n" << 2 * aria() / b << endl;
            break;
        case 'c':
            cout << "Inaltimea din varful C este: \n" << 2 * aria() / c << endl;
            break;
        default:
            cout << "Alegerea dvs. nu corespunde cerintelor\n" << endl; break;


        }
    }
};

void main()
{
    float x, y, z;

    do {
        cout << "Introduceti valorile laturilor triunghiului: \n";
        cout << "\tx= ";
        cin >> x;
        cout << "\ty= ";
        cin >> y;
        cout << "\tz= ";
        cin >> z;
    } while ((x < 0) || (y < 0) || (z < 0) || (x + y < z) || (z + y < x) || (x + z < y));

    TriangleExtended t(x, y, z);
    cout << "\n\tPerimetrul triunghiului este: " << t.perimetru() << endl;
    cout << "\tAria triunghiului este: " << t.aria()<<endl;
    cout << "Inaltimea corespunzatoare unei laturi: ";
    t.inaltime();
}

