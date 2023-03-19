// Tasca_Andrei-Antonio_Lab03_P8.cpp 
/*Să se scrie o aplicație C/C++ care să genereze aleator maxim 10 valori întregi, ce vor fi memorate într-un 
tablou unidimensional. Să se verifice dacă o altă valoare generată aleator aparține acestui tablou, utilizând 
funcția _lsearch().*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <search.h>
#include <conio.h>
using namespace std;

//prototipul functie de comparare intre valorile sirului si valoarea cautata in sir
int compare(int*, int*);
//prototipul functiei de cautare si/sau adaugare a unei noi valori in sir
int cautare_adaugare(int*, int*, int);
void main(void)
{
    int *p = NULL, *key = NULL, k, n = 10, i;
    //se aloca dinamic spatiu in memorie pentru elementele tabloului
    p = (int*)malloc(11*sizeof(int));
    if (p != NULL)//se testeaza daca s-a alocat spatiu in memorie
    {
        //obtinem niste numere intregi generate aleator si le punem in tablou
        srand((unsigned)time(NULL));
        for (i = 0; i < n; i++)
            *(p + i) = (int)rand();
        printf("Tabloul obtinut este:\n") ;//afisam tabloul obtinut
        for (i = 0; i < 10; i++)
            printf("%d",*(p + i));
        //obtinem un numar intreg generat aleator
        k = (int)rand();
        key = &k; //atribuim pointerului adresa numarului generat
        printf("\n\nNumarul generat ce trebuie cautat in tabloul este: %d\n", k);
        if (cautare_adaugare(key, p, n))
            printf("\nNumarul %d, exista deja\n", *key);
        else
        {
            n++;
            printf("\nNumarul %d a fost adaugat in tablou pe ultima pozitie\n", *key);
            printf("\nTabloul nou obtinut este:\n"); //afisam tabloul obtinut 
            for (i = 0; i < n; i++)
                printf("%d", *(p + i));
            printf("\n");
        }

    }
    else //in cazul in care alocarea nu a reusit se afiseaza un mesaj corespunzator
    {
        printf("\n Alocare esuata\n");
        _getch();
        return;
    }
    if (p) //se elibereaza spatiul de memorie in cazul in care alocarea a fost reusita
        free(p);
    _getch();

}

int cautare_adaugare(int *key, int*p, int n)
{
    int m = n;
    _lsearch(key, p, (size_t*)&n, sizeof(int), (int(*)(const void*, const void*))compare);
    return(n == m);

}
int compare(int* a, int *b)
{
    return(*a - *b);
}