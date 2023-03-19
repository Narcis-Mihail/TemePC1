// Copacel_Narcis-Mihail_Lab02_P13.cpp 

#include <iostream>
using namespace std;

float recursiv(int n);
float nerecursiv(int n);
int main()
{
	int n;
	cin >> n;
	cout << "\nSerie armonica recursiv: " << recursiv(n);
	cout << "\nSerie armonica nerecursiv: " << nerecursiv(n);

}

float recursiv(int n)
{
	if (n == 1)
		return 1;
	else return (float)1 / n + recursiv(n - 1);
}

float nerecursiv(int n)
{
	float serie=0;
	for (int i = 1; i <= n; i++)
		serie += (float)1 / i;
	return serie;
}