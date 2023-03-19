using namespace std;
class myString
{
	char x[100];
public:
	void Sir(char y[]) { strcpy(x, y); }
	int getLungime() { return strlen(x); }
	int getLastIndex(char c);
	void Majusc();
	void minus();
	int nrApar(char c);
};

int myString::getLastIndex(char c)
{

	for (int i = getLungime() - 1; i >= 0; i--)
		if (x[i] == c)
			return i + 1;
		else
			return 0;
	
}

void myString::Majusc()
{
	int i;
	for (i = 0; i < strlen(x); i++)
		if (x[i] >= 'a' && x[i] <= 'z')
			x[i] = x[i] - 'a' + 'A';

	cout << x;
	
}

void myString::minus()
{
	int i;
	for (i = 0; i < strlen(x); i++)
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] = x[i] - 'A' + 'a';

	cout << x;
}

int myString::nrApar(char c)
{
	int k = 0;
	for (int i = 0; i < getLungime(); i++)
	{
		if (x[i] == c)
			k++;
	}

	return k;
}
