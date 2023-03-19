// Copacel_Narcis-Mihail_Lab06_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class PilotF1
{
private:
    char nume[30], echipa[30];
    int varsta;
    int record;
    int nr_pole_position;
public:
    void setNume(char x[]) { strncpy(nume, x, 30); }
    void setEchipa(char x[]) { strncpy(echipa, x, 30); }
    void setVarsta(int x) { varsta = x; }
    void setRecord(int x) { record = x; }
    void setNr_pole_position(int x) { nr_pole_position = x; }
    char* GetNume() { return nume; }
    char* GetEchipa() { return echipa; }
    int GetVarsta() { return varsta; }
    int GetRecord() { return record; }
    int GetNr_pole_position() { return nr_pole_position; }

};

void citire(PilotF1*);
PilotF1* best_pilot(PilotF1*);
void afisare(PilotF1*);

int main()
{

    PilotF1 *p;
    p = new PilotF1[3];
    cout << "\t\tIntroduceti datele celor 3 piloti: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nIntroduceti datele pilotului " << i + 1;
        citire(p + i);
    }

    cout << "\n\nPilotul cu cel mai bun timp: ";
    afisare(best_pilot(p));


}

void citire(PilotF1* obj)
{
    char nume[30], echipa[30];
    int varsta, record ,nr_pole_position;
    cin.get();
    cout << "\n\tIntroduceti numele: ";
    cin.get(nume,30);
    obj->setNume(nume);
    cout << "\tIntroduceti echipa: ";
    cin >> echipa;
    obj->setEchipa(echipa);
    cout << "\tIntroduceti varsta: ";
    cin >> varsta;
    obj->setVarsta(varsta);
    cout << "\tIntroduceti recordul: ";
    cin >> record;
    obj->setRecord(record);
    cout << "\tIntroduceti timpul cel mai bun obtinut: ";
    cin >> nr_pole_position;
    obj->setNr_pole_position(nr_pole_position);


}

PilotF1* best_pilot(PilotF1* obj)
{
    int min = 9999,c=0;
    for (int i = 0; i < 3; i++)
        if (min > (obj+i)->GetNr_pole_position())
        {
            min = obj->GetNr_pole_position();
            c = i;
        }

    return (obj + c);

}

void afisare(PilotF1* obj)
{
    cout << "\n\tNumele: " << obj->GetNume();
    cout << "\n\tEchipa:" << obj->GetEchipa();
    cout << "\n\tVarsta: " << obj->GetVarsta();
    cout << "\n\tRecord: " << obj->GetRecord();
    cout << "\n\tCel mai bun timp: " << obj->GetNr_pole_position();

}