// Copacel_Narcis-Mihail_Lab01_P5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

double radical(int x);
double radical(int& x,int b);
double radical(int* x);


int main()
{
    int a, b;
    int& c = a;
    int* pb;
    pb = &b;

    cout << "Introduceti valoari intregi:"; cin >> a>>b;

    cout << "Radicalul este egal cu (transmiterea prin valoare): " << radical(a)<<endl;
    cout << "Radicalul este egal cu(transmiterea prin referinta): " << radical(b)<<endl;
    cout << "Radicalul este egal cu(transmitere prin adresa): " << radical(a,0);
}

double radical(int x)
{
    return sqrt((float)(x));
}

double radical(int& x,int b)
{
    return sqrt((float)(x));
}

double radical(int *x)
{
    int n;
    n = *x;
    return sqrt((float)(n));
}