// Copacel_Narcis-Mihail_Lab07_P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class TablouUni
{
	int dim;
	float* sir;
public:
	TablouUni()
	{
		dim = 0;
		sir = new float[dim];
	}
	float getValori(int i)
	{
		return *(sir+i);
	}
	int getDim()
	{
		return dim;
	}
	void setValori(int n)
	{
		dim = n;
		sir = new float[dim];
		for (int i = 0; i < dim; i++)
			cin >> *(sir + i);
	}
	void NewTablou(TablouUni obj1, TablouUni obj2);

};

void TablouUni::NewTablou(TablouUni obj1, TablouUni obj2)
{
	if (obj1.dim > obj2.dim)
		this->dim = obj2.dim;
	else
		this->dim = obj1.dim;

	this->sir = new float[dim];

	for (int i = 0; i < this->dim; i++)
		*(sir + i) = obj1.getValori(i) - obj2.getValori(i);

	
}
int main()
{
	TablouUni t[3];
	for (int i = 0; i < 2; i++)
	{

		cout << "\tIntroduceti dimensiunea tabloului " << i + 1<<": ";
		int n;
		cin >> n;
		cout << "\n\tIntroduceti valori in tablou: ";
		t[i].setValori(n);
		cout << endl;
	}

	t[2].NewTablou(t[0], t[1]);

	cout << "\n\nValorile tabloului 3 sunt: ";
	for (int i = 0; i < t[2].getDim(); i++)
		cout << t[2].getValori(i) << " ";


}

