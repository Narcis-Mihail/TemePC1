// Copacel_Narcis-Mihail_Lab11_P3.cpp

#include <iostream>
using namespace std;

class Militar
{
public:

    virtual void sunt_militar()
    {
        cout << "\nLucrez in cadrul armatei.";
    }
};

class Soldat : public Militar
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt soldat in cadrul armatei!";
    }

};

class Ofiter : public Militar
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt ofiter in cadrul armatei.";
    }
};

class Locotenent : public Ofiter
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt locotenent in cadrul armatei.";
    }
};

class Colonel : public Ofiter
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt Colonel in cadrul armatei.";
    }
};

class Capitan: public Ofiter
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt Capitan in cadrul armatei.";
    }
};

class General: public Ofiter
{
public:
    void sunt_militar() override
    {
        cout << "\nSunt General in cadrul armatei.";
    }
};

int main()
{
    Militar m;
    Soldat s;
    Ofiter o;
    Locotenent l;
    Colonel c;
    Capitan C;
    General g;

    m.sunt_militar();
    s.sunt_militar();
    o.sunt_militar();
    l.sunt_militar();
    c.sunt_militar();
    C.sunt_militar();
    g.sunt_militar();

    
    
}

