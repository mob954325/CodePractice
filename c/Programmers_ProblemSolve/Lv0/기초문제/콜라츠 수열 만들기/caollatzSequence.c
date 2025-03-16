#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// 콜라츠 수열만들기
// 1. n이 작수면 n / 2
// 2. n이 홀수면 3 * x + 1
// 1 2 반복

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* temp = (int*)malloc(1000000 * sizeof(int));
    int temp_cnt = 0;

    temp[temp_cnt++] = n;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        temp[temp_cnt++] = n;
    }

    int* answer = (int*)malloc(temp_cnt * sizeof(temp_cnt));

    for (int i = 0; i < temp_cnt; i++)
    {
        answer[i] = temp[i];
    }

    return answer;
}