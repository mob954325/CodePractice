#include <stdio.h>
// 함수의 인자 전달 방식
// 1. call by value (값에 의한 호출)
// 2. call by address (주소값에 의한 호출)
void Swap(int a, int b) { 
	// 값에 의한 호출  
	int temp = 0;
	temp = a;  
	a = b;  
	b = temp;
}
void PSwap(int* pa, int* pb) {   
	// 주소값에 의한 호출 
	int temp = 0;
	temp = *pa;   *pa = *pb;   *pb = temp;
}
int main() {
	int a = 20;   int b = 30;
	printf("before Swap(int, int) a = %d, b = %d\n", a, b); 
	Swap(a, b); 
	// 값에 의한 호출 
	printf("after Swap(int, int) a = %d, b = %d\n", a, b);
	printf("\n\n");  
	printf("before PSwap(int*, int*) a = %d, b = %d\n", a, b);  
	PSwap(&a, &b); 
	// 주소값에 의한 호출  
	printf("after PSwap(int*, int*) a = %d, b = %d\n", a, b);
}