#include "Test1.h"
#include <stdio.h>

namespace Test
{
	int a;
	int array1[2];

	void Function1()
	{
		array1[0] = 1;
		array1[1] = 2;
	}

	void Print()
	{
		printf("asf");
		printf("aa%d // %d", array1[0], array1[1]);
	}
}