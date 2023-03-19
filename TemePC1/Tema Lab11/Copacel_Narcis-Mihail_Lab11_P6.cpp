// Copacel_Narcis-Mihail_Lab11_P6.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Record
{
private:
    char artist[20];
    char titlu[20];
    int min, sec;

public:
    char* getArtist()
    {
        return artist;
    }

    char* getTitlu()
    {
        return titlu;
    }

    int getMin()
    {
        return min;
    }

    int getSec()
    {
        return sec;
    }

    void setArtist(char* a)
    {
        strcpy(artist, a);
    }

    void setTitlu(char* t)
    {
        strcpy(titlu, t);
    }

    void setMin(int m)
    {
        min = m;
    }

    void setSec(int s)
    {
        sec = s;
    }
};

class Playlist
{

    Record* p;
    int n;
public:
    Playlist(int n)
    {
        this->n = n;
        p = new Record[n];
    }

    void init()
    {
        char t[20], a[20];
        int m, s;
        for (int i = 0; i < n; i++)
        {
            cout << "Piesa " << i + 1 << ": \n";
            cout << "\tTitlu: ";
            cin >> t;
            p[i].setTitlu(t);
            cout << "\tArtist: ";
            cin >> a;
            p[i].setArtist(a);
            cout << "Durata: \n";
            cout << "\nMinute: ";
            cin >> m;
            p[i].setMin(m);
            cout << "\tSecunde: ";
            cin >> s;
            p[i].setSec(s);
        }
    }

    int getNr()
    {
        return n;
    }

    Record getRecord(int n)
    {
        return p[n];
    }

    void setRecord(Record r, int n)
    {
        p[n] = r;
    }

    virtual void ordonare(int c) = 0;
};

class PlaylistImplementation :public Playlist
{
public:
    PlaylistImplementation(int n) :Playlist(n) {}

    void afis()
    {
        for (int i = 0; i < getNr(); i++)
        {
            cout << "\n\tTitlu: " << getRecord(i).getTitlu();
            cout<<"\n\tArtist: "<< getRecord(i).getArtist();
            cout<<"\n\tDurata: "<<getRecord(i).getMin()<<":"<< getRecord(i).getSec();
        }
    }

    void ordonare(int c) override
    {
        switch (c)
        {
        case 1:
        {
            cout << "\nOrdonare alfabetica dupa titlu: \n";
            for (int i = 0; i < getNr() - 1; i++)
                for (int j = i + 1; j < getNr(); j++)
                {
                    if (strcmp(getRecord(i).getTitlu(), getRecord(j).getTitlu()) > 0)
                    {
                        Record aux;
                        aux = getRecord(i);
                        setRecord(getRecord(j), i);
                        setRecord(aux, j);
                    }
                }
        }
        break;
        case 2:
        {  cout << "\nOrdonare alfabetica dupa artist: \n";
        for (int i = 0; i < getNr() - 1; i++)
            for (int j = i + 1; j < getNr(); j++)
            {
                if (strcmp(getRecord(i).getArtist(), getRecord(j).getArtist()) > 0)
                {
                    Record aux;
                    aux = getRecord(i);
                    setRecord(getRecord(j), i);
                    setRecord(aux, j);
                }
            }
        }
        break;
        case 3:
        {
            cout << "\nOrdonare crescatoare dupa durata: \n";
            for (int i = 0; i < getNr() - 1; i++)
                for (int j = i + 1; j < getNr(); j++)
                {
                    if (getRecord(i).getMin()> getRecord(j).getMin())
                    {
                        Record aux;
                        aux = getRecord(i);
                        setRecord(getRecord(j), i);
                        setRecord(aux, j);
                    }
                    else
                        if(getRecord(i).getMin() == getRecord(j).getMin())
                            if (getRecord(i).getSec() > getRecord(j).getSec())
                            {
                                
                                    Record aux;
                                    aux = getRecord(i);
                                    setRecord(getRecord(j), i);
                                    setRecord(aux, j);
                                
                            }
                }
        }
        break;

        default:
            cout << "\n\t\tTrebuie sa alegeti intre 1, 2 sau 3!!";
            break;
        }
    }
};

void main()
{
    int n;
    cout << "\nCate inregistrari doriti sa introduceti?";
    cin >> n;
    PlaylistImplementation obj(n);
    obj.init();

    int cont;
    cout << "\nDupa ce criteriu doriti sa ordonati inregistrarile? (1 - titlu / 2 - artist / 3 - durata)";
    cin >> cont;

    obj.ordonare(cont);

    cout << "\nLista ordonata de inregistrari este: ";
    obj.afis();

}
