#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 1000

int main()
{
	// 스택 선언
	// 선언하려면 정수 리터럴 도는 상수식으로 요소 수를 지정해야합니다.
	// -> 컴파일러가 할당된 스택 공간의 양을 알아야하기 때문
	int stackNumbers[1000] = { 0, };
	stackNumbers[0] = 1;
	stackNumbers[1] = 22;

	for (int i = 0; i < 1000; i++)
	{
		printf("%d : %d\n", i, stackNumbers[i]);
	}

	// 힙 선언
	// 힙으로 배열을 선언할 때 밑의 내용은 사용자 책임입니다.
	// 1. 항상 원래 포인터 주소의 복사본을 유지하므로 배열이 더 이상 필요하지 않을 때 메모리를 삭제 할 수 있다 (free메소드 사용)
	// 2. 배열 범위를 지나 포인터 주소를 증가시키거나 감소 시키지 않는다. (버퍼 오버런 -> 그래도 작동은 됨)
	int* heapNumbers = (int*)malloc(MAX_HEAP_SIZE * sizeof(int));
	heapNumbers[0] = 33;
	heapNumbers[1] = 44;

	for (int i = 0; i < MAX_HEAP_SIZE; i++)
	{
		printf("%d : %d\n", i, heapNumbers[i]);
	}

	free(heapNumbers); // 할당 해제
}