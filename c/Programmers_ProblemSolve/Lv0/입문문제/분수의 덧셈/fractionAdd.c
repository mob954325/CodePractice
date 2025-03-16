#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. 공통 분모 만들어서 덧셈
// 2. 공약수 찾기 - 유클리드 호제법
//  자연수 a, b가 있을 때 r을 a % b의 결과값이라고 하면(나머지) 
//  b, r의 최대공약수는 a, b의 최대공약수와 같다는 성질을 이용한 알고리즘
//  위 계산을 반복하여 나머지가 0이 될 때 나눈 값을 최대 공약수(Greate Common Divisor)라고 한다.
// 3. 2.번에서 구한 값으로 분모 분자를 나눠서 기약분수로 만들기
int EuclideanAlgorithm(int a, int b)
{
    int r = a % b;
    int res = 0;
    if (r != 0) res = EuclideanAlgorithm(b, r);
    else res = b;

    return res;
}

int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));

    int num = 0, denom = 0;
    // 1.
    num = (numer1 * denom2) + (numer2 * denom1);
    denom = (denom1 * denom2);

    // 2. 
    int GCD = EuclideanAlgorithm(num, denom);
    num /= GCD;
    denom /= GCD;

    answer[0] = num;
    answer[1] = denom;

    return answer;
}

int main()
{
    solution(1, 2, 3, 4);
}