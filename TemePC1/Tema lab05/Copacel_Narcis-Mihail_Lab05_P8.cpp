// Copacel_Narcis-Mihail_Lab05_P8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex {

    float re, im;

public:
    void setRe(float x) { re = x; }
    void setIm(float x) { im = x; }
    float getRe() {return re; }
    float getIm() {return im; }
    Complex sum(Complex c);
    Complex difference(Complex c);
    Complex multi(Complex c);
    Complex div(Complex c);
};
Complex Complex::sum(Complex c) {
    Complex rez;
    rez.im = (c.im + im);
    rez.re = (c.re + re);
    return rez;
}

Complex Complex::difference(Complex c)
{
    Complex rez;
    rez.im = (c.im - im);
    rez.re = (c.re - re);
    return rez;
}

Complex Complex::multi(Complex c)
{
    Complex rez;
    rez.im = (c.im * im);
    rez.re = (c.re * re);
    return rez;
}

Complex Complex::div(Complex c)
{
    Complex rez;
    rez.im = (c.im / im);
    rez.re = (c.re / re);
    return rez;
}

int main()
{
    Complex c1, c2;
    int x, y;
    cout << "\tIntroduceti valorile pentru primul numar complex: ";
    cout << "\nPartea reala: "; cin >> x;
    cout << "Partea imaginara:"; cin >> y;
    c1.setRe(x);
    c1.setIm(y);
    
    cout << "\n\n\tIntroduceti valorile pentru al doilea numar complex: ";
    cout << "\nPartea reala: "; cin >> x;
    cout << "Partea imaginara:"; cin >> y;
    c2.setRe(x);
    c2.setIm(y);

    cout << "\n\nAdunam cele doua numere complexe: ";
    
    Complex rez;
    rez = c1.sum(c2);

    cout << "\nPartea reala este:" << rez.getRe();
    cout << "\nPartea imaginara este" << rez.getIm();

    cout << "\n\Scadem cele doua numere complexe: ";

    rez = c1.difference(c2);

    cout << "\nPartea reala este:" << rez.getRe();
    cout << "\nPartea imaginara este" << rez.getIm();

    cout << "\n\Inmultim cele doua numere complexe: ";

    rez = c1.multi(c2);

    cout << "\nPartea reala este:" << rez.getRe();
    cout << "\nPartea imaginara este" << rez.getIm();

    cout << "\n\Impartim cele doua numere complexe: ";

    rez = c1.div(c2);

    cout << "\nPartea reala este:" << rez.getRe();
    cout << "\nPartea imaginara este" << rez.getIm();


}

