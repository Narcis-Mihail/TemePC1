// Copacel_Narcis-Mihail_Lab05_P4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Numar
{
    int val;

public:
    int suma_nr(Numar nr1,Numar nr2) { return nr1.val + nr2.val; }
    void setVal(int x) { val = x; }
    void nr_suma(Numar nr1, Numar nr2);
    void AfisVal() { cout << val; }
};

void Numar::nr_suma(Numar nr1, Numar nr2)
{
    val=nr1.val + nr2.val;
}

int main()
{
    Numar s,nr1,nr2;
    Numar* p;
    p = &s;
    int x, y;
    cout << "Introduceti valoarea primului numar: "; cin >> x;
    p->setVal(x);
    cout << "Introduceti valoarea celui de al doilea numar: "; cin >> y;
    nr2.setVal(y);

    cout << p->suma_nr(s, nr2)<<"\n";
   
    cout << "Introduceti valoarea primului numar: "; cin >> x;
    p->setVal(x);
    cout << "Introduceti valoarea celui de al doilea numar: "; cin >> y;
    nr2.setVal(y);

    p->nr_suma(s, nr2);
    p->AfisVal();
    
    
}
