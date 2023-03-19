// Copacel_Narcis-Mihail_Lab08_P4.cpp 

#include <iostream>
using namespace std;

class MyClass
{
public:
    static int var_static;
    MyClass()
    {
        var_static++;

    }


};

int MyClass::var_static;

int main()
{
    MyClass x, y, z,a,s,h,j,k,l;
    cout <<"\tAu fost create "<<MyClass::var_static<<" obiecte";
}
