// Copacel_Narcis-Mihail_Lab06_P5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <malloc.h>
using namespace std;

struct data
{
    int zi, luna, an;

};

class Data
{
    struct data *p;
public:

    Data(int zi, int luna, int an)
    {
        p = (struct data*)malloc(1 * sizeof(struct data));
        p->zi = zi;
        p->luna = luna;
        p->an = an;
    }
    void getData()
    {
        cout << "\n" << p->zi << "/" << p->luna << "/" << p->an;

    }

    void ValidareData();
};

void Data::ValidareData()
{
    if (p->an > 0)
    {
        if (p->luna == 1 || p->luna == 3 || p->luna == 5 || p->luna == 7 || p->luna == 8 || p->luna == 10 || p->luna == 12 && p->zi > 0 && p->zi <= 31)
            cout << "\nData este valida";
        else

            if (p->luna == 4 || p->luna == 6 || p->luna == 9 || p->luna == 11 && p->zi > 0 && p->zi <= 30)
                cout << "\nData este valida.";
            else
                if (p->luna == 2)
                {
                    if ((p->an % 400 == 0 || (p->an % 100 != 0 && p->an % 4 == 0)) && p->zi > 0 && p->zi <= 29)
                        cout << "\nData este valida.";
                    else if (p->zi > 0 && p->zi <= 28)
                        cout << "\nData este valida.";
                    else
                        cout << "\nData este invalida.";
                }
                else
                    cout << "\nData este invalida.";
    }
    else
        cout << "\nData este invalida.";
}



int main()
{
    int zi, luna, an;
    cin >> zi >> luna >> an;
    Data zi1(zi, luna, an),*p;
    p = &zi1;
    p->getData();
    p->ValidareData();

}