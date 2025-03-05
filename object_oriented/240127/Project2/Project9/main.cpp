#include <stdio.h>
#include <stdlib.h>// 동적메모리

int main() {
	int size = 10;

	// malloc은 동적메모리 공간을 할당받고 초기화를 하지 않습니다. 
	double* parray = (double*)malloc(sizeof(double) * size); // 동적메모리 공간을 할당
	printf("-- malloc --\n");
	for (int i = 0; i < size; i++)
	{
		printf("parray[%d] = %lf\n", i, parray[i]); 
	}

	free(parray);   // 동적메모리 반환
	printf("\n\n");

	// calloc은 할당된 동적메모리를 0으로 초기화한다.   
	parray = (double*)calloc(size, sizeof(double));
	printf("\n--- calloc ---\n");
	for (int i = 0; i < size; i++) 
	{ 
		printf("parray[%d] = %lf\n", i, parray[i]);
	}
	printf("\n\n");
	size = 20;

	// realloc은 할당받은 메모리공간을 재할당 할때 사용합니다.  
	parray = (double*)realloc(parray, sizeof(double) * size);
	printf("\n--- realloc ----\n");  
	for (int i = 0; i < size; i++)
	{
		printf("parray[%d] = %lf\n", i, parray[i]);
	}

	printf("\n\nprintArray\n");
	// double형 저장공간을 int 저장공간으로 바꿈  

	int* pintArray = (int*)parray;
	for (int i = 0; i < size * 2; i++) 
	{ 
		pintArray[i] = i; 
	}
	printf("\ndouble형 저장공간을 int형 저장공간으로 형변환하여 값을 저장하고 출력\n");   // 메모리공간에 저장하는 값은 확정적이지 않다.   for (int i = 0; i < size * 2; i++) {      printf("pintArray[%d] = %d\n", i, pintArray[i]);   }
	free(pintArray);

	return 0;
}