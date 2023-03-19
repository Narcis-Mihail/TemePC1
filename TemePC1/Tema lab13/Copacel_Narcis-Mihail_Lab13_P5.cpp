// Copacel_Narcis-Mihail_Lab13_P5.cpp 

#include <iostream>
#include <fstream>
using namespace std;

class Fractie
{
private:
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
        cout << "\nStergere obiect!\n";

    }

    Fractie operator+(Fractie&);
    Fractie operator-(Fractie&);
    Fractie operator*(Fractie&);
    Fractie operator/(Fractie&);


    friend ostream& operator<<(ostream& fout, Fractie obj);
    friend istream& operator>>(istream& fin, Fractie& obj);

    void simplifica();



};

Fractie Fractie::operator+(Fractie& obj2)
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

Fractie Fractie::operator-(Fractie& obj2)
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

Fractie Fractie::operator*(Fractie& obj2)
{
    Fractie rez;
    rez.a = a * obj2.a;
    rez.b = b * obj2.b;
    rez.simplifica();
    return rez;
}

Fractie Fractie::operator/(Fractie& obj2)
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



int main()
{
    Fractie f1, f2;
    int numr, numt;
    cout << "Introduceti prima fractie: ";
    cin >> numr>>numt;
    f1.setNumarator(numr);
    f1.setNumitor(numt);

    cout << "Introduceti a doua fractie: ";
    cin >> numr>> numt;
    f2.setNumarator(numr);
    f2.setNumitor(numt);

    cout << "\n\tFractiile initiale sunt: "<<f1<<" si "<<f2<<endl;

    cout << "\nIntroduceti 4 fractii: \n";
    Fractie calc[4],f[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "i+1: ";
        cin >> f[i];
    }
        


    for(int i=0;i<4;i++)
        switch (i+1)
        {
        case 1:
            calc[i] = f[0]+f[1];
            break;
        case 2:
            calc[i] = f[0] - f[1];
            break;
        case 3:
            calc[i] = f[2] * f[3];
            break;
        case 4:
            calc[i] = f[2] / f[3];
            break;
        }

    char numeF[10];
    cout << "\nIntroduceti numele fisierului: ";
    cin >> numeF;
    ofstream fout;
    fout.open(numeF, ios::out);

    if (!fout.is_open())
    {
        cout << "\n\t\tNu se poate deschide fisierul!!!";
        exit(1);
    }
    
    fout << "\tObiecte initiale: ";
    for (int i = 0; i < 4; i++)
        fout << f[i]<<" ";
    fout << "\n\tRezultatele obtinute: ";
    for (int i = 0; i < 4; i++)
        fout << calc[i] << " ";
    
    fout.close();
    return 1;

}

ostream& operator<<(ostream& fout, Fractie obj)
{
    fout << obj.a << "/" << obj.b ;
    return fout;
}

istream& operator>>(istream& fin, Fractie& obj)
{
    fin >> obj.a >> obj.b;
    return fin;
}
