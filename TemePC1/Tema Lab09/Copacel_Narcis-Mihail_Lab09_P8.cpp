// Copacel_Narcis-Mihail_Lab09_P8.cpp 

#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    float img;
    float re;
public:
    Complex(void)
    {
        img = 0.;
        re = 0.;
    }
    Complex(float r, float i)
    {
        re = r;
        img = i;
    }

    Complex operator+(Complex obj);
   

    Complex operator-(Complex obj)
    {
        
        Complex rez;
        rez.re = re - obj.re;
        rez.img = re - obj.img;
        return rez;
    }

    void afisare()
    {
        cout << "\nPartea reala este: " << re;
        cout << "\nPartea imaginara este: " << img;
    }


    friend Complex operator*(Complex& , Complex&);
    friend Complex operator/(Complex&, Complex&);
};

Complex Complex::operator+(Complex obj)
{
    Complex rez;
    rez.re=re+ obj.re;
    rez.img = re+obj.img;
    return rez;
   
}

Complex operator*(Complex& obj1, Complex& obj2)
{
    Complex rez;
    rez.re = obj1.re * obj2.re+(obj1.img * obj2.img > 0 ? -obj1.img * obj2.img: obj1.img * obj2.img);
    rez.img = obj1.img * obj2.re + obj1.re * obj2.img;
    return rez;
}

Complex operator/(Complex& obj1, Complex& obj2)
{
    Complex rez;
    rez.re = (obj1.re * obj2.re + obj1.img * obj2.img) / (pow(obj2.re, 2) + pow(obj2.img, 2));
    rez.img = (obj2.re * obj1.img - obj1.re * obj2.img) / (pow(obj2.re, 2) + pow(obj2.img, 2));
    return rez;
}

int main()
{
    Complex z1(1, 1),z2(2,3),z3;
    z3 = z1 + z2; 
    cout << "\tSupraincarcam operatorul + : \n";
    z3.afisare();

    z3 = z1 - z2;
    cout << "\n\tSupraincarcam operatorul - : \n";
    z3.afisare();

    cout << "\n\tSupraincarcam operatoul * :\n";
    z3 = z1 * z2;
    z3.afisare();

    cout << "\n\tSupraincarcam operatorul /: \n";
    z3 = z1 / z2;
    z3.afisare();
}

