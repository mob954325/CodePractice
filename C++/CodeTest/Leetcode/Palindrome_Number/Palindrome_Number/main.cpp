#include <cstdio>

using namespace std;

int main()
{
	int Num = -121;
	int check = Num;

	while (check != 0)
	{
		int current = check % 10;
		printf("%d\n", current);

		check /= 10;
	}

}