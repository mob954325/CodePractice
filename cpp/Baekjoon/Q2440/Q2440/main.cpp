#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int starCount = n; starCount > i; starCount--)
		{
			printf("*");
		}

		if(i < n - 1) printf("\n");
	}
}