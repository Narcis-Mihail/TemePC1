// Copacel_Narcis-Mihail_Lab10_p7.cpp 

#include <iostream>
#include <math.h>
using namespace std;

#define Pi 3.14

class Cerc
{
protected:
    int raza;
public:
    Cerc(int r)
    {
        raza = r;
    }
    float ariaC()
    {
        return Pi * pow(raza, 2);
    }
};

class Patrat
{
protected:
    int lat;
public:
    Patrat(int lat)
    {
        this->lat = lat;
    }
    float ariaP()
    {
        return pow(lat, 2);
    }
};

class CercPatrat : public Cerc, public Patrat
{
public:
    CercPatrat(int r, int lat) :Cerc(r), Patrat(lat) {}
    float perimetruC()
    {
        return 2 * Pi * raza;
    }
    int perimetruP()
    {
        return 4 * lat;
    }
    bool includere()
    {
        bool b1;
        b1 = 2 * raza >= lat * sqrt(2);
        return b1;
    }
};


int main()
{
    int raza, lat;
    cout << "Introduceti raza cercului: ";
    cin >> raza;
    cout << "Introduceti latura patratului: ";
    cin >> lat;
    CercPatrat obj(raza, lat);

    cout << "\nAria cercului este egala cu: " << obj.ariaC() << endl << "Aria patratului este egala cu: " << obj.ariaP()<<endl;
    cout << "Perimetrul cercului este egal cu: " << obj.perimetruC() << endl << "Perimetrul patratului este egal cu: " << obj.perimetruP();

    if (obj.includere())
    
        cout << "\n\tPatratul poate fi introdus in cerc!";
    else
        cout << "\n\tPatratul poate fi introdus in cerc!";
}

