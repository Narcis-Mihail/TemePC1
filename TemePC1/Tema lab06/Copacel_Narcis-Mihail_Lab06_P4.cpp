// Copacel_Narcis-Mihail_Lab06_P4.cpp 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct data
{
	int zi, luna, an;
	
};

class Data
{
	struct data x;
public:

	Data(int zi, int luna, int an)
	{
		x.zi = zi;
		x.luna = luna;
		x.an = an;
	}
	void getData()
	{
		cout <<"\n"<< x.zi << "/" << x.luna << "/" << x.an;

	}
	
	void ValidareData();
    void afisDate(FILE *f);
};

void Data::ValidareData()
{
    if (x.an > 0)
    {
        if (x.luna == 1 || x.luna == 3 || x.luna == 5 || x.luna == 7 || x.luna == 8 || x.luna == 10 || x.luna == 12 && x.zi > 0 && x.zi <= 31)
            cout << "\nData este valida";
        else

            if (x.luna == 4 || x.luna == 6 || x.luna == 9 || x.luna == 11 && x.zi > 0 && x.zi <= 30)
                cout << "\nData este valida.";
            else
                if (x.luna == 2)
                {
                    if ((x.an % 400 == 0 || (x.an % 100 != 0 && x.an % 4 == 0)) && x.zi > 0 && x.zi <= 29)
                        cout << "\nData este valida.";
                    else if (x.zi > 0 && x.zi <= 28)
                        cout << "\nData este valida.";
                    else
                        cout << "\nData este invalida.";
                }
                else
                    cout << "\nData este invalida.";
    }
    else
        cout << "\nData este invalida.";
}
	
void Data::afisDate(FILE* f)
{
    for (int i = 1; i <=x.luna; i++)
    {
        if (i == this->x.luna)
        {
            for (int j = 1; j < this->x.zi; j++)
            {
                fprintf(f, "%d/%d/%d ", j, i, this->x.an);

            }
            break;
        }
        if (this->x.luna == 1 || this->x.luna == 3 || this->x.luna == 5 || this->x.luna == 7 || this->x.luna == 8 || this->x.luna == 10 || this->x.luna == 12)
            for (int j = 1; j <= 31; j++)
            {
                fprintf(f, "%d/%d/%d ", j, i, this->x.an);
            
            }
        else
            if (this->x.luna == 4 || this->x.luna == 6 || this->x.luna == 9 || this->x.luna == 11 )
                for (int j = 1; j <= 30; j++)
                {
                    fprintf(f, "%d/%d/%d ", j, i, this->x.an);
                    
                }
            else
                if (this->x.luna == 2)
                {
                    if ((x.an % 400 == 0 || (x.an % 100 != 0 && x.an % 4 == 0)))
                        for (int j = 1; j <= 29; j++)
                        {
                            fprintf(f, "%d/%d/%d ", j, i, this->x.an);
                           
                        }
                    else
                        for (int j = 1; j <= 28; j++)
                        {
                            fprintf(f, "%d/%d/%d ", j, i, this->x.an);
                           
                        }
                }
        fprintf(f, "\n");
    }
}

int main()
{
    FILE* f;
   
	int zi, luna, an;
	cin >> zi >> luna >> an;
	Data zi1(zi, luna, an);
	zi1.getData();
    zi1.ValidareData();

    f = fopen("AllDates.txt", "w");
    zi1.afisDate(f);

}
