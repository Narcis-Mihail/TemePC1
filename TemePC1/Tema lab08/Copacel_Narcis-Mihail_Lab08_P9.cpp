// Copacel_Narcis-Mihail_Lab08_P9.cpp 

#include <iostream>
using namespace std;
#include <time.h>
const int dim_sir = 24;
#define DIM 10

class Person {
	// membri private
	char nume[dim_sir];
	char prenume[dim_sir];
	char cnp[14];
	static int icount;
	// structura CNP: S AN LU ZI 6cifre; total 13 cifre
public:
	// membri publici
	void setNume(char* n);
	void setPrenume(char* p);
	int setValidCnp(char* c);
	char* getNume(void) {
		return nume;
	}
	char* getPrenume(void) {
		return prenume;
	}
	char* getCnp(void) {
		return cnp;
	}
	char get_gender(void);
	int get_an_nast(void);
	int get_luna_nast(void);
	int get_zi_nast(void);
	int get_varsta(void);
	static int getcount()
	{
		return icount;
	}
};

void Person::setNume(char* n) {
	if (n != 0)
		strncpy_s(nume, n, dim_sir - 1);
	else
		strcpy_s(nume, "Necunoscut");
}

void Person::setPrenume(char* p) {
	if (p != 0)
		strncpy_s(prenume, p, dim_sir - 1);
	else
		strcpy_s(prenume, "Necunoscut");
}

int Person::setValidCnp(char* c) {
	char buf[3];
	int zi, luna, an;
	if (c != 0) {
		// validare CNP: numai pentru cifra gen, cifrele pentru AN, LU, ZI
		if (strlen(c) != 13)//lungime cnp
			return 1;
		if (c[0] != '1' && c[0] != '2' && c[0] != '5' && c[0] != '6')//cod cnp
			return 2;
		strncpy_s(buf, c + 1, 2);//an
		buf[2] = '\0';
		an = atoi(buf);
		if (an > 99)
			return 3;//inconsistent

		strncpy_s(buf, c + 3, 2);//luna
		buf[2] = '\0';
		luna = atoi(buf);
		strncpy_s(buf, c + 5, 2);//zi
		buf[2] = '\0';
		zi = atoi(buf);

		if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
		{

			if (zi > 0 && zi <= 31)
			{
				strcpy_s(cnp, c);
				{icount++; return 0; };
			}
			else
				return 5;
		}
		else
			if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
			{
				if (zi > 0 && zi <= 30)
				{
					strcpy_s(cnp, c);
					{icount++; return 0; };
				}
				else
					return 5;
			}
			else
				if (luna == 2)
				{
					if ((an % 400 == 0 || (an % 100 != 0 && an % 4 == 0)))
						if (zi > 0 && zi <= 29)
						{
							strcpy_s(cnp, c);
							{icount++; return 0; };
						}
						else
							if (zi > 0 && zi <= 28)
							{
								strcpy_s(cnp, c);
								{icount++; return 0; };
							}
							else
								return 5;

				}
				else
					return 4;

	}
	else return -1;
}

char Person::get_gender(void) {
	if (cnp[0] == '1' || cnp[0] == '5') return 'M';
	if (cnp[0] == '2' || cnp[0] == '6') return 'F';
	return 'X';
}

int Person::get_an_nast(void) {
	char buf[3];
	if (this->cnp[0] == '1' || this->cnp[0] == '2')
	{
		strncpy_s(buf, cnp + 1, 2);
		buf[2] = '\0';
		return(1900 + atoi(buf));
	}
	else
	{
		strncpy_s(buf, cnp + 1, 2);
		buf[2] = '\0';
		return(2000 + atoi(buf));
	}

}

int Person::get_luna_nast(void) 
{
	char buf[3];
	strncpy_s(buf, cnp + 3, 2);
	buf[2] = '\0';
	return(atoi(buf));
}

int Person::get_zi_nast(void) 
{
	return((cnp[5] - '0') * 10 + (cnp[6] - '0'));
}

int Person::get_varsta(void) {
	struct tm newTime;
	time_t szClock;
	time(&szClock);
	localtime_s(&newTime, &szClock);
	int an_c = 1900 + newTime.tm_year;
	int an_n = get_an_nast();
	int n = an_c - an_n;
	int lu_c = newTime.tm_mon + 1;
	int lu_n = get_luna_nast();
	if (lu_c < lu_n)
		n--;
	else {
		if (lu_c == lu_n) {
			int zi_c = newTime.tm_mday;
			int zi_n = get_zi_nast();
			if (zi_c < zi_n) n--;
		}
	}
	return n;
}

int Person::icount;

int main() 
{
	int n;
	cout << "Cate persoane doriti sa introduceti? ";
	cin >> n;
	Person *p ;
	p = new Person[n];
	for (int i = 0; i < n; i++)
	{
		char aux_string[dim_sir];
		cout << "\nEnter Name: ";
		cin >> aux_string;//Popescu
		(p + i)->setNume(aux_string);
		cout << "\nEnter SurName: ";
		//cin >> aux_string;//Bitanescu
		cin.ignore();
		gets_s(aux_string, dim_sir);//Preia Prenume si cu spatiu
		(p + i)->setPrenume(aux_string);
		cout << "\nEnter CNP: ";
		cin >> aux_string;

		int t_cnp = (p + i)->setValidCnp(aux_string);
		switch (t_cnp) {
		case 0: cout << "\nCNP valid\n";
			cout << "\nDate despre obiect: " << endl;
			cout << "\tNume: " << (p + i)->getNume() << ", Prenume: " << (p + i)->getPrenume() << ", CNP: " << (p + i)->getCnp() << endl;
			cout << "\tGen: " << (p + i)->get_gender() << endl;
			cout << "\tData nasterii: " << (p + i)->get_an_nast() << "/" << (p + i)->get_luna_nast() <<
				"/" << (p + i)->get_zi_nast() << endl;
			cout << "\tVarsta: " << (p + i)->get_varsta() << endl; break;
		case 1: cout << "\nLungime sir CNP invalid"; break;
		case 2: cout << "\nGen invalid"; break;
		case 3: cout << "\nAn invalid"; break;
		case 4: cout << "\nLuna invalida"; break;
		case 5: cout << "\nZi invalida"; break;
		default: cout << "\nProbleme CNP"; break;
		}
	}

	cout << "\n\n\tAu fost introduse datele corecte a " << Person::getcount() << " persoane.";
	return 0;
}