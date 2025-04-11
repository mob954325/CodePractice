#include <stdio.h>
//#include <float.h>
#include <cfloat>
#include <cmath>


int main() 
{
	// 그냥 비교
	float a = 0.0f;
	for (int i = 0; i < 10; i++)
	{
		a += 0.1f;
	}
	float b = 1.0f;
	printf("%f == %f %s\n", a, b, (a == b) ? "true" : "false");
	printf("a : %.10f\n", a); // 완벽한 1이 아님 1.xxxx
	printf("b : %.10f\n\n", b); // 1.000...

	// epsilon 비교
	a = 0.1f;
	a -= 0.1f;
	for (int i = 0; i < 10; i++)
	{
		a += 0.1f;
	}
	b = 1.0f;

	printf("epsilon : %.20f\n", FLT_EPSILON);
	float c = a - b;
	printf("%f == %f %s\n", a, b, (fabs(a - b) < FLT_EPSILON + 0.1e-07F) ? "true" : "false"); // fabs - 부동소숫점의 절대값 연산

	return 0;
}
