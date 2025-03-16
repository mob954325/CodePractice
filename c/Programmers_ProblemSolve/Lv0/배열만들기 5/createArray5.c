#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// 1. 각 원소의 s번인덱스에서 시작하는 길이 l짜리 부분 문자열을 정수로 전환
// 2. k값보다 크면 배열에 저장하기

// intStrs_len은 배열 intStrs의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* intStrs[], size_t intStrs_len, int k, int s, int l) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* temp = (int*)malloc(intStrs_len * sizeof(int));
    int tempCnt = 0;

    for (int i = 0; i < intStrs_len; i++)
    {
        int currNum = 0, pos = 0;
        char* intStrNum = (char*)malloc(200 * sizeof(char));
        for (int j = s; j < s + l; j++)
        {
            intStrNum[pos++] = intStrs[i][j];
        }

        intStrNum[pos] = '\0';
        currNum = atoi(intStrNum);

        if (currNum > k) temp[tempCnt++] = currNum;
    }

    int* answer = (int*)malloc(tempCnt * sizeof(int));
    for (int i = 0; i < tempCnt; i++)
    {
        answer[i] = temp[i];
    }

    free(temp);
    return answer;
}