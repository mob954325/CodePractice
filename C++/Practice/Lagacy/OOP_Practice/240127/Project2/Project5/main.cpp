#include <stdio.h>

int* pSetScore(int value) {
	int sum = 0;
	sum += value;
	return &sum;  // sum 자동변수의 주소값을 리턴
}

int* pSetScoreStatic(int value) {
	static int sum = 0;
	sum += value;	
	return &sum; // sum 정적변수의 주소값을 리턴
}

int main() {
	printf("pSetScore 함수\n"); 
	int* pScore = pSetScore(100);
	printf("*pScore = %d\n", *pScore);
	printf("*pScore = %d\n", *pScore); 
	printf("*pScore = %d\n", *pScore);
	printf("\n\npSetScoreStatic\n");  

	pScore = pSetScoreStatic(2000); 
	printf("*pScore = %d\n", *pScore);
	printf("*pScore = %d\n", *pScore); 
	printf("*pScore = %d\n", *pScore);

	return 0;
}