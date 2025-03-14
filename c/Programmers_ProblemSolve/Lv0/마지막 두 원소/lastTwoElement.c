#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// 배열 요소 추가하기
// 1. 마지막 원소가 그 전 원소보다 크면 마지막 원소 - 그전 원소 뺀값을
// 2. 마지막 원소가 그 전 원소보다 크지 않으면 마지막 원소를 두 배한 값을 추가하여 반환해라

// 12case 실패 -> <=부호 확인 테스트
// 크기 않다면 -> 크지않거나 같으면 ...?

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.   

    int answer_len = num_list_len + 1;
    int* answer = (int*)malloc(answer_len * sizeof(int));

    // 이전 요소 추가
    for (int i = 0; i < num_list_len; i++)
    {
        answer[i] = num_list[i];
    }

    // 마지막 요소 추가 
    if (num_list[num_list_len - 1] > num_list[num_list_len - 2]) // 1.
    {
        answer[answer_len - 1] = answer[answer_len - 2] - answer[answer_len - 3];
    }
    else if (num_list[num_list_len - 1] <= num_list[num_list_len - 2]) // 2.
    {
        answer[answer_len - 1] = answer[answer_len - 2] * 2;
    }

    return answer;
}