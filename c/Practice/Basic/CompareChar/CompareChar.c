#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
	char* c1 = '=';
	char c2 = '=';
	const char* s1 = "=";

	printf("===========\n\n");
	printf("%d\n", c1);		// 코드
	printf("%c\n", c1);		// 문자
	printf("%d\n", &c1);	// 주소

	printf("===========\n\n");
	printf("%d\n", c2);		// 코드
	printf("%c\n", c2);		// 문자
	printf("%c\n", &c2);	// 문자 -> ?

	printf("===========\n\n");
	printf("%d\n", s1);		// 주소
	printf("%s\n", s1);		// 문자열
	printf("%c\n", *(s1 + 0)); // 아마 문자열에서 첫 문자
}
