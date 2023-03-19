// Copacel_Narcis-Mihail_Lab11_P7.cpp

#include <iostream>
#include <math.h>
using namespace std;


class Punct
{
    int x, y;
public:
    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    int GetX()
    {
        return x;
    }

    int GetY()
    {
        return y;
    }
};

class PatrulaterAbstract
{
protected:
    Punct a, b, c, d;
public:
    virtual void Aria() = 0;
    virtual void Perimetru() = 0;

};

class PatrulaterConcret :public PatrulaterAbstract
{
public:
    char Det()
    {
        float A, B, C, D;
        A = sqrt(pow(c.GetX() - d.GetX(), 2) + pow(c.GetY() - d.GetY(), 2));
        B = sqrt(pow(d.GetX() - a.GetX(), 2) + pow(d.GetY() - a.GetY(), 2));
        C = sqrt(pow(b.GetX() - a.GetX(), 2) + pow(b.GetY() - a.GetY(), 2));
        D = sqrt(pow(c.GetX() - b.GetX(), 2) + pow(c.GetY() - b.GetY(), 2));

        if (A == C && B == D)
            return 'd';
        else
            if (A == B == C == D)
                return 'P';
            else
                return 'p';
    }

    void setCoordonate()
    {
        int x, y;
        cout << "\nCoordonatele primului punct: ";
        cin >> x >> y;
        a.setX(x);
        a.setY(y);
        cout << "\nCoordonatele celui de al doilea punct: ";
        cin >> x >> y;
        b.setX(x);
        b.setY(y);
        cout << "\nCoordonatele celui de al treilea punct: ";
        cin >> x >> y;
        c.setX(x);
        c.setY(y);
        cout << "\nCoordonatele celui de al patrulea punct: ";
        cin >> x >> y;
        d.setX(x);
        d.setY(y);
    }

    void Aria() override
    {
        float A, B, C, D;
        A = sqrt(pow(c.GetX() - d.GetX(), 2) + pow(c.GetY() - d.GetY(), 2));
        B = sqrt(pow(d.GetX() - a.GetX(), 2) + pow(d.GetY() - a.GetY(), 2));
        C = sqrt(pow(b.GetX() - a.GetX(), 2) + pow(b.GetY() - a.GetY(), 2));
        D = sqrt(pow(c.GetX() - b.GetX(), 2) + pow(c.GetY() - b.GetY(), 2));
        
        char cont = Det();

        switch (cont)
        {
        case 'P':
            cout << "\n\tAria patratului este egala cu: " << A * B;
            break;
        case 'd':
            cout << "\n\tAria dreptunghiului este egala cu: " << A * B;
            break;
        case 'p':
            float s, p, q,Aria;
            s = (A + B + C + D) / 2;
            p = sqrt(pow(A, 2) + pow(B, 2));
            q= sqrt(pow(C, 2) + pow(D, 2));
            Aria = sqrt((s - A) * (s - B) * (s - C)*(s - D) - (1 / 4) * (A * C + B * D + p * q) * (A * C + B * D - p * q));
            cout << "\n\tAria patrulaterului este egala cu: "<<A;
            break;
                      
        }
    }

    void Perimetru() override
    {
        float A, B, C, D;
        A = sqrt(pow(c.GetX() - d.GetX(), 2) + pow(c.GetY() - d.GetY(), 2));
        B = sqrt(pow(d.GetX() - a.GetX(), 2) + pow(d.GetY() - a.GetY(), 2));
        C = sqrt(pow(b.GetX() - a.GetX(), 2) + pow(b.GetY() - a.GetY(), 2));
        D = sqrt(pow(c.GetX() - b.GetX(), 2) + pow(c.GetY() - b.GetY(), 2));

        char cont = Det();

        switch (cont)
        {
        case 'P':
            cout << "\n\tPerimetrul patratului este egal cu: " << 4*A;
            break;
        case 'd':
            cout << "\n\tPerimetrul dreptunghiului este egala cu: " << 2*(A+B);
            break;
        case 'p':
            
            cout << "\n\tPerimetrul patrulaterului este egala cu: " << A+B+C+D;
            break;
        }
    }
};

int main()
{
    PatrulaterConcret p;
    
    cout << "Introduceti coordonatele punctelor: ";
    p.setCoordonate();

    p.Aria();
    p.Perimetru();
    
    
}

