// Copacel_Narcis-Mihail_Lab07_P6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Complex {
    double re, im;
    char* nume;
public:
    Complex(double x = 1.0, double y = 1.0, const char* nume = "c") {
        int i = strlen(nume) + 1;
        this->nume = new char[i];
        strcpy(this->nume, nume);
        re = x;
        im = y;
    }

    Complex(const Complex* c)
    {
        int i = strlen(c->nume) + 1;
        this->nume = new char[i];
        strcpy(this->nume, c->nume);
        this->re = c->re;
        this->im = c->im;
       
    }
    //~Complex(void);
  
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

    void setNume(char* nume)
    {
        if (strlen(nume) > 15)
            cout << "\n\tNume prea lung!";
        else
            strcpy(this->nume, nume);
    }
    double getIm() {
        return im;
    }
    Complex ad_complex(Complex* c, int n)
    {
        Complex rez(0, 0, "Suma_c");
        for (int i = 0; i < n; i++)
        {
            rez.re += (c + i)->re;
            rez.im += (c + i)->im;
        }
        return rez;
    }

    Complex sc_complex(Complex* c, int n)
    {
        Complex rez(0, 0, "Scadere_c");
        rez.re += (c + 0)->re;
        rez.im += (c + 0)->im;
        for (int i = 1; i < n; i++)
        {
            rez.re -= (c + i)->re;
            rez.im -= (c + i)->im;
        }
        return rez;
    }

    Complex p_complex(Complex* c, int n)
    {
        Complex rez(0, 0, "Inmultire_c");
        for (int i = 0; i < n - 1; i++)
            for (int j = 1; j < n; j++)
            {
                rez.re *= (c + i)->re * (c + j)->re - (c + i)->im * (c + j)->im;
                rez.im *= (c + i)->re * (c + j)->im + (c + i)->im * (c + j)->re;
            }
        return rez;
    }
};

//Complex::~Complex()
//{
//    delete[] this->nume;
//    re = 0;
//    im = 0;
//}

int main()
{
    int n;
    cout << "\tIntroduceti cate numere complexe doriti sa adaugati(cel mult 10 numere):";
    cin >> n;
    Complex* z = new Complex[n];
    cout << "\n\tIntroduceti numerele complexe:\n";
    for (int i = 0; i < n; i++)
    {
        double re, im;
        char nume[15];
        cout << i + 1 << ": ";
        cout << "Numele: ";
        cin >> nume;
        (z + i)->setNume(nume);
        cout << "Partea reala: ";
        cin >> re;
        (z + i)->setRe(re);
        cout << "Partea imaginara: ";
        cin >> im;
        (z + i)->setIm(im);
    }

    cout << "\n\tCalculam suma numerelor complexe: ";
    Complex suma = suma.ad_complex(z, n);
    cout << suma.getRe() << "+" << suma.getIm()<<"i";

    cout << "\n\tScaderea nr. complexe: ";
    Complex sc = sc.sc_complex(z, n);
    cout << sc.getRe()  << sc.getIm() << "i";

    cout << "\n\tProdusul numerelor complexe:";
    Complex pr = pr.p_complex(z, n);
    cout << pr.getRe() << pr.getIm() << "i";

    return 0;

}