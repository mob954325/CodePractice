#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문제
// a, b, c로 나눠진 문자열을 순서대로 출력하세요

#define MAXSIZE 1000001

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myStr) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int n = strlen(myStr);

    char** result = (char**)malloc(MAXSIZE * sizeof(char*));
    char* temp = (char*)malloc(MAXSIZE * sizeof(char));
    int tempCnt = 0, resultCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (tempCnt != 0 && myStr[i] <= 'c')
        {
            temp[tempCnt++] = '\0';
            result[resultCnt] = (char*)malloc(tempCnt * sizeof(char));
            strcpy(result[resultCnt], temp);
            tempCnt = 0;
            resultCnt++;
        }
        else if (myStr[i] > 'c')
        {
            temp[tempCnt++] = myStr[i];
        }
    }

    if (tempCnt != 0)
    {
        temp[tempCnt++] = '\0';
        result[resultCnt] = (char*)malloc(tempCnt * sizeof(char));
        strcpy(result[resultCnt], temp);
        resultCnt++;
    }
    free(temp);

    if (resultCnt == 0)
    {
        char** empty = (char**)malloc(1 * sizeof(char*));
        empty[0] = (char*)malloc(1 * sizeof(char));
        empty[0] = "EMPTY";
        free(result);

        return empty;
    }

    char** answer = (char**)malloc(resultCnt * sizeof(char*));
    for (int i = 0; i < resultCnt; i++)
    {
        int reslutStrLen = strlen(result[i]);
        answer[i] = (char*)malloc((reslutStrLen + 1) * sizeof(char));
        strcpy(answer[i], result[i]);
        free(result[i]);
    }

    free(result);
    return answer;
}

int main()
{
    solution("cabab");
}