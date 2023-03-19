// Copacel_Narcis-Mihail_Lab06_P5.cpp 

#include <iostream>

using namespace std;
class Test2 {
	int x;

	Test2() {
		cout << "\nApel constructor explicit vid.";
	}friend class B;



};
class B
{
	Test2 a1;

public:
	void setVariabila(int a)
	{
		a1.x = a;
	}
	int getVariabila() { return a1.x; }

};
int main() {

	B *p,b1;
	p = &b1;

	int a;
	cout << "\nIntroduceti valoarea variabilei de tip \"int\" din clasa: ";
	cin >> a;
	p->setVariabila(a);
	cout << "Variabila a1.x este egala cu: " << p->getVariabila();
}