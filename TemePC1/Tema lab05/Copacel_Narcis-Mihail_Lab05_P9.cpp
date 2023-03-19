// Copacel_Narcis-Mihail_Lab05_P9.cpp 

#include <iostream>
using namespace std;

class Fractie
{
private: int a, b;

public:
    void setFr(int x, int y) { a = x; b = y; }
    int getNumar() { return a; }
    int getNumit() { return b; }
    void simplifica();
};

void Fractie::simplifica()
{
    int x, y,i=2;
    x = a;
    y = b;
    
    while (a != 1 && b != 1 && i<=a && i<=b) 
    {
        
        if (x % i == 0 && y % i == 0)
        {
            x /= i;
            y /= i;
            i++;

        }
        else
            i++;
    }
    setFr(x, y);
    cout << getNumar() << "/" << getNumit();
}

int main()
{
    Fractie f1, f2;
    int x, y;
    cout << "Prima factie: " << f1.getNumar() << "/" << f1.getNumit();
    cout << "\nA doua factie: " << f2.getNumar() << "/" << f2.getNumit();

    cout << "\n\n\tIntroduceti prima fractie:";
    cout << "\nNumarator:"; cin >> x;
    cout << "Numitor:"; cin >> y;
    f1.setFr(x, y);

    cout << "\n\tIntroduceti a doua fractie:";
    cout << "\nNumarator:"; cin >> x;
    cout << "Numitor:"; cin >> y;
    f2.setFr(x, y);

    cout << "\nPrima factie: " << f1.getNumar() << "/" << f1.getNumit();
    cout << "\nA doua factie: " << f2.getNumar() << "/" << f2.getNumit();

    cout << "\n\nFractia 1 simplificata este:";
    f1.simplifica();

}
