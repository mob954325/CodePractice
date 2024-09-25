#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	clock_t start, stop;
	double duration = 0.0f;

	// clock() : 시스템 시간을 CLOCKS_PER_SEC으로 반환하는 함수

	start = clock(); // 시간 기록

	for (int i = 0; i < 1000000; i++); // 의미없는 루프 1백만

	stop = clock(); // 끝 시간 기록

	duration = (double)(stop - start) / CLOCKS_PER_SEC;

	printf("duration time is %f sec.", duration);
	return 0;
}