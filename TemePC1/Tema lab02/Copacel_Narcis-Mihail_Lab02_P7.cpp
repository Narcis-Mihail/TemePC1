// Copacel_Narcis-Mihail_Lab02_P7.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


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
    cout << "\nSuma elem pare este: " << suma(v, n);

}

int suma(int v[], int n)
{
    if (n == 1)
    {
        if (v[n - 1] % 2 == 0) return v[n - 1];
        else return 0;
    }
    else
    {
        if (v[n - 1] % 2 == 0) return v[n - 1] + suma(v, n - 1);
        else
            return suma(v, n - 1);
    }
}