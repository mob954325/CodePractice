#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 홀수면 모든 홀수의 합
// 짝수면 모든 짝수 제곱의 합

int solution(int n) {
    int answer = 0, curr = 0;

    if(n % 2 == 0)
    {
        while(curr <= n)
        {
            answer += (curr * curr);
            curr += 2;
        }
    }
    else
    {
        curr = 1;
        while(curr <= n)
        {
            answer += (curr);
            curr += 2;
        }
    }
    
    return answer;
}