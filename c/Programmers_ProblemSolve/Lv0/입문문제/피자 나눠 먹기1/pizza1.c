#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// 피자를 7조각씩 잘라줄 때 
// 사람 n이 모두 한조각씩 먹기 위해 필요한 최소 피자 수

int solution(int n) {
    return n % 7 == 0 ? n / 7 : n / 7 + 1;
}