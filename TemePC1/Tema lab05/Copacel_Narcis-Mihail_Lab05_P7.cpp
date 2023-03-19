// Copacel_Narcis-Mihail_Lab05_P7.cpp : 

#include <iostream>
using namespace std;

class Aritmetica
{
    float a, b;
public:
    void setNr(float x, float y) { a = x; b = y; }
    float getNr(float x) { return x; }
    float suma() { return getNr(a + b); }
    float diferenta();
};

float Aritmetica::diferenta()
{
    return getNr(a - b);
}

int main()
{
    Aritmetica o1, o2, o3;
    float x, y;
    cout << "\tIntroduceti valorile pentru primul obiect: ";
    cin >> x >> y;
    o1.setNr(x, y);
    cout << "Suma atributelor primului obicet este: " << o1.suma();
    cout << "\nDiferenta atributelor primului obicet este: " << o1.diferenta();

    cout << "\n\n\tIntroduceti valorile pentru primul obiect: ";
    cin >> x >> y;
    o2.setNr(x, y);
    cout << "Suma atributelor primului obicet este: " << o2.suma();
    cout << "\nDiferenta atributelor primului obicet este: " << o2.diferenta();

    cout << "\n\n\tIntroduceti valorile pentru primul obiect: ";
    cin >> x >> y;
    o3.setNr(x, y);
    cout << "Suma atributelor primului obicet este: " << o3.suma();
    cout << "\nDiferenta atributelor primului obicet este: " << o3.diferenta();
    
}

