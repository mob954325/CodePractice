#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	FILE* fp;
	// 파일쓰기   fp = fopen("test.txt", "w");
	if (fp == NULL) 
	{
		printf("파일 열기에 실패\n");   
		return;
	}
	fputc('a', fp);   // fputc: 한 문자 파일 출력함수
	for (int i = 'a'; i <= 'z'; i++)
	{ 
		fputc((char)i, fp); 
	}
	fclose(fp);   // 파일 닫기

	// 파일 읽기  
	// 파일 열기 
	fp = fopen("test.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");  
		return;
	}
	char c;
	while ((c = fgetc(fp)) != EOF) 
	{   
		// fgetc는 한문자 읽기    
		putchar(c);  
	}
		fclose(fp);


		return 0;
	}