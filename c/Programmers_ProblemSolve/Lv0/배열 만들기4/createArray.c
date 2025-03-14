#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100000

// 1. 만약 stk가 빈 배열이라면 arr[i]를 stk에 추가하고 i에 1을 더합니다.
// 2. stk에 원소가 있고, stk의 마지막 원소가 arr[i]보다 작으면 arr[i]를 stk의 뒤에 추가하고 i에 1을 더합니다.
// 3. stk에 원소가 있는데 stk의 마지막 원소가 arr[i]보다 크거나 같으면 stk의 마지막 원소를 stk에서 제거합니다.

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* stk = (int*)malloc(MAX_BUFFER_SIZE * sizeof(int));

    for (int i = 0; i < MAX_BUFFER_SIZE; i++)
    {
        stk[i] = -1;
    }

    int stk_len = 0;
    int i = 0;
    while (i < arr_len)
    {
        if (stk_len == 0) // 1
        {
            stk[stk_len++] = arr[i];
            i++;
            continue;
        }
        else // 2 3
        {
            if (stk[stk_len - 1] < arr[i])
            {
                stk_len++;
                stk[stk_len - 1] = arr[i];
                i++;
            }
            else // >=  
            {
                stk[stk_len - 1] = -1;
                stk_len--;
            }
        }
    }

    return stk;
}