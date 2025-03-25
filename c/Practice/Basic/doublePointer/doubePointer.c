#include <stdio.h>
#include <stdlib.h>

void allocationMemory2(int** ptr)
{
	*ptr = (int*)malloc(sizeof(int));
	**(ptr) = 222;	
}

void allocationMemory1(int* ptr)
{
	ptr = 222; // x
}

void SetMessage(char** pTarget)
{
	*pTarget = "인간은 패배하도록 창조된 게 아니야.";
}

int main()
{
	// 일반 값 확인
	int i = 100;
	int* p = &i;
	int** pp = &p;

	*p = 200; // i의 값 변경
	printf("i : %d, *p : %d, **p : %d\n", i, *p, **pp);
	**pp = 300; // 
	printf("i : %d, *p : %d, **p : %d\n", i, *p, **pp);

	// *자료형 확인
	int* p1 = NULL;
	allocationMemory1(p1);
	allocationMemory2(&p1);

	if (p1 != NULL)
	{
		printf("p1 : %d\n", *p1);
		free(p1);
	}

	p1 = NULL;

	// char*
	char* pMsg;
	SetMessage(&pMsg);
	printf("%s\n\t- [노인과 바다]에서", pMsg);
}