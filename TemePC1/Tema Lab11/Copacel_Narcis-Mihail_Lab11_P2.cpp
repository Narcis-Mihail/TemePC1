// Copacel_Narcis-Mihail_Lab11_P2.cpp 
#include <iostream>
using namespace std;

class Vehicul {
    int roti;
    float greutate;
public:
    virtual void mesaj() {
        cout << "Mesaj din clasa Vehicul\n";
    }

    virtual void setGreutate(float g)
    {
        greutate = g;
    }

    virtual float GetGreutate()
    {
        return greutate;
    }


};
class Automobil : public Vehicul {
    int incarcatura_pasageri;
public:
    void mesaj() override {
        cout << "Mesaj din clasa Automobil\n";
    }

    virtual float GetGreutate()
    {
        cout << "Greutatea Automobilului: ";
        return Vehicul::GetGreutate();
    }

    virtual void setGreutate(float g)
    {
        Vehicul::setGreutate(g);
        cout << "S-a setat greutatea Automobilului la valoarea " << GetGreutate() << endl;
    }

};
class Camion : public Vehicul {
    int incarcatura_pasageri;
    float incarcatura_utila;
public:
    int pasageri() {
        return incarcatura_pasageri;
    }
    virtual float GetGreutate()
    {
        cout << "Greutatea Camionului: ";
        return Vehicul::GetGreutate();
    }

    virtual void setGreutate(float g)
    {
        Vehicul::setGreutate(g);
        cout << "S-a setat greutatea Camionului la valoarea " << GetGreutate() << endl;
    }

};
class Barca : public Vehicul {
    int incarcatura_pasageri;
public:
    int pasegeri() {
        return incarcatura_pasageri;
    }
    void mesaj() override {
        cout << "Mesaj din clasa Barca\n";
    }

    virtual float GetGreutate()
    {
        cout << "Greutatea barcii: ";
        return Vehicul::GetGreutate();
    }

    virtual void setGreutate(float g)
    {
        Vehicul::setGreutate(g);
        cout << "S-a setat greutatea barcii la valoarea " << GetGreutate() << endl;
    }

};

int main()
{
    // apel direct, prin intermediul unor obiecte specificeVehicul monocicleta;
    Vehicul monocicleta;
    Automobil ford;
    Camion semi;
    Barca barca_de_pescuit;
    monocicleta.mesaj();
    ford.mesaj();
    semi.mesaj();//din Vehicul ca si CB
    barca_de_pescuit.mesaj();
    // apel prin intermediul unui pointer specific
    Vehicul* pmonocicleta;
    Automobil* pford;
    Camion* psemi;
    Barca* pbarca_de_pescuit;
    cout << "\n";
    pmonocicleta = &monocicleta;
    pmonocicleta->mesaj();
    pford = &ford;
    pford->mesaj();
    psemi = &semi;
    psemi->mesaj();//din CB
    pbarca_de_pescuit = &barca_de_pescuit;
    pbarca_de_pescuit->mesaj();
    // apel prin intermediul unui pointer catre un obiect al clasei de baza
    cout << "\n";
    pmonocicleta = &monocicleta;
    pmonocicleta->mesaj();//Vehicul
    pmonocicleta = &ford;//upcasting
    pmonocicleta->mesaj();//Automobil
    pmonocicleta = &semi;//upcasting
    pmonocicleta->mesaj();//Camion- Vehicul
    pmonocicleta = &barca_de_pescuit;//upcasting
    pmonocicleta->mesaj();//Barca
    return 0;

}

