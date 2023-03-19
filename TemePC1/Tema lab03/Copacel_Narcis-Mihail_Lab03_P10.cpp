// Tasca_Andrei-Antonio_Lab03_P10.cpp 
/*Citiți de la intrarea standard un tablou unidimensional de maxim 20 de valori întregi. Folosind mecanismul de 
căutare binară, determinați dacă o nouă valoare, a, introdusă de la tastatură există în șir. Dacă da, determinați 
toți factorii primi ai acestei valori pe care îi veți afișa pe ecran.*/
#include<iostream>
using namespace std;
int n, a, v[10], m;
int caut(int s, int d)
{
    if (s > d)
        return -1;
    else
    {
        m = (s + d) / 2;
        if (a == v[m])
            return m;
        if (a < v[m])
            return caut(s, m - 1);
        else
            return caut(m + 1, d);
    }
}
int main()
{
    cout << "n,x ";
    cin >> n >> a;
    cout << "dati " << n << " elemente (in ordine crescatoare).\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "elementul " << a << " a fost gasit pe pozitia: " << caut(0, n - 1);
    return 0;
}