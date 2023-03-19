// Copacel_Narcis-Mihail_Lab13_P4.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

class Date
{
    char nume[30];
    char localitate[30];
    char nrTel[11];
public:
    Date()
    {
        strcpy(nume,  NULL);
        strcpy(localitate,  NULL);
        strcpy(nrTel,  NULL);
    }

    Date(const char* n, const char* local, const char* tel)
    {
        strcpy(nume,  n);
        strcpy(localitate,  local);
        strcpy(nrTel,  tel);
    }

    friend ostream& operator<<(ostream&, Date obj);
    friend istream& operator>>(istream&, Date& obj);
};


int main()
{
    char sir[250];
    Date d("Narcis", "Galati", "0761699784");
    cout << "Datele persoanei sunt urmatoarele: ";
    cout << d;

    cout << "\nIntroduceti date noi: ";
    cin >> d;

    ofstream fout;
    fout.open("fis.txt", ios::binary);
    if (!fout.is_open())
    {
        cout << "\n\t\tFisierul nu s-a deshis!!";
        exit(1);
    }

    fout << d;
    fout.close();

    ifstream fin;
    fin.open("fis.txt", ios::binary);
    cout << "\nDatele citite din fisier sunt: ";
    fin >> d;
    cout << d << endl;

    fin.close();
    return 1;
}


ostream& operator<<(ostream& fout, Date obj)
{
    fout << obj.nume << " " << obj.localitate << " " << obj.nrTel;
    return fout;
}

istream& operator>>(istream& fout, Date& obj)
{
    fout >> obj.nume >> obj.localitate >> obj.nrTel;
    return fout;
}


