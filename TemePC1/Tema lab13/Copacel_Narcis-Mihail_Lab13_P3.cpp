// Copacel_Narcis-Mihail_Lab13_P3.cpp 

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cout << "\t\tNu ati introdus numele fisierului!!!";
		exit(1);
	}

	ifstream fin;
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cout << "\n\t\tNu se poate deschide fisierul!!";
		exit(1);
	}

	
	fin.seekg(0, fin.end);
	int dim = fin.tellg();
	fin.seekg(0, fin.beg);
	
	char* sir = new char[dim];
	
		fin.read(sir, dim);
		sir[dim] = '\0';
		cout << sir;
	
	

	fin.close();
	delete []sir;
	return 1;
}

