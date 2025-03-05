#include <stdio.h>

int main()
{

	short a = -32768;
	long b = -2786489;
	int c = 21000000;

	printf("a = %d, b = %d, c = %d\n", a, b, c);

	float d = 234.334;
	double f = 1.2321412;

	printf("d = %.1f, f = %.5lf\n", d, f);

	char h = 'a';
	char j = 'B';

	printf("i = %c, j = %c\n", h, j);

	printf("str = %s\n", "monster");
	return 0;
}