#include <stdio.h>
// 변수
// 접근범위, 존속기간
// 변수는 생성위치와 사용되는 키워드에 따라서 변수의 성격이 틀립니다.
int global = 0;     
// 외부변수, 전역변수

int SetScore(int value) {  
	// 매개변수 value 도 로컬변수, 자동변수 
	static int score = 0;  // 로컬변수, 정적변수 
						   // 정적변수는 함수가 호출될때 한번만들어지고  
						   // 변수가 없어지지 않습니다. 프로그램 생명주기 내내 유지가 됩니다.
	score += value;
	global = 2000;
	return score;
}
int main() {
	int a = 20; // 로컬변수, 자동변수
	{      
		int c = 100; // 로컬변수(지역변수), 자동변수   
	}
	//c = 200;

	for (int i = 0; i < 10; i++) 
	{
		SetScore(i);
	}
	int sum = SetScore(0);  
	printf("Sum = %d\n", sum);

	global = 1000;
	return 0;
}