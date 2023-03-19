// Copacel_Narcis-Mihail_Lab02_P11.cpp 

#include <iostream>
using namespace std;

int convert(int numar, int baza) {
    if (numar == 0 || baza == 10)
        return numar;

    return (numar % baza) + 10 * convert(numar / baza, baza);
}

int main()
{
    
        int i,n;
        cin >> i >> n;
            printf("%d este %d in baza(%d)\n", n, convert(n, i),i);
        return 0;
    
    
}

