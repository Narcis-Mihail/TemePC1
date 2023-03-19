// Copacel_Narcis-Mihail_Lab10_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Baza {
protected: int a, b;
public:
    Baza() { a = 1, b = 1; }
    void setA(int a) {
        this->a = a;
    }
    void setB(int b) {
        this->b = b;
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
    int aduna() {
        return a + b;
    }
    int scade() {
        return a - b;
    }
};
class Derivata : private Baza
{
public:
    int inmulteste() {
        return a * b;
    }

    int adunare()
    {
        return this->aduna();
    }

    int scadere()
    {
        return this->scade();
    }
};


int main()
{
    Baza obiect_baza;
    cout << "\nAfis din baza (val. initiale): " << obiect_baza.getA() << " " <<
        obiect_baza.getB() << '\n';
    cout << "\nSuma este (cu val. initiale, baza) = " << obiect_baza.aduna(); // corect aduna( ) e public
        cout << "\nDiferenta este (cu val. initiale, baza) = " << obiect_baza.scade();
    //corect scade( ) e public
    obiect_baza.setA(2);
    obiect_baza.setB(3);
    cout << "\nAfis din baza (modificat): " << obiect_baza.getA() << " " << obiect_baza.getB() << '\n';
    cout << "\nSuma/Diferenta dupa setare= " << obiect_baza.aduna() << "/" <<
        obiect_baza.scade() << '\n';
    Derivata obiect_derivat;
    cout << "\nProdusul este (din derivat cu val. initiale) = " << obiect_derivat.inmulteste() << '\n';
    // corect val. implicite
    cout << "\nSuma este (din derivat cu val. initiale, baza) = " << obiect_derivat.adunare( ); // incorect aduna() devine private
        cout<<"\nDiferenta este: "<<obiect_derivat.scadere( ); // eroare, scade( ) devine private+
        return 0;
}

