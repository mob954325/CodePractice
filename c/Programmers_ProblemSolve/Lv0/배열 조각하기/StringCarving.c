#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제
// query[i] 가 짝수면 뒤짜르기
// 홀수면 앞짜르기 -> 남은 배열 리턴

// arr_len은 배열 arr의 길이입니다.
// query_len은 배열 query의 길이입니다.
int* solution(int arr[], size_t arr_len, int query[], size_t query_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int* nums = (int*)malloc(sizeof(int) * arr_len);

    // nums 배열에 값넣기
    for (int i = 0; i < arr_len; i++)
    {
        *(nums + i) = arr[i];
    }

    int answerSize = arr_len; // 사이즈 
    int left = 0, right = answerSize - 1;

    // 왼쪽 오른쪽 요소를 하나씩 제거하기 
    for (int i = 0; i < query_len; i++)
    {
        if (query[i] % 2 == 0)
        {
            nums[right--] = -1;
            answerSize--;
        }
        else if (query[i] % 2 == 1)
        {
            nums[left++] = -1; // buffer overrun
            answerSize--;
        }
    }

    // answer 배열에 위에서 나온 값 추출해서 반환
    int* answer = (int*)malloc(sizeof(int) * answerSize);
    int cnt = 0; // answer에 넣을 요소 위치 값
    for (int i = 0; i < arr_len; i++)
    {
        // segmentation fault 
        if (nums[i] != -1)
        {
            *(answer + cnt++) = nums[i];
        }
    }

    return answer;
}

int main()
{
    int arr[6] = { 0, 1, 2, 3, 4 };
    int q[3] = { 1,2,3 };
    solution(arr, 6, q, 3);
}