// Copacel_Narcis-Mihail_Lab08_P3.cpp 

#include <iostream>
using namespace std;

class Repository
{
private:
    int a, b;
public:

    Repository()
    {
        a = 0;
        b = 0;
    }
    Repository(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    friend class Mathematics;
};

class Mathematics
{
public:
    int ad(Repository& x)
    {
        return x.a + x.b;
    }
    int sc(Repository& x)
    {
        return x.a - x.b;
    }
    int pr(Repository& x)
    {
        return x.a * x.b;
    }
    float div(Repository& x)
    {
        return float(x.a) / x.b;
    }
};

int main()
{
    Repository x(3, 3);
    Mathematics calc;

    cout << "\tSuma este egala cu: " << calc.ad(x);
    cout << "\n\tDiferenta este egala cu: " << calc.sc(x);
    cout << "\n\tProdusul este egal cu: " << calc.pr(x);
    cout << "\n\tImpartirea este egala cu: " << calc.div(x);


}
