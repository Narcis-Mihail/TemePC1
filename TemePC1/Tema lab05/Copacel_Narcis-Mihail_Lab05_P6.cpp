// Copacel_Narcis-Mihail_Lab05_P6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex {
    double re, im;
public:
    Complex(double x = 0.0, double y = 0.0) {
        re = x;
        im = y;
    }
    double modul() {
        return sqrt(re * re + im * im);
    }
    
    void setRe(double real) {
        re = real;
    }
    double getRe() {
        return re;
    }
    void setIm(double imaginar) {
        im = imaginar;
    }
    double getIm() {
        return im;
    }
    void ad_complex(Complex b) {//recomandat a returna un obiect
        re += b.re;
        im += b.im;
    }
    void sc_complex(Complex b) //recomandat a returna un obiect
    {
        re -= b.re;
        im -= b.im;
    }
};

int main()
{
    Complex z1,z2;
    double aux;
    cout << "Partea reala a obiectului 1 este: \t";
    cin >> aux;
    z1.setRe(aux);
    cout << "Partea imaginara a obiectului 1 este \t";
    cin >> aux;
    z1.setIm(aux);

    cout << "Partea reala a obiectului 2 este: \t";
    cin >> aux;
    z2.setRe(aux);
    cout << "Partea imaginara a obiectului 2 este \t";
    cin >> aux;
    z2.setIm(aux);

    cout << "Adunam cele doua obiecte:\n";
    z1.ad_complex(z2);
    cout << "Partea reala este " << z1.getRe() << " si partea imaginara este: " << z1.getIm();
    z1.sc_complex(z2);

    cout << "\nScadem cele doua obiecte:\n";
    z1.sc_complex(z2);
    cout << "Partea reala este " << z1.getRe() << " si partea imaginara este: " << z1.getIm();
}

