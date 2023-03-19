// Copacel_Narcis-Mihail_Lab11_P4.cpp

#include <iostream>
using namespace std;

class Animal
{
public:

    virtual void respira() = 0;

    virtual void mananca()
    {
        cout << "\nCe mananca de obicei?";
    }

    virtual void doarme()
    {
        cout << "\nCat doarme ?";
    }

};

class Caine :public Animal
{
public:
    void respira()
    {
        cout << "\nRespira prin plamani!";
    }

    void mananca()
    {
        cout << "\nMananca orice ii dai!";
    }
};

class Peste :public Animal
{
public:
    void respira()
    {
        cout << "\nRespira cu ajutorul branhiilor!";
    }

    void doarme()
    {
        cout << "\nDorm foarte putin!";
    }
};

void main()
{
    const int n = 2;
    Caine Patrocle;
    Patrocle.respira();
    Patrocle.mananca();
    cout << endl;

    Peste Nemo;
    Nemo.respira();
    Nemo.doarme();
    cout << endl;

    Animal* tab[n];
    tab[0] = new Caine;
    tab[1] = new Peste;

    for (int i = 0; i < n; i++)
    {
        tab[i]->doarme();
        tab[i]->mananca();
        tab[i]->respira();
    }
    delete[]tab;
}

