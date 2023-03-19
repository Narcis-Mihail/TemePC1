// Tasca_Andrei-Antonio_Lab03_P9.cpp
/*Scrieţi o aplicaţie C/C++ care să găsească imaginile cele mai apropiate folosind pe rând o cheie de căutare din 
antetul imaginii. Antetul este reprezentat printr-o structură ce conţine un nume de fişier (sir de caractere), o 
cale (sir de caractere), o rezoluţie de intensitate (întreg), o dimensiune în octeţi (întreg). Pentru fiecare cheie 
folosiţi o metodă diferită de căutare. Antetul imaginilor se află stocat într-un fişier sau se citeşte într-un tablou 
de structuri de la tastatură*/


#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<search.h>
#include<conio.h>

struct imagine {
	char nume[20], cale[20];
	int rezolutie, dimensiune;
};

//prototipuri functii
void citire(struct imagine*);
void afisare(imagine* p);
void meniul();
int cmp1(imagine* a, imagine* b);
int cmp2(imagine* a, imagine* b);
int cmp3(imagine* a, imagine* b);
int cmp4(imagine* a, imagine* b);

void main(void) {
	struct imagine* p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int n, i, x;
	char num[20], calea[20];
	printf("Introduceti numarul de imagini: ");
	scanf("%d", &n);

	//se aloca spatiu dinamic pentru cele n elemente ale tabloului
	p = (imagine*)malloc(n * sizeof(imagine));

	//se testeaza daca s-a alocat spatiu in memorie
	if (p == NULL)// daca nu s-a alocat se afiseaza un mesaj corespunzator
	{
		printf("\nEroare la alocare!\n");
		_getch();
		return;
	}
	else {
		printf("\nIntroduceti datele imaginilor:");
		for (i = 0; i < n; i++)
		{
			printf("\n\tImaginea %d;", i + 1);
			citire(p + i);
			afisare(p + i);
		}
		//meniu
		while (1) {
			printf("\n Tastati cifra corespunzatoare: \n- cautare dupa nume 1");
			printf("\n-cautare dupa cale 2");
			printf("\n-cautare dupa rezolutie 3");
			printf("\n-cautare dupa dimensiune 4");
			printf("\n-iesire dun program 0\n Alegerea dumneavoastra: ");
			scanf("%d", &x);
			
			struct imagine c = { "\0","\0",NULL,NULL };

			switch (x) {
			case 1: {
				//cautare dupa numele imaginii

				printf("\nIntroduceti numele imaginii pe care doriti sa o cautati: ");
				scanf("%s", num);
				strcpy_s(c.nume, num);

				p1 = (struct imagine*)_lfind(&c, p, (size_t*)&n, sizeof(imagine), (int(*)(const void*, const void*))cmp1);
				if (p1) {
					printf("\nImaginea cu numele %s s-a gasit\n", num);
					afisare(p1);
				}
				else
					printf("\nImaginea cu numele %s nu s-a gasit\n", num);
				break;
			}//end case 1
			case 2: {
				//cautare dupa calea imaginii
				printf("\Introduceti calea imaginii pe care doriti sa o cautati: ");
				scanf("%s", calea);
				strcpy_s(c.cale, calea);


				p2 = (struct imagine*)_lfind(&c, p, (size_t*)&n, sizeof(imagine), (int(*)(const void*, const void*))cmp2);
				if (p2) {
					printf("\nImaginea avand calea %s s-a gasit\n", calea);
					afisare(p2);
				}
				else
					printf("\nImaginea avand calea %s nu s-a gasit\n", calea);
			}//end case 2
			case 3: {
				//cautare dupa rezolutia imaginii
				printf("\Introduceti rezolutia imaginii pe care doriti sa o cautati: ");
				scanf("%d",&c.rezolutie);
				p3 = (struct imagine*)_lfind(&c, p, (size_t*)&n, sizeof(imagine), (int(*)(const void*, const void*))cmp3);
				if (p3) {
					printf("\nImaginea cu rezolutia %d s-a gasit\n", c.rezolutie);
					afisare(p3);
				}
				else
					printf("\nImaginea cu rezolutia %d nu s-a gasit\n", c.rezolutie);
				p3 = NULL;
				break;
			}//end case 3
			case 4:{
				//cautare dupa dimensiunea imaginii
				printf("\Introduceti dimensiunea imaginii pe care doriti sa o cautati: ");
				scanf("%d", &c.dimensiune);
				qsort(p, (size_t)n, sizeof(imagine), (int(*)(const void*,const void*))cmp4);
				p4 = (struct imagine*)bsearch(&c, p, (size_t)n, sizeof(imagine), (int(*)(const void*, const void*))cmp4);
				if (p4) {
					printf("\nImaginea cu dimensiunea %d s-a gasit\n", c.dimensiune);
					afisare(p4);
				}
				else
					printf("\nImaginea cu dimensiunea %d nu s-a gasit\n", c.dimensiune);
				p4 = NULL;
				break;
			}//end case 4
			case 0: {
				//se elibereaza spatiul de memorie alocat
				if (p)free(p);
				return;
			}//end case 0
			default:
				printf("\n s-a tastat altceva");
			}//end switch

		}//end while(1)
	}//end else-alocare reusita
	_getch();
}//end main

void citire(imagine* p)
{
	printf("\nNume:");
	scanf("%s", p->nume);
	printf("\nCale:");
	scanf("%s", p->cale);
	printf("\nRezolutie:");
	scanf("%d", &p->rezolutie);
	printf("\nDimensiune:");
	scanf("%d", &p->dimensiune);
}

void afisare(imagine* p) {
	printf("\nNume: %s", p->nume);
	printf("\nCale: %s", p->cale);
	printf("\nRezolutie: %d", p->rezolutie);
	printf("\nDimensiune: %d", p->dimensiune);
}
int cmp1(imagine* a, imagine* b)
{
	return (stricmp(a->nume, b->nume));
}

int cmp2(imagine* a, imagine* b)
{
	return(stricmp(a->cale, b->cale));
}

int cmp3(imagine* a, imagine* b)
{
	return ((a->rezolutie) - (b->rezolutie));
}

int cmp4(imagine* a, imagine* b)
{
	return((a->dimensiune) - (b->dimensiune));
}