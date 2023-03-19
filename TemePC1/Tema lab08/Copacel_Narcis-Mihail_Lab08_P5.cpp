// Copacel_Narcis-Mihail_Lab08_P5.cpp 

#include <iostream>
using namespace std;

class MyClass
{
private:
    static int var_static;
public:
    MyClass()
    {
        var_static++;
    }
    static int getVar_Static()
    {
        return var_static;
    }
};

int MyClass::var_static;

int main()
{
    MyClass x, y, z, j, h, g, f, d;
    cout << "Au fost create " << MyClass::getVar_Static() << " obiecte";
}
