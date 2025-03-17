#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// 피자를 6조각으로 잘라 줄 때
// n명이 모두 같은 조각을 먹어야 한다면 최소 피자 판수가 몇 개인지 구하기

// 반복기 돌려서
// n * i가 6의 배수면 반환
int solution(int n) {
    int answer = n;
    while (answer < 10000)
    {
        if (answer % 6 == 0) break;
        answer += n;
    }

    return answer / 6;
}