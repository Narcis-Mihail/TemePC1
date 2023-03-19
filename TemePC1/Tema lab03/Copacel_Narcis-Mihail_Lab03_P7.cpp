// Tasca_Andrei-Antonio_Lab03_P7.cpp
/*Să se calculeze ∫ab 1/(1+x2)dx, cu ajutorul metodei trapezelor, astfel încât inălţimea fiecărui trapez a cărui arie 
se însumează să fie mai mică decât ε=0.0001. Aria trapezului cu vârfurile în punctele (a,0), (b,0), (a,f(a)) şi 
(b,f(b)) este (b-a)*(f(a)+f(b))/2, iar f(x)=1/(1+x2). Se citesc de la tastatură numerele reale a şi b, a≤b. Utilizaţi metoda divide et impera.*/


#include <stdio.h>
#include <conio.h>
float integrala(float a, float b);
float functia(float x);

void main() {
	float a, b;
	printf("Introduceti valoarea numarului a: ");
	scanf("%f", &a);

	printf("Introduceti valoarea numarului b; ");
	scanf("%f", &b);
	printf("Valoarea integralei de la %.2f la %.2f pentru f=1/1+x^2 este:%.2f\n", a, b, integrala(a, b));
	_getch();
}

float integrala(float a, float b) {//calculeaza val integralei folosind metoda div et impera
	float c, arie;
	float e = 0.0001;
	if ((b - a) > e) {
		c = (a + b) / 2;
		return integrala(a, c) + integrala(c, b);
	}
	else //daca(b-a)<0,0001 calculam valoarea ariei
		return (b - a) * (functia(a) + functia(b)) / 2;
}
float functia(float x) {
	return(1 / (1 + x * x));
}