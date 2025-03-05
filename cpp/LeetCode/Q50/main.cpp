#include <iostream>

int main()
{
	long l = LONG_MIN;
	std::cout << l << "\n";
	std::cout << labs(l) << "\n";
	std::cout << l * -1 << "\n";
}

double myPow(double x, int n) {
    // 방법 1.
    // x를 n번 곱하기
    // -> 1을 2147483647(long의 최대값)을 곱하는건 비효율적이다.
    // 방법 2.
    // 이진 지수화 
    // 지수값을 이진으로 변환하여 비트가 켜져있으면 곱하고 꺼져있으면 통과
    // -> 홀수일때만 곱하기

    if (n < 0)
    {
        x = 1 / x;
    }

    long num = labs(n); // 지수
    double pow = 1;     // 결과값

    while (num)
    {
        if (num & 1) // num의 첫 비트가 1이다. if((num & 1) != 0)과 동일
        {
            pow *= x;
        }

        x *= x; // n^해당 위치 비트값 ( 1, 2, 4, 8 ...)
        num >>= 1;
    }

    return pow;
}


// 방법 2.
// ex> x = 7, n = 11, pow = 1
// (11)10 == (1011)2
// 1 0 1 1
// 8 4 2 1
// -> 7^8 * 7^2 * 7^1 == 7^(8 + 2 + 1) == 7^11
//