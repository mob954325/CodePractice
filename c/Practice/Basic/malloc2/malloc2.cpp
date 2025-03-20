#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
	char arr[MAX_BUFFER_SIZE] = "This is string";

	char** arr2d = (char**)malloc(4 * sizeof(char*)); // char**의 크기 할당
	int size = 4;
	for (int i = 0; i < 4; i++)
	{
		arr2d[i] = (char*)malloc(6 * sizeof(char)); // char이 5개들어가는 배열 크기 할당
		for (int j = 0; j < 5; j++)
		{
			arr2d[i][j] = 'a';
		}
		arr2d[i][5] = '\0';
	}

	// 길이가 5인 문자열 4개를 담은 2차원 배열 arr2d
	// a a a a a
	// a a a a a
	// a a a a a
	// a a a a a
	// char** -> 문자열을 가리킴
	// char*  -> 문자열의 요소값을 가리킴

	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", arr2d[i]);
	}

	// 동적 할당 해제하기
	for (int i = 0; i < 4; i++)
	{
		free(arr2d[i]);
	}

	free(arr2d);
}