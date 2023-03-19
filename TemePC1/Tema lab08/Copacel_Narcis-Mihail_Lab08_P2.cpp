// Copacel_Narcis-Mihail_Lab08_P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Calculator;
class Placa_de_baza
{
private:
	char denumire_procesor[20];
	
public:
	Placa_de_baza()
	{
		strcpy_s(denumire_procesor, "INTEL");
	}
	void setProcesor()
	{
		char t[20];
		cout << "\t\nNume procesor: ";
		cin >> t;
		strcpy_s(this->denumire_procesor, t);
	}
	string getProcesor()
	{
		return denumire_procesor;
	}
	void tehnician_service(Calculator& x);
};

class Calculator
{
private:
	int _RAM;

public:
	Calculator()
	{
		this->_RAM = 4;
	}
	int getRAM()
	{
		return _RAM;
	}
	friend void Placa_de_baza::tehnician_service(Calculator&);
};

void Placa_de_baza::tehnician_service(Calculator& x)
{
	x._RAM = 8;
	this->setProcesor();
}

int main()
{
	Calculator calc;
	Placa_de_baza pb;
	cout<<"\nRAM: "<<calc.getRAM();
	cout << "\nDenumire procesor: " << pb.getProcesor();
	pb.tehnician_service(calc);
	cout << "\n\nNoul ram:" << calc.getRAM();
	cout << "\nNoua denumire procesor: " << pb.getProcesor();

   
}

