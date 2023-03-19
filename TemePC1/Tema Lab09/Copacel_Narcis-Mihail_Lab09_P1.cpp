// Copacel_Narcis-Mihail_Lab09_P1.cpp 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX = 30;//nr. caractere
const int dim = 5;//nr. obiecte implicit

class Persoana {
    char* nume;
    double greutate;
    int varsta;
public:
    Persoana() {
        nume = new char[strlen("Necunoscut") + 1];
        strcpy(nume, "Necunoscut");
        greutate = 0.0;
        varsta = 0;
    }
    Persoana(char* nume, double greutate, int varsta) 
    {
        nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->greutate = greutate;
        this->varsta = varsta;
    }

    Persoana(Persoana& c)
    {
        delete[] this->nume;
        nume = new char[strlen(c.nume) + 1];
        strcpy(this->nume, c.nume);
        this->greutate = c.greutate;
        this->varsta = c.varsta;

    }

    void setNume(char* nume)
    {
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

    }

    void setGreutate(double greutate)
    {
        this->greutate = greutate;
    }

    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }

    char* getNume() {
        return nume;
    }
    double getGreutate() {
        return greutate;
    }
    int getVarsta() {
        return varsta;
    }
    void display() {
        cout << "\nNume: " << nume;
        cout << "\nGreutate: " << greutate;
        cout << "\nVarsta: " << varsta;
    }

    ~Persoana()
    {
        cout << "\nStergere persoana";
        delete[] nume;
        this->greutate = 0.;
        this->varsta = 0;
    }
    friend class Analize;
};

class Analize {
    Persoana* p;
    int n;
public:
    Analize() {
        p = new Persoana[dim];
        n = dim;
    }
    Analize(int j) {
        p = new Persoana[j];
        n = j;
    }
    void introduce() {
        int j;
        char nume[MAX];
        double greutate;
        int varsta;
        for (j = 0; j < n; j++) {
            cout << "\nDatele pentru persoana: " << j + 1; cout << "\nNume: ";
            cin >> nume;
            p[j].setNume(nume);
            cout << "\nGreutate: ";
            cin >> greutate;
            p[j].setGreutate(greutate);
            cout << "\nVarsta: ";
            cin >> varsta;
            p[j].setVarsta(varsta);
            
        }
    }

    /*Persoana* sortare()
    {
        char c;
        while (1)
        {
            cout << "\nSortare (g-greutate, n-nume, v-varsta, e-exit) ?";
            cin >> c;
            switch (toupper(c))
            {
            case 'G': 
            {Persoana aux;
            int ok;
            do{
                ok = 0;
                for (int i = 0; i < n - 1; i++)
                    if ((p + i)->greutate < (p + i + 1)->greutate)
                    {
                        aux = *(p + i);
                        *(p + i) = *(p + i + 1);
                        *(p + i + 1) = aux;

                        ok = 1;

                    }

            } while (ok == 1);

            for (int i = 0; i < n ; i++)
                p[i].display();

            }break;
            case 'N': {Persoana aux;
                int ok;
                do {
                    ok = 0;
                    for (int i = 0; i < n - 1; i++)
                        if (strcmp((p+i)->nume,(p+i+1)->nume)>0)
                        {
                            aux = p[i];
                            p[i] = p[i + 1];
                            p[i + 1] = aux;

                            ok = 1;

                        }

                } while (ok == 1);

                for (int i = 0; i < n ; i++)
                    p[i].display();

            }break;
            case 'V':int v;
            {Persoana aux;
            int ok;
            do {
                ok = 0;
                for (int i = 0; i < n - 1; i++)
                    if ((p + i)->varsta < (p + i + 1)->varsta)
                    {
                        aux = *(p + i);
                        *(p + i) = *(p + i + 1);
                        *(p + i + 1) = aux;

                        ok = 1;

                    }

            } while (ok == 1);

            for (int i = 0; i < n ; i++)
                p[i].display();

            }
                break;
            case 'E':return 0;
            default: cout << "\n\t\tAti introdus o optiune inexistenta!!"; break;
            }
        }

    }*/

    //Persoana* operator[ ](char* nume) {
    //    for (int i = 0; i < n; i++)
    //        if (strcmp(p[i].nume, nume) == 0) p[i].display();
    //    return NULL;
    //}
    ////Indexare dupa greutate
    //Persoana* operator[ ](double gr) {
    //    for (int i = 0; i < n; i++)
    //        if (p[i].greutate == gr) p[i].display();
    //    return NULL;
    //}//op[] greutate
    //
    // //Indexare dupa index
    //Persoana* operator[ ](int index) {
    //    if ((index >= 1) && (index <= n)) p[index].display();
    //    else { cout << "\nIndex gresit"; return NULL; }
    //}//op[]index

    ~Analize()
    {
        cout << "\nStergere analize";
        delete[]p;
    }
};

int main()
{
    int n;
    char c;
    char nume[MAX];
    double greutate;
    int varsta;
    cout << "\nCate persoane? ";
    cin >> n;
    Analize a(n);
    a.introduce();
    a.sortare();
    /*while (1)
    {
        cout << "\nOptiunea (g-greutate, n-nume, i-index, e-exit) ?";
        cin >> c;
        switch (toupper(c))
        {
        case 'G':double g;
            cout << "Greutatea: ";
            cin >> g;
            a[g];
            break;
        case 'N':char n[MAX];
            cout << "Numele: ";
            cin >> n;
            a[n];
            break;
        case 'I':int i;
            cout << "Nr index: ";
            cin >> i;
            a[i];
            break;
        case 'E':return 0;
        default: cout << "\n\t\tAti introdus o optiune inexistenta!!"; break;
        }
    }*/

    char c;
    while (1)
    {
        cout << "\nSortare (g-greutate, n-nume, v-varsta, e-exit) ?";
        cin >> c;
        switch (toupper(c))

}
