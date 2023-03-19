// Copacel_Narcis-Mihail_Lab02_P10.cpp 


#include <iostream>
using namespace std;

int recursiv(int v[],int n,int x);
int nerecursiv(int v[], int n,int x);

int main()
{
    int v[100], n, i,x;

    cout << "Introduceti dimensiunea sirului: "; cin >> n;
    cout << "Introduceti valori in sir:";
    for (i = 0; i < n; i++)
        cin >> v[i];
    
    cout << "Introduceti numarul pe care il cautati: "; cin >> x;
    cout << "\nCautare recursiva: " << recursiv(v, n,x);
    cout << "\nCautare nerecursiva: " << nerecursiv(v, n, x);
}

int recursiv(int v[], int n,int x )
{
    if (n == 1)
    {
        if (v[n - 1] == x)
            return 1;
        else
            return 0;
    }
    else
    
        if (v[n - 1] == x)
        
            return 1+recursiv(v, n - 1, x);
        else
            return recursiv(v, n - 1, x);
    
}

int nerecursiv(int v[], int n, int x)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            c++;
    }
    return c;
}