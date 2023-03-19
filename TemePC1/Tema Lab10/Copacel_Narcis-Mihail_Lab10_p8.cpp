// Copacel_Narcis-Mihail_Lab10_p8.cpp 

#include <iostream>
using namespace std;

class Fractie
{
protected:
    int a, b;

public:
    Fractie()
    {
        a = 0;
        b = 1;
        
    }
    Fractie(int numr, int numt)
    {
        if (numt != 0)
        {
            a = numr;
            b = numt;
        }
        else
            cout << "\n\t\tNumitorul este egal cu 0";
    }

    void setNumarator(int numr)
    {
        a = numr;
    }
    int getNumarator()
    {
        return a;
    }

    void setNumitor(int numt)
    {
        if (numt != 0)
            b = numt;
        else
            cout << "\n\t\tNumitorul este egal cu 0";
    }
    int getNumitor()
    {
        return b;
    }

    void displayFractie()
    {
        cout << a << "/" << b;
    }

    ~Fractie()
    {

        
    }

    Fractie operator+(Fractie&);
    Fractie operator-(Fractie&);
    Fractie operator*(Fractie&);
    Fractie operator/(Fractie&);
    
   


    void simplifica();

    
};

Fractie Fractie::operator+( Fractie& obj2)
{
    Fractie rez;
    if (b != obj2.b)
    {
        rez.a = a * obj2.b + b * obj2.a;
        rez.b = b * obj2.b;
        rez.simplifica();
        return rez;
    }
    else
    {
        rez.a = a + obj2.a;
        rez.setNumitor(b);
        rez.simplifica();
        return rez;
    }
}

Fractie Fractie::operator-( Fractie& obj2)
{
    Fractie rez;
    if (b != obj2.b)
    {
        rez.setNumarator(a * obj2.b - b * obj2.a);
        rez.setNumitor(b * obj2.b);
        rez.simplifica();
        return rez;
    }
    else
    {
        rez.setNumarator(a - obj2.a);
        rez.setNumitor(b);
        rez.simplifica();
        return rez;
    }
}

Fractie Fractie::operator*( Fractie& obj2)
{
    Fractie rez;
    rez.a = a * obj2.a;
    rez.b = b * obj2.b;
    rez.simplifica();
    return rez;
}

Fractie Fractie::operator/( Fractie& obj2)
{
    Fractie rez;
    rez.a = a * obj2.b;
    rez.b = b * obj2.a;
    rez.simplifica();
    return rez;
}

void Fractie::simplifica()
{
    int n = (a > b ? a : b);


    for (int i = 2; i <= n / 2; i++)
    {
        while (a % i == 0 && b % i == 0)
        {
            a = a / i;
            b = b / i;
        }
        if (a == 1 || b == 1)
            break;
    }
}

class Fractie_ext :public Fractie
{
public:
    Fractie_ext() :Fractie() {}
    Fractie_ext(int numr, int numt) :Fractie(numr, numt){}

    Fractie_ext operator++();
    Fractie_ext operator--();
};

Fractie_ext Fractie_ext::operator++()
{
    Fractie_ext t;

    t.a = a + b;
    t.b = b;

    return t;

}

Fractie_ext Fractie_ext::operator--()
{
    Fractie_ext t;

    t.a = a - b;
    t.b = b;
    return t;

}

int main()
{
    Fractie f1, f2;
    int numr, numt;
    /*cout << "Introduceti prima fractie: ";
    cin >> numr>>numt;
    f1.setNumarator(numr);
    f1.setNumitor(numt);

    cout << "Introduceti a doua fractie: ";
    cin >> numr, numt;
    f2.setNumarator(numr);
    f2.setNumitor(numt);

    Fractie calc[4];

    for(int i=0;i<4;i++)
        switch (i+1)
        {
        case 1:
            calc[i] = f1 + f2;
            cout << "\nSuma fractiilor este egala cu: ";
            calc[i].displayFractie();
            break;
        case 2:
            calc[i] = f1 - f2;
            cout << "\nDiferenta fractiilor este egala cu: ";
            calc[i].displayFractie();
            break;
        case 3:
            calc[i] = f1 * f2;
            cout << "\nInmultirea fractiilor este egala cu: ";
            calc[i].displayFractie();
            break;
        case 4:
            calc[i] = f1 / f2;
            cout << "\nImpartirea fractiilor este egala cu: ";
            calc[i].displayFractie();
            break;
        }*/
    cin.get();
    cout << "\n\tLucram acum cu clasa derivata: \n\n";
    Fractie_ext f_e1, f_e2;

    cout << "Introduceti prima fractie: ";
    cin >> numr >> numt;
    f_e1.setNumarator(numr);
    f_e1.setNumitor(numt);
    cin.get();
    cout << "Introduceti a doua fractie: ";
    cin >> numr, numt;
    f_e2.setNumarator(numr);
    f_e2.setNumitor(numt);

    Fractie_ext calc2[4];

    for (int i = 0; i < 4; i++)
        switch (i + 1)
        {
        case 1:
            calc2[i] = ++f_e1;
            
            cout << "\nIncrementarea primei fractii : ";
            calc2[i].displayFractie();
            break;
        case 2:
            calc2[i] = --f_e1;
            cout << "\nDecrementarea primei fractii: ";
            calc2[i].displayFractie();
            break;
        case 3:
            calc2[i] = ++f_e2;
            cout << "\nIncrementarea fractiei a doua: ";
            calc2[i].displayFractie();
            break;
        case 4:
            calc2[i] = --f_e2;
            cout << "\nDecrementarea fractiei a doua: ";
            calc2[i].displayFractie();
            break;
        }
}