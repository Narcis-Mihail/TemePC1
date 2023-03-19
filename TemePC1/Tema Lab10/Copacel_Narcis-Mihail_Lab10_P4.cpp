// Copacel_Narcis-Mihail_Lab10_P4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    TriangleExtended(float x, float y,float z):Triangle(x,y,z){}
    float aria()
    {
        float p;
        p = perimetru() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
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
        cout << "\tAria triunghiului este: " << t.aria();

}

