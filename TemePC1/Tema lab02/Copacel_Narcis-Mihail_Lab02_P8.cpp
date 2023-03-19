// Copacel_Narcis-Mihail_Lab02_P8.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int produs(int v[], int n);
int prim(int x);
int suma(int v[], int n);

int main()
{
    FILE* f;
    int v[100], n;

    f = fopen("fisier.txt", "r");

    if (f == NULL)
    {
        cout << "\n\n\tEroare la deschiderea fisierului!";
        return 1;
    }

    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &v[i]);

    fclose(f);

    if (n % 2 == 0)
        cout << "\nProdusul elementelor de pe poz impare este: " << produs(v, n - 1);
    else
        cout << "\nProdusul elementelor de pe poz impare este: " << produs(v, n );
    cout << "\nSuma elementelor prime este " << suma(v, n);
}

int produs(int v[], int n)
{
    if (n == 0) return 1;
    else {
        if (n % 2 != 0) return v[n - 1] * produs(v, n - 1);
        else return produs(v, n - 1);
    }
}

int prim(int x)
{
    if (x == 1)
        return 0;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

int suma(int v[], int n)
{
    if (n == 0) return 0;
    else
        if (prim(v[n - 1]) == 1) return v[n - 1] + suma(v, n - 1);
        else
            return suma(v, n - 1);
}