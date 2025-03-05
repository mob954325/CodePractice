#include <stdio.h>
// �Լ��� ���� ���� ���
// 1. call by value (���� ���� ȣ��)
// 2. call by address (�ּҰ��� ���� ȣ��)
void Swap(int a, int b) { 
	// ���� ���� ȣ��  
	int temp = 0;
	temp = a;  
	a = b;  
	b = temp;
}
void PSwap(int* pa, int* pb) {   
	// �ּҰ��� ���� ȣ�� 
	int temp = 0;
	temp = *pa;   *pa = *pb;   *pb = temp;
}
int main() {
	int a = 20;   int b = 30;
	printf("before Swap(int, int) a = %d, b = %d\n", a, b); 
	Swap(a, b); 
	// ���� ���� ȣ�� 
	printf("after Swap(int, int) a = %d, b = %d\n", a, b);
	printf("\n\n");  
	printf("before PSwap(int*, int*) a = %d, b = %d\n", a, b);  
	PSwap(&a, &b); 
	// �ּҰ��� ���� ȣ��  
	printf("after PSwap(int*, int*) a = %d, b = %d\n", a, b);
}