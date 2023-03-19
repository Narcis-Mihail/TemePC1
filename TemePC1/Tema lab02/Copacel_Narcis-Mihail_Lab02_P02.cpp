// Copacel_Narcis-Mihail_Lab02_P02.cpp 
#include <iostream>
#include<assert.h>
using namespace std;

int comb(int n, int k);

int main()
{
	int n, k;
	cin >> n >> k;
	assert(n >= k);

	cout << "Combinari de " << n << " luate de cate " << k << " este :" << comb(n, k);


}

int comb(int n, int k)
{
	if (n == 0 || n == k) return 1;
	return (n / (n - k)) * comb(n - 1, k);
}