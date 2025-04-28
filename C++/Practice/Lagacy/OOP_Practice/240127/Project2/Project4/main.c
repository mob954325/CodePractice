#include <stdio.h>
#include "test.h"

int global = 0;

int main()
{
	global = 2000;
	TextPrintGlobal();

	return 0;
}