// Copacel_Narcis-Mihail_Lab02_P4.cpp 
#include <iostream>
#include <math.h>
using namespace std;

int a(int a0, int b0, int n);
int b(int a0, int b0, int n);

int main()
{
    int a0, b0, n;

    cout << "Introduceti valori:";
    cin >> a0 >> b0 >> n;

    cout << "a(n)= " << a(a0, b0, n);
    cout << "\nb(n)= " << b(a0, b0, n);

    


}

int a(int a0, int b0, int n)
{
    if (n == 0)
        return a0;
    else
        return(a(a0, b0, n - 1) + b(a0, b0, n - 1))/2;
    
}

int b(int a0, int b0, int n)
{
    if (n == 0)
        return a0;
    else
        return sqrt((float)(a(a0, b0, n - 1) * b(a0, b0, n - 1)));
}