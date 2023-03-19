// Copacel_Narcis-Mihail_Lab06_P6.cpp 

#include <iostream>
#include <math.h>
using namespace std;

class Triunghi 
{
    float a, b, c;
public:
    Triunghi(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->valid();
    }
    void getLaturi();
    void ModificLat(float lat);
    float calcArie();
    float calcPerimetru();
    void IfDrept();
    int valid();


};

int Triunghi::valid()
{
    if (a < b + c && b < a + c && c < a + b)
        cout << "\n\tEste valid!";
    else
    {
        cout << "\n\tTriunghiul nu este valid";
        return 1;
    }
}

void Triunghi::IfDrept()
{
    if (a > b && b > c)
    {
        if (pow(a, 2) == pow(b, 2) + pow(c, 2))
            cout << "\nTriunghiul este dreptunghic.";
    }
    else
        if (b > a && a > c)
        {
            if (pow(b, 2) == pow(a, 2) + pow(c, 2))
                cout << "\nTriunghiul este dreptunghic.";
        }
        else
            if (pow(c, 2) == pow(b, 2) + pow(a, 2))
                cout << "\nTriunghiul este dreptunghic.";
            else
                cout << "\nTriunghiul nu este dreptunghic.";
}

float Triunghi::calcArie()
{
    float p = (a + b + c) / 2;
    float Arie;
    Arie = sqrt(p * (p - a)*(p - b)*(p - c));
    return Arie;
}

float Triunghi::calcPerimetru()
{
    return a + b + c;
}

void Triunghi::ModificLat(float lat)
{
    char m;
    cout << "\n\tCe latura modificati?";
    cin >> m;
    if (m == 'a')
        a = lat;
    else
        if (m == 'b')
            b = lat;
        else
            c = lat;
    this->valid();
}

void Triunghi::getLaturi()
{
    cout << "\n\tLaturile triughiului sunt: ";
    cout << "\nLatura a: " << a;
    cout << "\nLatura b: " << b;
    cout << "\nLatura c: " << c;
}

int main()
{
    float a, b, c;
    cout << "Introduceti laturile: ";
    cin >> a >> b >> c;
    Triunghi t(a, b, c);
    float lat;
    cout << "\nIntroduceti dimensiunea laturii pe care doriti sa o modificati: ";
    cin >> lat;
    t.ModificLat(lat);
    cout << "\nPerimetrul este egal cu: " << t.calcPerimetru();
    cout << "\nAria triughiului este egala cu:" << t.calcArie();
    t.IfDrept();
    


}
