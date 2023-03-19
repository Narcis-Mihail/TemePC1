// Copacel_Narcis-Mihail_Lab09_P11.cpp 

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
        cout << a << "/" << b;
    }

    ~Fractie()
    {
        
        icount--;
    }

    Fractie operator+=(Fractie& f);
    Fractie operator-=(Fractie& f);
    Fractie operator*=(Fractie& f);
    Fractie operator/=(Fractie& f);
    Fractie operator++();
    Fractie operator--();
    Fractie operator=(Fractie& f);
    Fractie operator++(int);
    Fractie operator--(int);
   

    void simplifica();

    /*friend Fractie operator+(Fractie& obj1, Fractie& obj2);
    friend Fractie operator-(Fractie& obj1, Fractie& obj2);
    friend Fractie operator*(Fractie& obj1, Fractie& obj2);
    friend Fractie operator/(Fractie& obj1, Fractie& obj2);*/
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

//Fractie operator+(Fractie& obj1, Fractie& obj2)
//{
//    Fractie rez;
//    if (obj1.b != obj2.b)
//    {
//        rez.a = obj1.a * obj2.b + obj1.b * obj2.a;
//        rez.b = obj1.b * obj2.b;
//        rez.simplifica();
//        return rez;
//    }
//    else
//    {
//        rez.a = obj1.a + obj2.a;
//        rez.setNumitor(obj1.b);
//        rez.simplifica();
//        return rez;
//    }
//}
//
//Fractie operator-(Fractie& obj1, Fractie& obj2)
//{
//    Fractie rez;
//    if (obj1.b != obj2.b)
//    {
//        rez.setNumarator(obj1.a * obj2.b - obj1.b * obj2.a);
//        rez.setNumitor(obj1.b * obj2.b);
//        rez.simplifica();
//        return rez;
//    }
//    else
//    {
//        rez.setNumarator(obj1.a - obj2.a);
//        rez.setNumitor(obj1.b);
//        rez.simplifica();
//        return rez;
//    }
//}
//
//Fractie operator*(Fractie& obj1, Fractie& obj2)
//{
//    Fractie rez;
//    rez.a = obj1.a * obj2.a;
//    rez.b = obj1.b * obj2.b;
//    rez.simplifica();
//    return rez;
//}
//
//Fractie operator/(Fractie& obj1, Fractie& obj2)
//{
//    Fractie rez;
//    rez.a = obj1.a * obj2.b;
//    rez.b = obj1.b * obj2.a;
//    rez.simplifica();
//    return rez;
//}

Fractie Fractie::operator+=(Fractie& f)
{
    if (b != f.b)
    {
        a = a * f.b + b * f.a;
        b = b * f.b;
        this->simplifica();
        return *this;
    }
    else
    {
        a = a + f.a;
        this->simplifica();
        return *this;
    }

}

Fractie Fractie::operator-=(Fractie& f)
{
    if (b != f.b)
    {
        a = a * f.b - b * f.a;
        b = b * f.b;
        this->simplifica();
        return *this;
    }
    else
    {
        a = a - f.a;
        this->simplifica();
        return *this;
    }
}

Fractie Fractie::operator*=(Fractie& f)
{
    Fractie rez;
    a = a * f.a;
    b = b * f.b;
    this->simplifica();
    return *this;
}

Fractie Fractie::operator/=(Fractie& f)
{
   
    a = a * f.b;
    b = b * f.a;
    this->simplifica();
    return *this;
   
}

Fractie Fractie::operator++()
{
    a = a + b;
    return *this;
}

Fractie Fractie::operator++(int)
{
    Fractie t;

    a = a + b;

    return t;

}

Fractie Fractie::operator--()
{
    a = a - b;
    return *this;
}

Fractie Fractie::operator--(int)
{
    Fractie t;

    a = a - b;

    return t;

}

Fractie Fractie::operator=(Fractie& f)
{
    a = f.a;
    b = f.b;
    return *this;
}

int main()
{
    Fractie f1[2];
    cout << "\tIntroduceti doua fractii de la tastatura: \n";
    for (int i = 0; i < 2; i++)
    {
        int a, b;
        cout << "Introduceti fractia " << i+1 << " :";
        cin >> a >> b;
        f1[i].setNumarator(a);
        f1[i].setNumitor(b);
    }

    Fractie f2[2];
    
    cout << "\n\tRealizam o copie a fractiilor.";

    for (int i = 0; i < 2; i++)
        f2[i] = f1[i];
  
    Fractie fo[4];

    cout << "\n\tEfectuam operatiile compuse.\n";
    Fractie fS,fs,finm,fimp;
    
    f2[0] += f2[1];
    fS = f2[0];
    f2[0] -= f1[0];

    f2[0] -= f2[1];
    fs = f2[0];
    f2[0] += f2[1];

    f2[0] *= f2[1];
    finm = f2[0];
    f2[0] /= f1[0];

    f2[0] /= f2[1];
    fimp = f2[0];
    f2[0] *= f2[1];

    cout << "\tRezultatele operatiilor sunt: \n";

    cout << "Suma: "; fS.displayFractie();
    cout << "\nScaderea: "; fs.displayFractie();
    cout << "\nInmultirea: "; finm.displayFractie();
    cout << "\nImpartirea: "; fimp.displayFractie();

    cout << "\n\tPrimele 2 rezultate dupa incrementare postfixata: \n";
    fS++;
    cout << "Suma: "; fS.displayFractie();
    fs++;
    cout << "\nScaderea: "; fs.displayFractie();
    
    cout << "\n\tUltimele 2 rezultate dupa incrementare prefixata: \n";

    ++finm;
    cout << "Inmultirea: "; finm.displayFractie();
    ++fimp;
    cout << "\nImpartirea: "; fimp.displayFractie();

    fS--;
    fs--;
    finm--;
    fimp--;

    cout << "\n\tPrimele 2 rezultate dupa decrementare postfixata: \n";
    fS--;
    cout << "Suma: "; fS.displayFractie();
    fs--;
    cout << "\nScaderea: "; fs.displayFractie();


    cout << "\n\tUltimele 2 rezultate dupa decrementare prefixata: \n";

    --finm;
    cout << "Inmultirea: "; finm.displayFractie();
    --fimp;
    cout << "\nImpartirea: "; fimp.displayFractie();
}