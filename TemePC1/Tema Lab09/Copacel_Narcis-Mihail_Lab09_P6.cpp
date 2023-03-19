// Copacel_Narcis-Mihail_Lab09_P5.cpp 

#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

class Calculator
{
public:
    int calcul(int x);
    int calcul(int x, int y);
    double calcul(int x, int y, int z);
};

int Calculator::calcul(int x)
{
    return x * x;
}

int Calculator::calcul(int x,int y)
{
    return x * y;
}

double Calculator::calcul(int x,int y, int z)
{
    return ((x - y) * (x + z) / 2.0);
}

void main(int argc, char *argv[])
{
    Calculator ob1;
    if (argc < 4)
    {
        cout << "Nu ati introdus datele!\nTrebuie sa introduceti 3 numere intregi in linia de comanda \n";
        exit(0);
    }
    cout << "\nPatratul primului parametru este:" << ob1.calcul(atoi(argv[1])) << endl;
    cout << "Produsul celor 2 parametrii este: ";
    cout << ob1.calcul(atoi(argv[1]), atoi(argv[2]))<<endl;
    cout << "Rezultatul calculului cu formula f(x,y,z)=(x-y)(x+z)/2 este: ";
    cout << ob1.calcul(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}

