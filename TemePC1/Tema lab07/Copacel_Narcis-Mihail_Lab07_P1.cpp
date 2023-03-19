// Copacel_Narcis-Mihail_Lab07_P1.cpp 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

const int dim_sir = 20;
class CPunctText {
	int x;
	int y;
	//int lungime_sir;//atribut redundant
	char* sNume;
public:
	//constructor explicit vid
	CPunctText();
	//constructor cu parametri
	CPunctText(int ix, int iy, const char* sText = "Punct");
	//constructor de copiere
	CPunctText(const CPunctText& pct);
	//destructor:
	~CPunctText();
	int Cx() { return x; }
	int Cy() { return y; }
	string CNume() { return sNume; }

	CPunctText(CPunctText &obj1,CPunctText &obj2);
	float Distanta(CPunctText* obj);
};
CPunctText::CPunctText() {
	
	
	sNume = new char[dim_sir+1];
}
CPunctText::CPunctText(int ix, int iy, const char* sText) {
	
	
	sNume = new char[strlen(sText) + 1];
	x = ix;
	y = iy;
	strcpy(sNume, sText);
}
CPunctText::CPunctText(const CPunctText& pct) {
	
	sNume = new char[strlen(pct.sNume)+1];
	x = pct.x;
	y = pct.y;
	strcpy(sNume, pct.sNume);
}
CPunctText::~CPunctText() {
	
	delete[] sNume;
}

CPunctText::CPunctText(CPunctText &obj1,CPunctText &obj2)
{
	
	sNume = new char[strlen(obj1.sNume) + strlen(obj2.sNume)+1];
	strcat(strcpy(sNume, obj1.sNume), obj2.sNume);
	x = obj1.x + obj2.x;
	y= obj1.y + obj2.y;
	
	
}

float CPunctText::Distanta(CPunctText* obj)
{
	float d;
	return d = sqrt(pow(this->x,2)+pow(this->y,2));
	
}


int main() {
	CPunctText cpt1(1, 2, "Punct1");//apel constructor cu parametri
	CPunctText cpt2(cpt1); //apel constructor de copiere
	CPunctText cpt3 = cpt2; //apel constructor de copiere
	CPunctText cpt4(4, 5); //apel constructor cu parametri
	CPunctText cpt5(cpt1,cpt2);

	cout << "Punctul " << cpt5.CNume() << " are coordonatele x=" << cpt5.Cx() << " si y=" << cpt5.Cy();
	
}//main