// Copacel_Narcis-Mihail_Lab08_P10.cpp 

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
        cout << endl << a << "/" << b;
    }

    ~Fractie()
    {
        cout << endl;
        cout <<"Apelare desctructor. "<< icount;
        icount--;
    }
    void simplifica();
    friend Fractie operator+(Fractie& obj1, Fractie& obj2);
    friend Fractie operator-(Fractie& obj1, Fractie& obj2);
    friend Fractie operator*(Fractie& obj1, Fractie& obj2);
    friend Fractie operator/(Fractie& obj1, Fractie& obj2);
};

int Fractie::icount;

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

Fractie operator+(Fractie& obj1, Fractie& obj2)
{
    Fractie rez;
    if (obj1.b != obj2.b)
    {
        rez.a = obj1.a * obj2.b + obj1.b * obj2.a;
        rez.b = obj1.b * obj2.b;
        rez.simplifica();
        return rez;
    }
    else
    {
        rez.a = obj1.a + obj2.a;
        rez.setNumitor(obj1.b);
        rez.simplifica();
        return rez;
    }
}

Fractie operator-(Fractie& obj1, Fractie& obj2)
{
    Fractie rez;
    if (obj1.b != obj2.b)
    {
        rez.setNumarator(obj1.a * obj2.b - obj1.b * obj2.a);
        rez.setNumitor(obj1.b * obj2.b);
        rez.simplifica();
        return rez;
    }
    else
    {
        rez.setNumarator(obj1.a - obj2.a);
        rez.setNumitor(obj1.b);
        rez.simplifica();
        return rez;
    }
}

Fractie operator*(Fractie &obj1, Fractie& obj2)
{
    Fractie rez;
    rez.a = obj1.a * obj2.a;
    rez.b = obj1.b * obj2.b;
    rez.simplifica();
    return rez;
}

Fractie operator/(Fractie& obj1, Fractie& obj2)
{
    Fractie rez;
    rez.a = obj1.a * obj2.b;
    rez.b = obj1.b * obj2.a;
    rez.simplifica();
    return rez;
}

int main()
{
    int a, b;
    Fractie f[6];
    cout << "\tIntroduceti doua fractii: ";
    for (int i = 0; i < 2; i++)
    {
        cout << "\nIntroduceti numaratorul: ";
        cin >> a;
        f[i].setNumarator(a);
        cout << "\nIntroduceti numitorul: ";
        cin >> b;
        f[i].setNumitor(b);


    }
    
    cout << "\n\tSupraincarcam operatorul +: \n";
    f[2] = f[0] + f[1];
    f[2].displayFractie();

    cout << "\n\tSupraincarcam operatorul -: \n";
    f[3] = f[0] - f[1];
    f[3].displayFractie();

    cout << "\n\tSupraincarcam operatorul *: \n";
    f[4] = f[0] * f[1];
    f[4].displayFractie();

    cout << "\n\tSupraincarcam operatorul /: \n";
    f[5] = f[0] / f[1];
    f[5].displayFractie();
}

