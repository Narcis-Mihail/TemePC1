// Copacel_Narcis-Mihail_Lab08_P7.cpp 

#include <iostream>
using namespace std;

struct publicatie
{
    char nume[10];
    char editura[10];
    int pagini;
    int exemp;
    float pret;
    float PretTVA;
    float pretMediu;
};

class Chiosc
{
private:
    struct publicatie* p;
    static float valoare_tva;
    int nr_publicatii;
public:
    Chiosc(int n)
    {
        nr_publicatii = n;
        p = new struct publicatie[n];
        for (int i = 0; i < n; i++)
        {
            cout << "\nIntroduceti numele: ";
            cin >> (p + i)->nume;
            cout << "Introduceti editura: ";
            cin >> (p + i)->editura;
            cout << "Introduceti nr. de pagini: ";
            cin >> (p + i)->pagini;
            cout << "Introduceti nr de exemplare: ";
            cin >> (p + i)->exemp;
            cout << "Introduceti pretul fara TVA: ";
            cin >> (p + i)->pret;
            cout << endl;
        }
    }

    static void setTVA(int x)
    {
        valoare_tva = float(x) / 100;
    }

    void PretTotal()
    {
        for (int i = 0; i < nr_publicatii; i++)
        {
            (p + i)->PretTVA = ((p + i)->pret + ((p + i)->pret * valoare_tva)) * (p + i)->exemp;
        }
    }

    void PretMediuPagina()
    {
        for (int i = 0; i < nr_publicatii; i++)
        {
            (p + i)->pretMediu = (p + i)->PretTVA / (p + i)->exemp;
        }
    }

    void ordonare()
    {
        struct publicatie aux;
        int ok;
        do
        {
            ok = 0;
            for (int i = 0; i < nr_publicatii - 1; i++)
                if ((p + i)->PretTVA < (p + i + 1)->PretTVA)
                {
                    aux = *(p + i);
                    *(p + i) = *(p + i + 1);
                    *(p + i + 1) = aux;

                    ok = 1;

                }

        } while (ok == 1);
    }

    void getPublicatii()
    {
        for (int i = 0; i < nr_publicatii; i++)
        {
            cout << i << ":";
            cout << "\n\tEditura: " << (p + i)->editura;
            cout << "\n\tNumele:" << (p + i)->nume;
            cout << "\n\tNumarul de pagini: " << (p + i)->pagini;
            cout << "\n\tNumarul de exemplare: " << (p + i)->exemp;
            cout << "\n\tPretul total cu tva:" << (p + i)->PretTVA;
            cout << "\n\tPretul mediu per pagina:" << (p + i)->pretMediu;
            cout << endl;
        }
    }
};

float Chiosc::valoare_tva;

int main()
{
    int i,newTVA;
    cout << "Introduceti numarul de publicatii din chiosc:";
    cin >> i;



    Chiosc c(i);

    cout << "\n\tIntroduceti noul TVA: ";
    cin >> newTVA;
    Chiosc::setTVA(newTVA);
    c.PretTotal();
    c.PretMediuPagina();
    c.ordonare();
    cout << "\nEditurile ordonate in functie de incasari: \n";
    c.getPublicatii();
    
}


