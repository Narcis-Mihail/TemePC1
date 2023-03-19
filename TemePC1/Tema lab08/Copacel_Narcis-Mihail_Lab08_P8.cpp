// Copacel_Narcis-Mihail_Lab08_P8.cpp :

#include <iostream>
using namespace std;

class Fractie
{
private:
    int a, b;
    static int icount;
public:
    Fractie()
    {
        a = 0;
        b = 1;
        icount++;
    }
    Fractie(int numr, int numt)
    {
        if (numt != 0)
        {
            a = numr;
            b = numt;
            icount++;
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
        if(numt!=0)
        a = numt;
        else
            cout << "\n\t\tNumitorul este egal cu 0";
    }
    int getNumitor()
    {
        return b;
    }

    ~Fractie()
    {
        cout << endl;
        cout << icount;
        icount--;
    }
    friend void simplifica(Fractie& x);
    friend Fractie _f_aduna_fractie(Fractie& x,Fractie &y);
    friend Fractie _f_scade_fractie(Fractie& x, Fractie& y);
    friend Fractie _f_inmultire_fractie(Fractie& x, Fractie& y);
    friend Fractie _f_impartire_fractie(Fractie& x, Fractie& y);

};

int Fractie::icount;

void simplifica(Fractie& x);
Fractie _f_aduna_fractie(Fractie& x, Fractie& y);
Fractie _f_scade_fractie(Fractie& x, Fractie& y);
Fractie _f_inmultire_fractie(Fractie& x, Fractie& y);
Fractie _f_impartire_fractie(Fractie& x, Fractie& y);

int main()
{
    int a, b;
    
    cout << "Introduceti prima fractie: ";
    cin >> a >> b;
    Fractie f1(a, b);

    cout << "Introduceti a doua fractie: ";
    cin >> a >> b;
    Fractie f2(a, b);
    
    cout << "Simplificam fractia: ";
    simplifica(f1);
    simplifica(f2);

    Fractie Ad = _f_aduna_fractie(f1, f2);
    Fractie Sc = _f_scade_fractie(f1, f2);
    Fractie Imn = _f_inmultire_fractie(f1, f2);
    Fractie Imp = _f_impartire_fractie(f1, f2);

    cout << "\nSuma este egala cu: " << Ad.getNumarator() << "/" << Ad.getNumitor();
    cout << "\nDiferenta este egala cu: " << Sc.getNumarator() << "/" << Sc.getNumitor();
    cout << "\nInmultirea este egala cu: " << Imn.getNumarator() << "/" << Imn.getNumitor();
    cout << "\nImpartirea este egala cu: " << Imp.getNumarator() << "/" << Imp.getNumitor();
}

void simplifica(Fractie& x)
{
    int n = (x.a > x.b ? x.a : x.b);


    for (int i = 2; i <= n / 2; i++)
    {
        while (x.a % i == 0 && x.b % i == 0)
        {
            x.a = x.a / i;
            x.b = x.b / i;
        }
        if (x.a == 1 || x.b == 1)
            break;
    }

}

Fractie _f_aduna_fractie(Fractie& x, Fractie& y)
{
    Fractie rez;
    if (x.b != y.b)
    {
        rez.a = x.a * y.b + x.b * y.a;
        rez.b = x.b * y.b;
        return rez;
    }
    else
    {
        rez.a = x.a + y.a;
        return rez;
    }
}

Fractie _f_scade_fractie(Fractie& x, Fractie& y)
{
    Fractie rez;
    if (x.b != y.b)
    {
        rez.a = x.a * y.b - x.b * y.a;
        rez.b = x.b * y.b;
        return rez;
    }
    else
    {
        rez.a = x.a - y.a;
        return rez;
    }
}

Fractie _f_inmultire_fractie(Fractie& x, Fractie& y)
{
    Fractie rez;
    rez.a = x.a * y.a;
    rez.b = x.b * y.b;
    simplifica(rez);
    return rez;
}

Fractie _f_impartire_fractie(Fractie& x, Fractie& y)
{
    Fractie rez;
    rez.a = x.a * y.b;
    rez.b = x.b * y.a;
    simplifica(rez);
    return rez;
}