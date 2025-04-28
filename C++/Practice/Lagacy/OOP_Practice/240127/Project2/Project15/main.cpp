#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int buff[] = { 10, 20, 30, 40, 50 };
	FILE* fp;

	fp = fopen("binary.bin", "wb");   // 바이너리 모드 쓰기
	if (fp == NULL) 
	{
		printf("파일열기 실패");  
		return;
	}

	int size = sizeof(buff[0]); 
	int count = sizeof(buff) / sizeof(buff[0]);
	fwrite(buff, size, count, fp); // 바이너리모드로 쓰는 함수   
	fclose(fp);

	int output[5]; 
	fp = fopen("binary.bin", "rb");   // 바이너리 모드 읽기 오픈
	if (fp == NULL) 
	{ 
		printf("파일 열기 실패"); 
		return; 
	}

	fread(output, size, count, fp);   // 바이너리 모드 읽는 함수
	for (int i = 0; i < count; i++)
	{
		printf("output[%d] = %d\n", i, output[i]);
	}

	fclose(fp);
	return 0;
}