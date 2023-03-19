// Copacel_Narcis-Mihail_Lab09_P7.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student
{
private:
    char nume[30];
    int *note;
    int nrnote;
public:
    Student(int note[], int nrnote, char* nume);
    Student(Student* obj);
    Student operator=(Student *obj);
    void setnote(int note[]);
    void afisare();
    //~Student();

};

Student::Student(int note[], int nrnote,  char* nume)
{
    strcpy(this->nume, nume);
    this->nrnote = nrnote;
    setnote(note);

}

Student::Student(Student* obj)
{
    strcpy(nume, obj->nume);
    nrnote = obj->nrnote;
    //this->~Student();
    setnote(obj->note);
}

Student Student::operator=(Student* obj)
{
    //this->~Student();
    strcpy(nume, obj->nume);
    nrnote = obj->nrnote;
    setnote(obj->note);
    return *this;

}

void Student::setnote(int note[])
{
    this->note = new int[nrnote];
    for (int i = 0; i < nrnote; i++)
        this->note[i] = note[i];
}

void Student::afisare()
{
    cout << "\n\tNume: " << nume;
    cout << "\n\tNumarul de note: " << nrnote;
    cout << "\n\tNotele: ";
    for (int i = 0; i < nrnote; i++)
        cout << note[i] << " ";
}

//Student::~Student()
//{
//    cout << "\nStergem notele!";
//    delete []note;
//}

int main()
{
    int note[10], nrnote;
    char nume[20];

    cout << "Introduceti numele primului student: ";
    cin.get(nume, 10);
    cin.get();
    cout << "\nIntroduceti numarul de note ale studentului: ";
    cin >> nrnote;
    cout << "\nIntroduceti notele acestuia: ";
    for (int i = 0; i < nrnote; i++)
        cin >> note[i];

    Student s1(note, nrnote, nume);
    s1.afisare();

    cout << "\nUtilizarea constructorului de copiere: ";
    Student s2(s1);
    s2.afisare();

    cin.get();
    cout << "\nIntroduceti numele celui de-al student: ";
    cin.get(nume, 10);
    cin.get();
    cout << "\nIntroduceti numarul de note ale studentului: ";
    cin >> nrnote;
    cout << "\nIntroduceti notele acestuia: ";
    for (int i = 0; i < nrnote; i++)
        cin >> note[i];
    Student s3(note, nrnote, nume);
    
    cout << "\nSupraincarcarea operatorului de atribuire: ";
    Student s4 = s3;
    s4.afisare();

    return 0;
}

