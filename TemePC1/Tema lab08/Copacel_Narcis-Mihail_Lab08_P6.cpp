// Copacel_Narcis-Mihail_Lab08_P6.cpp 


#include <iostream>
#include <math.h>
using namespace std;

#define Pi 3.14

class Punct
{
private:
    int x, y;
public:
    Punct()
    {
        x = 0;
        y = 0;
    }
    Punct(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    friend class Operatii;
};

class Operatii
{
public:
    float Arie(Punct p1,Punct p2,int  i)
    {
        switch (i)
        {
        case 1: return Pi * sqrt((float)(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2))); break;
        case 2:
        {
            Punct p3(p1.x, p2.y);
            float a, b;
            a = sqrt((float)(pow((p3.x - p2.x), 2)));
            b = sqrt((float)(pow((p3.y - p1.y), 2)));
            return (a * b) / 2;
        }break;
        default:
            cout << "Nu ati introdus nici o figura!!!"; break;
        }
        
    }

    float Perimetru(Punct p1, Punct p2, int i)
    {
        switch (i)
        {
        case 1: return 2 * Pi * sqrt((float)(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2))); break;
        case 2: 
        {
            Punct p3;
            float a, b,c;
            a = sqrt((float)(pow((p3.x - p2.x), 2)));
            b = sqrt((float)(pow((p3.y - p1.y), 2)));
            c = sqrt((float)(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
            return a + b + c;
        }
        default:
            cout << "Nu ati introdus nici o figura!!!";
            break;
        }

    }
};

int main()
{
    Operatii p;
    Punct P0(1, 1), P1(2, 2);
    cout << "Introduceti figura(1=Cerc/2=Triunghi dreptunghic): ";
    int i;
    cin >> i;
    cout << "\nPentru figura " << i << " Aria este egala cu: " << p.Arie(P0, P1, i) << " si Perimetrul este egal cu " << p.Perimetru(P0, P1, i);

}
