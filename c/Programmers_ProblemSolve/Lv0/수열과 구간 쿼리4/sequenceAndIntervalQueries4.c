#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// 1. s <= i <= e에 대해
// 2. i % k == 0 이면 arr[i] + 1값을 추가해라

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(arr_len * sizeof(int));

    for (int i = 0; i < arr_len; i++)
    {
        answer[i] = arr[i];
    }

    for (int i = 0; i < arr_len; i++)
    {
        int i_min = queries[i][0];
        int i_max = queries[i][1];
        int i_compare = queries[i][2];

        int temp = arr[i];
        for (int j = 0; j < arr_len; j++)
        {
            if (j < i_min || j > i_max) continue; // s <= i <= e 확인

            if (j % i_compare == 0) // 2.
            {
                // segmentation fault
                temp++;
            }
        }

        arr[i] = temp;
    }

    return answer;
}