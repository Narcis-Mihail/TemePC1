// Copacel_Narcis-Mihail_Lab01_P9.cpp 

#include <iostream>
#include <string.h>
using namespace std;

#define CODARE(a,b) (a)^(b)
#define DECODARE(a,b) (a)^(b)

int main()
{
    char sir[20], s1[20], s2[20];
    int nr, tab[20];
    cout << "Introduceti sirul care trebuie codat: ";
    cin.get(sir, 20);
    cout << "\nIntroduceti un nr intreg care va reprezenta masca: ";
    cin >> nr;

    for (int i = 0; i < strlen(sir); i++)
    {
        *(tab + i) = *(sir + i);
        *(s1 + i) = CODARE(*(tab + i), nr);
    }

    cout << "\nSirul codat este: ";
    for (int i = 0; i < strlen(sir); i++)
        cout << *(s1+i);

    for (int i = 0; i < strlen(sir); i++)
        *(s2 + i) = DECODARE(*(s1 + i), nr);

    cout << "\nSirul decodat este: ";
    for (int i = 0; i < strlen(sir); i++)
        cout << *(s2 + i);
}
