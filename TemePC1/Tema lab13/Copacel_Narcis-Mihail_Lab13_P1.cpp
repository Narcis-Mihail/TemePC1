// Copacel_Narcis-Mihail_Lab13_P1.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;



int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "\t\tNu ati introdus numele fisierului!!!";
		exit(1);
	}
	char n;
	ifstream f;
	f.open(argv[1],ios::in);
	if (!f.is_open())
	{
		cout << "\n\t\tNu se poate deschide fisierul!!";
		exit(1);
	}
	f.seekg(0, ios::end);
	long dim = f.tellg();
	f.seekg(dim / 2, ios::beg);

	cout << "Continutul celei de a doua jumatati a fisierului: " << endl;

	while (!f.eof())
	{
		
		f.get(n);
		if (f.eof())
			break;
		cout << n;
	}

	cout << endl;
	f.close();
	return 0;
}
