// Copacel_Narcis-Mihail_Lab06_P7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
using namespace std;

class Seif
{
    int cifru;
    float suma;
    float getSuma() { return suma; }
    void setSuma(float suma) { this->suma = suma; }

public:
    Seif(int cifru, float suma)
    {
        this->cifru = cifru;
        this->suma = suma;
    }
    void puneInSeif(float suma, int cifru);
    void scoateDinSeif(float suma, int cifru);

};

void Seif::puneInSeif(float suma, int cifru) 
{ 
    if (this->cifru != cifru)
        cout << "\n\n\t\tCifru incorect!!!!";
    else
    {
        setSuma(suma + getSuma());
        cout << "\nNoua suma din seif este: " << getSuma();
    
    }

}

void Seif::scoateDinSeif(float suma, int cifru) 
{ 
    if (this->cifru != cifru)
        cout << "\n\n\t\tCifru incorect!!!!";
    else
    {
        setSuma(getSuma() - suma);
        cout << "\nNoua suma din seif este: " << getSuma();
    }

}

int main()
{
    int cifru;
    float suma;
    cout << "\t\tIntroduceti datele seifului: ";
    cout << "\nIntroduceti cifrul seifului: "; cin >> cifru;
    cout << "\nIntroduceti suma din seif: "; cin >> suma;
    Seif s(cifru, suma);
    char k;
    cout << "\nDoriti sa scoateti sau sa puneti bani in seif:(p=pun/s=scot) ";
    k = _getch();
    if (k == 'p' || k == 'P')
    {
        int cifru;
        cout << "\nCe suma doriti sa depuneti?\n";
        cin >> suma;
        cout << "\nIntroduceti cifrul.\n";
        cin >> cifru;
        s.puneInSeif(suma, cifru);
    }
    else
        if (k == 's' || k == 'S')
        {
            int cifru;
            cout << "\nCe suma doriti sa scoateti?\n";
            cin >> suma;
            cout << "\nIntroduceti cifrul.\n";
            cin >> cifru;
            s.scoateDinSeif(suma, cifru);
        }
}

