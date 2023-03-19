// Copacel_Narcis-Mihail_Lab11_P1.cpp 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Pozitie {
protected:
    int x, y;
public:
    Pozitie(int = 0, int = 0);
    Pozitie(const Pozitie&);//exista unul implicit standard, aici unul diferit
    ~Pozitie();
    //void afisare();
    //void deplasare(int, int);
    virtual void afisare();
    virtual void deplasare(int, int);
};//CB

  // constructor
Pozitie::Pozitie(int abs, int ord) {
    x = abs; y = ord;
    cout << "Constructor CB \"Pozitie\", ";
    afisare();
}

//constructor de copiere
Pozitie::Pozitie(const Pozitie& p) {
    x = p.x;
    y = p.y;
    cout << "Constructor de copiere CB \"Pozitie\", ";
    afisare();
}

// destructor
Pozitie::~Pozitie() {
    cout << "Destructor CB \"Pozitie \", ";
    afisare();
}
void Pozitie::afisare() {
    cout << " CB afisare: coordonate: x = " << x << ", y = " << y << "\n";
}

void Pozitie::deplasare(int dx, int dy) 
{
    cout << "CB: deplasare" << endl;
    x += dx; y += dy;
}

// clasa derivata Cerc
class Cerc : public Pozitie
{
    int raza;
public:
    Cerc(int raza, int x, int y) :Pozitie(x, y)
    {
        this->raza = raza;
    }

    void afisare() override;
    void deplasare(int ,int) override;
    ~Cerc()
    {
        cout << "Destructor CC \"Cerc\", ";
        this->afisare();
    }


};

void Cerc::deplasare(int dx, int dy)
{
        cout << " \nCC: Deplasare afisare CC\n";
        x += dx;
        y += dy;
        afisare();
   
}


void Cerc::afisare()
{
    cout << "\nPozitie: x = " << x << ", y = " << y;
    cout << "\nRaza cercului este egala cu: " << raza;
}


// clasa derivata
class Punct : public Pozitie {
    int vizibil;//ca un flag
    char culoare;
public:
    Punct(int = 0, int = 0, char = 'A');
    Punct(const Punct&);
    ~Punct();
    void arata() {
        vizibil = 1;
    }
    void ascunde() {
        vizibil = 0;
    }
    void coloreaza(char c) {
        culoare = c;
    }
    void deplasare(int, int) override;
    void afisare() override;
};//CD
// constructor
Punct::Punct(int abs, int ord, char c) :Pozitie(abs, ord) {
    vizibil = 0;
    culoare = c;
    cout << "Constructor CD \"Punct\", ";
    afisare();//CD
}
// constructor de copiere
Punct::Punct(const Punct& p) :Pozitie(p.x, p.y) {
    vizibil = p.vizibil;
    culoare = p.culoare;
    cout << "Constructor de copiere CD \"Punct\", ";
    afisare();//CD
}
// destructor
Punct::~Punct() {
    cout << "Destructor CD \"Punct\", ";
    afisare();//CD
}
// redefinire functie de deplasare in clasa derivata
void Punct::deplasare(int dx, int dy) 
{
    if (vizibil) {
        cout << " CD: Deplasare afisare CD\n";
        x += dx;
        y += dy;
        afisare();//CD
    }
    else {
        x += dx;
        y += dy;
        cout << "Deplasare prin CD afisare din CB\n"; Pozitie::afisare();
    }
}
// redefinire metoda de afisare in clasa derivata
void Punct::afisare() 
    {
        cout << "Pozitie: x = " << x << ", y = " << y;
        cout << ", culoare: " << culoare;
        if (vizibil) cout << ", vizibil \n";
        else cout << ", invizibil \n";
    }

// program de test

int main() 
{
    Pozitie pp0(7, 7);//base class object

    cout << "\n Metode CB \n";
    pp0.afisare();
    pp0.deplasare(6, 9);
    pp0.afisare();
    cout << "\n Metode CD \n";
    Punct p0(1, 1, 'V');//derived class object
        p0.afisare();
    Punct p1(p0);
    p1.arata();
    p1.deplasare(10, 10);
    cout << "\nUpcasting - obiecte:\n";
    pp0 = p0;//upcasting by objects
    pp0.afisare();
    cout << "\nUpcasting - pointeri:\n ";
    Pozitie * p;//base class pointer
    p = new Punct(100, 100, 'Z');//derived object to the base class pointer
    //cout<<"\nAfisare CB: \n"; non virtual
    cout << "\nAfisare CD: derived class object if virtual, else base class CB \n";
    p->afisare();//afis invizibil
    p = &pp0;
    cout << "\nAfisare CB: base class object always\n";
    p->afisare();
    p = &p1;
    cout << "\nAfisare CD: derived class object if virtual, else base class CB \n";
    p->afisare();
    Punct * pp;
    pp = &p1;
    cout << "\nAfisare CD: derived class object always\n";
    pp->afisare();
    cout << "\n Deplasare CD with 10, 10 \n";
    pp->deplasare(10, 10);
    cout << "\nAfisare CD: derived class object with ascunde()\n";
    pp->ascunde();
    pp->afisare();
    cout << "\n Deplasare CD with 10, 10 and ascunde()\n";
    pp->deplasare(10, 10);
    cout << "\nAfisare direct from CB: derived object displayed with base class method always\n";
    pp->Pozitie::afisare();
    cout << "\nDowncasting:\n ";
    Punct * pdown;//derived pointer
    pdown = (Punct*)&pp0;//downcasting by base class object
    cout << "\nAfisare CB: base class object using a derived pointer, else derived class CD \n"; pdown->afisare();
    pdown = (Punct*)p;//downcasting by derived class object
    cout << "\n Afisare din Derivat, Punct" << endl;
    pdown->afisare();

    cout << "\n\n";
    Cerc c(5, 1, 1);
    cout << "Metode CC: \n";
    c.afisare();
    c.deplasare(2, -1);
    c.afisare();


    return 0;
}

