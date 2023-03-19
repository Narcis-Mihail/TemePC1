// Copacel_Narcis-Mihail_Lab02_P01.cpp 

#include <iostream>
using namespace std;

int aranj(int n, int k);

int main()
{
    int n, k;
    cout << "Aranjamente de n="; cin >> n;
    cout << "Luate de cate k="; cin >> k;
    cout << "este egal cu : "<<aranj(n,k);


    
}


int aranj(int n, int k)
{
    if (k == 1) return n;
    return n  * aranj(n - 1, k - 1);
}