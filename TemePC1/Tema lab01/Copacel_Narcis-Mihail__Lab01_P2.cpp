// Copacel_Narcis-Mihail__Lab01_P2.cpp 

#include <iostream>
using namespace std;

/*inline int min(int a, int b);

int main()
{
    int v1, v2, min_v;
    cout << "Introduceti 2 valori intregi: ";
    cin >> v1;
    cin >> v2;
    min_v = min(v1, v2);
    cout << "\nMinimul este= " << min_v << endl;
}

inline int min(int a, int b)
{
    if (a < b) return a;
    return b;
}
*/

inline int min(int a, int b,int c);

int main()
{
    int v1, v2, v3, min_v;
    cout << "Introduceti 3 valori intregi: ";
    cin >> v1 >> v2 >> v3;

    min_v = min(v1, v2, v3);
    cout << "Minimul dintre cele 3 numere este: " << min_v;

}

inline int min(int a, int b, int c)
{
    if (a < b && b < c) return a;
    else
        if (a<b && b>c)
        {
            if (a > c) return c;
            else
                return a;
        }
        else
            return b;
}