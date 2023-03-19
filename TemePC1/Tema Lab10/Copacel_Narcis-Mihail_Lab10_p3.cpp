// Copacel_Narcis-Mihail_Lab10_p3.cpp 

#include <iostream>
#include <math.h>
using namespace std;

class Baza
{
protected:
    int a;
    int b;
public:
    void citire()
    {
        int x, y;
        cout << "Dati valoarea lui x: ";
        cin >> x;
        cout << "Dati valoarea lui y: ";
        cin >> y;
        a = x;
        b = y;
    }

    void afisare(int z)
    {
        cout << z << endl;
    }
};

class Derivata1 :public Baza {
public:
    Derivata1(){}
    int adunare()
    {
        return a + b;
    }

    int scadere()
    {
        return a - b;
    }

    int inmultire()
    {
        return a * b;
    }

    float impartire()
    {
        if (b != 0)
            return (float)a / b;
        else
            cout << "\n\tAtentie!!\tImpartire la 0!!\n\n";
    }
};

class Derivata2 :public Derivata1
{
public:
    Derivata2() {}

    float radacina(int x)
    {
        return sqrt(float(x));
    }

    float putere(int b, int p)
    {
        return pow((float)b, p);
    }

};

void main()
{
    int x, b, p;
    Derivata1 ob1;
    ob1.citire();
    cout << "\nSuma celor 2 numere este: " << ob1.adunare();
    cout << "\nDiferenta celor 2 numere este: " << ob1.scadere();
    cout << "\nProdusul celor 2 numere este: " << ob1.inmultire();
    cout << "\nCatul celor 2 numere este: " << ob1.impartire();
    Derivata2 ob2;
    cout << "\n Dati un alt numar: ";
    cin >> x;
    cout << "\nRadacina patrata a numarului este: " << ob2.radacina(x);
    cout << "\nDati baza: ";
    cin >> b;
    cout << "\nDati puterea: ";
    cin >> p;
    cout << "\n" << b << " la puterea " << p << " este: " << ob2.putere(b, p);
    
}

