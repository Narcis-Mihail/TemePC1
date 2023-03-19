// Copacel_Narcis-Mihail_Lab01_P7.cpp 

#include <iostream>
using namespace std;

#define codare(x,n) ((x)+n)
#define Codare 3

int main()
{
    char x,y;
    int n = Codare;

    cout << "Introduceti un caracter: "; cin >> x;
    y = codare(x, n);
    cout << "Caracterul " << x << " codat este " << y;


}

