#include <stdio.h>

extern int global; // int 형 global 변수가 외부에 있어

void TextPrintGlobal()
{
	printf("text.c TestPrintGlobal global = %d\n", global);
}