// Copacel_Narcis-Mihail_Lab11_P5.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Sir
{
public:
    virtual void concatenare(char* s1, char* s2) = 0;
    virtual void intretesere(char* s1, char* s2) = 0;
    virtual void inversare(char* s) = 0;
};

class Sir_Derivata :public Sir
{
public:
    void concatenare(char* s1, char* s2) override
    {
        strcat(s1, s2);
        cout << "\nRezultatul concatenarii: " << s1;
    }

    void intretesere(char* s1, char* s2) override
    {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int min = l1 > l2 ? l2 : l1;
        int k = 0;
        char* r = new char[l1 + l2];
        for (int i = 0; i < min; i++)
        {
            r[k++] = s1[i];
            r[k++] = s2[i];
        }
        if (l1 > l2)
            for (int i = min; i < l1; i++)
                r[k++] = s1[i];
        else
            for (int i = min; i < l2; i++)
                r[k++] = s2[i];
        r[k] = '\0';
        cout << "\nRezultatul intreteserii: " << r;
    }

    void inversare(char* s) override
    {
        int l = strlen(s);
        char* s1 = NULL;
        s1 = new char[l];
        for (int i = 0; i < l; i++)
            s1[i] = s[l - i - 1];
        s1[l] = '\0';
        cout << "\nRezultatul inversarii: " << s1;
    }
};

int main()
{
    char s1[20], s2[20], s3[20];
    Sir_Derivata obj;
    cout << "\nIntroduceti primul sir: ";
    cin >> s1;
    cout << "\nIntroduceti al doilea sir: ";
    cin >> s2;
    cout << "\nIntroduceti al treilea sir: ";
    cin >> s3;

    obj.concatenare(s1, s2);
    obj.intretesere(s1, s2);
    obj.inversare(s3);
}

