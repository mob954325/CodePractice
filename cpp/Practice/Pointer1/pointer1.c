#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* array;
	array = (int*)malloc(sizeof(int) * 2);

	int a, *pa;
	a = 35;
	pa = &a;

	printf("a : %d\n", a);
	printf("a address : %d\n", &a);
	printf("pa : %d\n", *pa);
	printf("pa address : %d\n", pa);
	printf("pa address + 1: %d\n", pa + 1); // int형 사이즈 만큼 이동 (+4)
	printf("\n");
	printf("*pa + 1 : %d\n", *pa + 1);		// 포인터가 가리키고 있는 지수에 저장된 값 1증가
	printf("*(pa + 1) : %d\n", *(pa + 1));	// 포인터가 가지고 있는 주소를 1증가 시킨 후 주소값을 구함
	printf("*pa++ : %d\n", *pa++);			// 포인터가 가리키고 있는 주소의 저장한 값을 1증가(pa의 값 변화 없음)
	printf("(*pa)++ : %d\n", (*pa)++);		// 포인터가 가리키고 있는 주소의 저장한 값을 구한 다음 그 값에 1을 증가 (pa의 값 변화) 
	printf("*++pa : %d\n", *++pa);			// 포인터를 1 증가 시킨 다음 해당 주소에 있는 값을 구함
	printf("++*pa + 1 : %d\n", ++*pa);		// 포인터가 가리키고 있는 값을 구한 다음에 그 값에 1을 더함
	a = NULL;
	free(array);
}