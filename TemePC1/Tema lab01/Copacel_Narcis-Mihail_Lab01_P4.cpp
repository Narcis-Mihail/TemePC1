// Copacel_Narcis-Mihail_Lab01_P4.cpp 
#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
using namespace std;

double produs(int x=10, float y=1.5, double z=12.5); 

int main()
{
    int x, y, z;

    cout << "Fara parametri: " << produs();
    cout << "\n\nUn parametru: "; cin >> x; cout << "\n";
    cout << produs(x);
    cout << "\n\nDoi parametrii: "; cin >> y; cout << "\n";
    cout << produs(x, y);
    cout << "\n\nTrei parametrii:"; cin >> z; cout << "\n";
    cout << produs(x, y, z);

}

double produs(int x, float y, double z)
{
    return x*y*z;
}