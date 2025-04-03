#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW_COUNT 3
#define MAX_BUFFER_SIZE 1024

void EditByPointer(int** array)
{
	for (int i = 0; i < MAX_ROW_COUNT; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = 11;
		}
	}
}

void EditByDoublePointer(int*** array)
{
	for (int i = 0; i < MAX_ROW_COUNT; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			(*array)[i][j] = 99;
		}
	}
}

void Show(int** array)
{
	for (int i = 0; i < MAX_ROW_COUNT; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("( %d, %d ) : %d\n",i, j, array[i][j]);
		}
	}
}

int main()
{
	int** array = (int**)malloc(MAX_ROW_COUNT * sizeof(int*));

	for (int i = 0; i < MAX_ROW_COUNT; i++)
	{
		array[i] = (int*)malloc(MAX_BUFFER_SIZE * sizeof(int));

		for (int j = 0; j < 5; j++)
		{
			array[i][j] = j;
		}
	}

	printf("Before Edit\n");
	Show(array);

	printf("Edit By Pointer\n");
	EditByPointer(array);
	Show(array);

	printf("Edit By DoublePointer\n");
	EditByDoublePointer(&array); // 이중 배열의 주소값을 준다.
	Show(array);
}