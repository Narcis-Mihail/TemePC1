// Copacel_Narcis-Mihail_Lab09_P9.cpp 

#include <iostream>
using namespace std;

class Mathemathics;
class Number
{
    double nr;
public:
    Number() { nr = 0; }
    Number(double numar) { nr = numar; }
    double getNr() { return nr; }
    friend class Mathemathics;
};

class Mathemathics
{
    Number n;
public:
    Mathemathics(){}
    Mathemathics(double nr) { n.nr=nr; }
    double getNr()
    {
        return n.getNr();
    }
    Mathemathics operator+(Mathemathics& obj)
    {
        Mathemathics rez;
        rez = n.nr + obj.n.nr;
        return rez;
    }

    Mathemathics operator-(Mathemathics& obj)
    {
        Mathemathics rez;
        rez = n.nr - obj.n.nr;
        return rez;
    }

    Mathemathics operator*(Mathemathics& obj)
    {
        Mathemathics rez;
        rez = n.nr * obj.n.nr;
        return rez;
    }

    Mathemathics operator/(Mathemathics& obj)
    {
        Mathemathics rez;
        rez = n.nr / obj.n.nr;
        return rez;
    }
};

int main()
{
    cout << "\tIntantiem doua obiecte din clasa mathemathics: \n";
    Mathemathics m1(5),m2(3.2),m3;
    cout << "m1.nr= " << m1.getNr() << " si m2.n= " << m2.getNr();

    cout << "\n\tSupraincarcam operatorul + :\n ";
    m3 = m1 + m2;
    cout << m3.getNr();
    cout << "\n\tSupraincarcam operatorul - :\n ";
    m3 = m1 - m2;
    cout << m3.getNr();
    cout << "\n\tSupraincarcam operatorul * :\n ";
    m3 = m1 * m2;
    cout << m3.getNr();
    cout << "\n\tSupraincarcam operatorul / :\n ";
    m3 = m1 / m2;
    cout << m3.getNr();
}

