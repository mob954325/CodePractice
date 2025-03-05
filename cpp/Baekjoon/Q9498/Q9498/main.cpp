#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int score;

int main()
{
	scanf("%d", &score);

	if (score > 90 - 1)
	{ 
		printf("A");
	}
	else if (score > 80 - 1)
	{
		printf("B");
	}
	else if (score > 70 - 1)
	{
		printf("C");
	}
	else if (score > 60 - 1)
	{
		printf("D");
	}
	else
	{
		printf("F");
	}
}