#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//함수 포인터
float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float div(float a, float b) { return a / b; }
float calculator(float(*pfunc)(float, float), float a, float b) { return pfunc(a, b); }
int main() {


	printf("&add = %p\n", add);
	float(*pfunc)(float, float) = add; // float(*)(float, float)
	pfunc(10.1f, 20.2f);


	float a = 10.23f;   float b = 3.45f;
	float ret = calculator(add, a, b);  
	printf("%f + %f = %f\n", a, b, ret);
	ret = calculator(sub, a, b); 
	printf("%f - %f = %f\n", a, b, ret);
	float(*pfuncArray[4])(float, float);  
	// 함수 포인터 배열  
	char operArray[4] = { '+', '-', 'x', '/' };
	pfuncArray[0] = add; 
	pfuncArray[1] = sub;  
	pfuncArray[2] = mul; 
	pfuncArray[3] = div;
	printf("\n\n함수 포인터 배열을 이용한 일괄 연산\n");
	for (int i = 0; i < 4; i++)
	{ 
		printf("%f %c %f = %f\n", a, operArray[i], b, pfuncArray[i](a, b));
	}
	return 0;
}