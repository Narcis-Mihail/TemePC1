// Copacel_Narcis-Mihail_Lab08_P1.cpp : 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

class OraCurenta
{
    int ora, minut, secunda;
public:
    void setOra(int n)
    {
        ora = n;
    }
    void setMinut(int n)
    {
        minut = n;
    }
    void setSecunda(int n)
    {
        secunda = n;
    }
    int getOra()
    {
        return ora;
    }
    int getMinut()
    {
        return minut;
    }
    int getSecunda()
    {
        return secunda;
    }

    friend OraCurenta Copy(OraCurenta x);
};

OraCurenta Copy(OraCurenta x);
void getOraCurenta(int &h, int &m, int &s);

int main()
{
    int h=0, m=0, s=0;
    OraCurenta x;
    cout << "Se preia timpul curent al calculatorului.";
    getOraCurenta(h, m, s);
    x.setOra(h);
    x.setMinut(m);
    x.setSecunda(s);
    OraCurenta GMT;
    GMT = Copy(x);
    cout << "\nOra curenta in GMT este: " << GMT.getOra() << ":" << GMT.getMinut() << ":" << GMT.getSecunda();
}

OraCurenta Copy(OraCurenta x)
{
    OraCurenta rez;
    rez.setOra(x.ora - 3);
    rez.setMinut(x.minut);
    rez.setSecunda(x.secunda);
    return rez;
}

void getOraCurenta(int &h, int &m, int &s)
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    h = timeinfo->tm_hour;
    m= timeinfo->tm_min;
    s = timeinfo->tm_sec;

}