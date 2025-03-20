// #pragma - 컴파일러에게 특정 옵셔이나 라이브러리 형태 지정
#include <stdio.h> // #include -> 특정 파일 가져오기

#define DEBUG

// 매크로 정의 확장
#define MAX_BUFFER_SIZE 1024 // 대상 변환형(Object-like marcros)
#define CIRCLESIZE(x) ((x) * (x) * 3.141592) // 유사 함수 변환형(function-like macros)

int main()
{
	// 조건부 컴파일 테스트
	int a = 0;
	printf("111111\n");
#ifdef DEBUG
	printf("Debug Area\n");
#endif // DEBUG

#ifdef DEBUG2 // DEBUG2sms 정의되지 않아서 내용이 실행안됨
	printf("Debug2 Area\n");
#endif // DEBUG

#if a == 0
	printf("a == 0\n");	
#endif // 0

#if a == 1 // a 가 1이 아니므로 내용이 실행안됨
	printf("a == 1\n");
#endif // 1
	printf("222222\n");

	// 매그로 사용
	printf("%d\n", MAX_BUFFER_SIZE);
	printf("radius 5 circle size %f\n", CIRCLESIZE(5));

}