#include <stdio.h>

extern int global; // int �� global ������ �ܺο� �־�

void TextPrintGlobal()
{
	printf("text.c TestPrintGlobal global = %d\n", global);
}