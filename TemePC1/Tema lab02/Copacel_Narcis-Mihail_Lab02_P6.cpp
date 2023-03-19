// Copacel_Narcis-Mihail_Lab02_P6.cpp 

#include <iostream>
using namespace std;

int prod_scalar(int v[], int v2[], int n);

int main()
{
    int v[50], v2[50], n;
    cout << "Dati dimensiunea tablourilor: ";
    cin >> n;
    if (n < 0 && n <= 10)
        cout << "Numarul de elemente nu este intre 1 si 10!\n";
    else
    {
        cout << "Cititi coeficientii primului tablou:\n";
        for (int i = 0; i < n; i++) {
            cout << "Coeficientul " << i + 1<<" :";
            cin >> v[i];
        }

        cout << "Cititi coeficientii celui de-al doilea tablou:\n";
        for (int i = 0; i < n; i++) {
            cout << "Coeficientul " << i + 1<<" :";
            cin >> v2[i];
        }
        cout << "\nProdusul scalar dintre cele 2 tablouri este: " << prod_scalar(v, v2, n);
    }
     
}

int prod_scalar(int v[], int v2[], int n)
{
    if (n == 1) return (v[n - 1] * v2[n - 1]);
    else return v[n - 1] * v2[n - 1] + prod_scalar(v, v2, n - 1);
}