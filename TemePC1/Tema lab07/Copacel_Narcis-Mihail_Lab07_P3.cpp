// Copacel_Narcis-Mihail_Lab07_P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct date
{
    string nume, prenume;
    float medie;
    int grupa;
    int n[7];
};

class Student 
{
private:
    int nrStd;
    struct date* p;
public:
    Student()
    {
        this->nrStd = 1;
        p = new struct date[nrStd];
    }
    Student(int nr)
    {
        nrStd = nr;
        p = new struct date[nrStd];
        
        for (int i = 0; i < nrStd; i++)
        {

            cout << "\tIntroduceti datele studentului: "<< i + 1;
            cout << "\nNume:";
            cin >> (p + i)->nume;
            cout << "\nPrenume:";
            cin >> (p + i)->prenume;
            cout << "\nGrupa: ";
            cin >> (p + i)->grupa;
            cout << "\nIntroduceti notele: ";
            for (int j = 0; j < 7; j++)
                cin >> (p + i)->n[j];
            medie(i);

        }
    }
    void medie(int i)
    {
        int suma = 0;
        for (int j = 0; j < 7; j++)
            suma += (p + i)->n[j];
        (p + i)->medie = float(suma) / 7;
    }
    void Sortare();

    void afis()
    {
        for (int i = 0; i < nrStd; i++)
        {
            cout << "\n\tNumele studentului: " << (p + i)->nume << " " << (p + i)->prenume;
            cout << "\n\tGrupa: " << (p + i)->grupa;
            cout << "\n\tMedie: " << (p + i)->medie;
            cout << endl;
        }
    }
};

void Student::Sortare()
{
    struct date *aux{};
    int ok;
    do
    {
        ok = 0;
        for (int i = 0; i < nrStd-1; i++)
            if ((p + i)->medie < (p + i + 1)->medie)
            {
                *aux = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = *aux;

                ok = 1;

            }

    } while (ok == 1);
   
}

int main()
{
    int nr;
    cout << "Introduceti numarul de studenti: ";
    cin >> nr;
    Student s(nr);
    s.Sortare();
    cout << "\nStudentii dupa sortare:";
    s.afis();


}
