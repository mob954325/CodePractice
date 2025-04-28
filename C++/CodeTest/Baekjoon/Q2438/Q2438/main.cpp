#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int num = 0; num < i + 1; num++)
		{
			printf("*");
		}

		if (i < n - 1) printf("\n");
	} 
}