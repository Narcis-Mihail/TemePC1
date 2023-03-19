// Copacel_Narcis-Mihail_Lab01_P1.cpp 

#include <iostream>
using namespace std;

//#define MAX2(a,b) ((a)>(b)?(a):(b))
#define MAX3(a,b,c) ((a)<(b)||(a)<(c)?((b)>(c)?a=b:a=c):a=a)

int main()
{
   /* int a, b;
    cin >> a >> b;
    cout << "Maximul dintre cele doua valori este: " << MAX(a, b);*/

    int a, b, c;
    cin >> a >> b >> c;
    MAX3(a, b, c);
    cout << a;

}