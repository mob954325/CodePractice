#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. 리스트 만들기

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int countArray[1001];
    for (int i = 0; i < 1001; i++)
    {
        countArray[i] = 0;
    }

    for (int i = 0; i < array_len; i++)
    {
        countArray[array[i]]++;
    }

    // 빈도수 높은 거 찾기
    int highestFrequencyNum = 0; // 가장 높은 빈도수를 가진 수
    int highestFrequencyValue = 0; // 가장 높은 빈도수
    int highestFrequencyCount = 0; // 가장 높은 빈도수를 가진 요소의 개수
    for (int i = 0; i < 1001; i++)
    {
        if (countArray[i] > highestFrequencyValue)
        {
            highestFrequencyNum = i;
            highestFrequencyValue = countArray[i];
            highestFrequencyCount = 1;
        }
        else if (countArray[i] == highestFrequencyValue)
        {
            highestFrequencyCount++;
        }
    }

    return highestFrequencyCount == 1 ? highestFrequencyNum : -1;
}