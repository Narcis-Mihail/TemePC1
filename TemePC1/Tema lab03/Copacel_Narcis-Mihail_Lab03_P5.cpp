// Tasca_Andrei-Antonio_Lab03_P5.cpp 
/*Creaţi un fişier în care stocaţi un şir de numere întregi, generate in mod aleator. Preluaţi prin program aceste 
valori. Folosiţi metoda divide et impera pentru a determina minimul şi maximul din şir şi afisaţi rezultatele pe 
ecran. Actualizaţi fişierul iniţial adăugând aceste două valori*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void creare(char t[30]);
int max(int* vector, int pozi, int len);
int min(int* vector, int pozi, int len);

void main(void) {
	FILE* f;
	char nume[30], ch;
	int v[100], n;
	printf("Introduceti numele fisierului de creat: ");
	scanf("%s", nume);

	creare(nume);

	if (!(f = fopen(nume, "r")))
	{
		printf("Eroare la deschiderea fisierului!\n");
		_getch();
		return;
	}
	int i = 0;
	while(fgetc(f)!=EOF){//cat timp nu am ajuns la sf fisierului citim
		fscanf(f, "%d", &v[i]);
		i++;
	}
	n = i;
		for (int i = 0; i < n; i++)
			printf("%d", v[i]);

	printf("\nMaximul dintre elem vect este %d", max(v, 0, n));
	printf("\nMinimul dintre elem vect este %d \n", min(v, 0, n));
	fclose(f);

	//adaugam maximul si minimul in fisier
	if (!(f = fopen(nume, "a")))
	{
		printf("Eroare la deschiderea fisierului!\n");
		_getch();
		return;
	}
	fprintf(f, "%d", max(v, 0, n));
	fprintf(f, "%d", min(v, 0, n));
	fclose(f);
	_getch();
}

void creare(char nume[30])
{
	FILE* f;
	int i, n, d;
	if (!(f = fopen(nume, "w")))
	{
		printf("Eroare la crearea fisierului!\n");
		_getch();
		exit(0);
	}
	printf("\nCate numere vreti sa fie in fisier: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nIntroduceti numarul: ");
		scanf("%d", &d);
		fprintf(f, "%d", d);
	}
	fclose(f);
}//creare

int max(int* vector, int pozi, int len) {//determinam maximul folosind metoda div et impera
	int a, b;
	if(len==1)
		return(*(vector+pozi));
	else {
		a=max(vector,pozi,len/2);
			b=max(vector,len/2+pozi,len/2+len%2);
			if(a>b)
				return a;
			else
				return b;
	}
}//max

int min(int* vector, int pozi, int len) {//determinam minimul folosind metoda div et impera
	int a, b;
	if (len == 1)
		return(*(vector + pozi));
	else {
		a = min(vector, pozi, len / 2);
		b = min(vector, len / 2 + pozi, len / 2 + len % 2);
		if (a > b)
			return a;
		else
			return b;
	}
}