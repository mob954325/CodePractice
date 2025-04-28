#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// s <= i <= e에 대해 i(요소 위치)가 k보다 클때 가장 작은 값을 쿼리별로 저장해서 반환하기

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.

#define MIN 100000000

int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(queries_rows * sizeof(int));

    int answer_cnt = 0;
    for (int i = 0; i < queries_rows; i++)
    {
        int i_min = queries[i][0];
        int i_max = queries[i][1];
        int i_compare = queries[i][2];

        int result_min = MIN;
        for (int j = 0; j < arr_len; j++)
        {
            if (j < i_min || j > i_max) continue; // s <= i <= e 확인

            if (arr[j] > i_compare && arr[j] < result_min) // i > k
            {
                result_min = arr[j];
            }
        }

        answer[answer_cnt++] = result_min == MIN ? -1 : result_min;
    }

    return answer;
}