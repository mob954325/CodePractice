#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. 배열 정렬하기
// 2. 중앙 인덱스의 값을 반환하기

int compare(const void* a, const void* b)
{
    return *(int*)a < *(int*)b;
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;

    qsort(array, array_len, sizeof(int), compare);

    return array[array_len / 2];
}