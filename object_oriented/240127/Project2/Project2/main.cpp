#include <stdio.h>
struct Ret { int addValue;   int subValue;   int mulValue;   float divValue; };

struct Ret AllCalculate(int a, int b) {
	struct Ret ret;   // 구조체 변수
	ret.addValue = a + b;  
	ret.subValue = a - b; 
	ret.mulValue = a * b; 
	ret.divValue = a / (float)b;
	return ret;
}
// 포인터사용
void PAllCalculate(int a, int b, int* paddValue, int* psubValue, int* pmulValue, float* pdivValue) 
{  
	*paddValue = a + b; 
	*psubValue = a - b;  
	*pmulValue = a * b;  
	*pdivValue = a / (float)b;
}

int main() {
	int a = 20;   int b = 30;
	struct Ret ret = AllCalculate(a, b);
	printf("구조체 이용\n");
	printf("%d + %d = %d\n", a, b, ret.addValue);
	printf("%d - %d = %d\n", a, b, ret.subValue);
	printf("%d x %d = %d\n", a, b, ret.mulValue);
	printf("%d / %d = %f\n", a, b, ret.divValue);
	int addValue;
	int subValue;
	int mulValue;
	float divValue;
	printf("\n포인터 이용\n");
	PAllCalculate(a, b, &addValue, &subValue, &mulValue, &divValue);
	printf("%d + %d = %d\n", a, b, addValue);
	printf("%d - %d = %d\n", a, b, subValue);
	printf("%d x %d = %d\n", a, b, mulValue);
	printf("%d / %d = %f\n", a, b, divValue);


	return 0;
}