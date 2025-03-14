#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	// 파일열기
	// 플래그는 문서파일 참조
	// https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
	
	// ============================================
	// FILE - 연 파일의 포인터 -> void*형 구조체로 이뤄져있음
	FILE* targetFile = fopen("targetFile.txt", "r+");
	if (targetFile == NULL) printf("No TargetFile.txt file in GetFile1");

	// fgetc -> 한 문자씩 가져오기
	int i = 0, ch;
	for (i = 0; !feof(targetFile); i++)
	{
		ch = fgetc(targetFile);
		printf("%c", ch);
	}

	printf("\n\n");
	if(targetFile != NULL) fclose(targetFile);

	// fgets -> 한 문자열씩 가져오기
	targetFile = fopen("targetFile.txt", "r+");
	char buffer[100];
	for (i = 0; !feof(targetFile); i++)
	{
		fgets(buffer, 100, targetFile);
		printf("%s", buffer);
	}	
	if(targetFile != NULL) fclose(targetFile);

	// 파일 쓰기 ============================================
	char* buffer2 = (char*)malloc(100 * sizeof(char));
	printf("\n\nwrite something\n");
	scanf("%s", buffer2);
	
	// fwrite
	FILE* myFile = fopen("myFile.txt", "wt+");
	fwrite(buffer2, sizeof(char), 100, myFile);	// 바이너리 형식 데이터 저장


	fclose(myFile);
	myFile = fopen("myFile.txt", "r");
	
	char* buffer3 = (char*)malloc(100 * sizeof(char));
	fgets(buffer3, 100, myFile);
	
	printf("%s\n", buffer3);

	free(buffer3);
	fclose(myFile);

	// fprintf, fwrite ============================================
	FILE* myFile2 = fopen("myFile2.txt", "wt+");
	char* buffer4 = (char*)malloc(100 * sizeof(char));
	printf("\n\nwrite something\n");
	scanf("%s", buffer4);
	fprintf(myFile2, buffer4);	// 서식에 맞춰서 텍스트 데이터 작성

	fclose(myFile2);
	myFile2 = fopen("myFile2.txt", "r");

	char* buffer5 = (char*)malloc(100 * sizeof(char));
	fscanf(myFile2, buffer5);	// 서식에 맞춰서 파일 데이터 가져오기

	printf("%ws\n", buffer5);	// 유니코드라　글자　깨짐

	free(buffer5);
	fclose(myFile2);
}