#include <iostream>
#include <math.h>

using namespace std;

int a;

int main()
{
	while (true)
	{
		cin >> a;

		if (a % 2 == 1) break;

		cout << "È¦¼ö°¡ ¾Æ´Õ´Ï´Ù\n";
	}

	char alpha = 'a';

	for (int i = 1; i <= a; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (i + j >= a)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}