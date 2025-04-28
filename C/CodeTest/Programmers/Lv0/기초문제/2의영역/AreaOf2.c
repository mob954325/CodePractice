#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 문제 
// 배열 안에 모든 2가 포함된 부분 배열을 반환해라

// 해결
// 먼저 찾은 2를 start로 지정
// start를 시작으로 모든 배열을 돌아서 2가 있을 때마다 end값 갱신
// 모든 배열을 다 돌고난뒤 start와 end 인덱스를 포함한 구간을 반환

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int start = -1, end = -1;
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == 2)
        {
            if (start == -1)
            {
                start = i;
                end = i;
            }
            else
            {
                end = i;
            }
        }
    }

    if (start == -1) // 2가 없음
    {
        int* answer = (int*)malloc(1 * sizeof(int));
        answer[0] = -1;
        return answer;
    }


    int cnt = 0; // cnt로 재활용
    int* answer = (int*)malloc((end - start + 1) * sizeof(int));
    for (int i = start; i <= end; i++)
    {
        answer[cnt++] = arr[i];
    }

    return answer;
}

int main()
{
    int a[7] = {1,2,1,4,5,2,9};
    solution(a, 7);
}