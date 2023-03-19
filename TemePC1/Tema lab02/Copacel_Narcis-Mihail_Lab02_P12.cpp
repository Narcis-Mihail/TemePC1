// Copacel_Narcis-Mihail_Lab02_P12.cpp 

#include <iostream>
using namespace std;

int sum(float s, float p, int n);

int main()
{
    float s, p;
    int n;
    cin >> s >> p >> n;
    cout << "Suma este egala cu: " << sum(s, p, n);
}

int sum(float s, float p, int n)
{
    if (n == 0)
        return 2;
    else
        if (n == 1)
            return s;
        else
            return s * sum(s, p, n - 1) - p * sum(s, p, n - 2);
}
