// Copacel_Narcis-Mihail_Lab02_P03.cpp 

#include <iostream>
using namespace std;

int cmmdc(int a, int b);

int main()
{
    int x, y;

    cin >> x >> y;

    cout << "Cel mai mare divizor comun este :" << cmmdc(x, y);

}

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);


} 