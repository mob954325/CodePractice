#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int t;

int main()
{
	scanf("%d", &t);

	for (int caseCount = 0; caseCount < t; caseCount++)
	{
		int a, b;

		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}