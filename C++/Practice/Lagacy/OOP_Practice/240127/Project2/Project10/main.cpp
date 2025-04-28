#include <stdio.h>
#include <stdlib.h>
int main() {
	int size = 0;
	printf("입력할 숫자의 갯수를 입력하세요: "); 
	scanf_s("%d", &size);
	int* parray = (int*)malloc(sizeof(int) * size); // 동적메모리 할당
	for (int i = 0; i < size; i++) { parray[i] = i; }
	for (int i = 0; i < size; i++) { printf("parray[%d] = %d\n", i, parray[i]); }
	free(parray);   // 동적메모리 반환


	return 0;
}