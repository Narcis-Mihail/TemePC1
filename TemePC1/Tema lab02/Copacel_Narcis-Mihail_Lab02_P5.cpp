// Copacel_Narcis-Mihail_Lab02_P5.cpp
#include <iostream>
using namespace std;

char invers(char sir[], int x);

int main()
{
	char sir[30];
	int dim;
	cout << "Indicati dimensiunea sirului: ";
	cin >> dim;

	for (int i = 0; i < dim; i++)
	{
		cout << "Introduceti caracterul de pe pozitia " << i+1<<" :";
		cin >> sir[i];
		cout << endl;
	}
	cout << endl;
	invers(sir, dim);
	cout << endl;

}

char invers(char sir[], int x)
{
	if (x == 1) cout << sir[0];
	else 
	{
		cout << sir[x - 1];
		return invers(sir, x - 1);

	}
}
