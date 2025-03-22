#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100001

int compare(const void* a, const void* b) 
{
    char* x = *(char**)a;
    char* y = *(char**)b;
    return strcmp(x, y);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int n = strlen(myString);

    char** result = (char**)malloc(MAXSIZE * sizeof(char*));
    char* temp = (char*)malloc(MAXSIZE * sizeof(char)); // 문자열 저장용
    int tempCnt = 0, resultCnt = 0;
    temp[0] = '\0';

    for (int i = 0; i < n; i++)
    {
        if (tempCnt != 0 && myString[i] == 'x')
        {
            temp[tempCnt++] = '\0';
            result[resultCnt] = (char*)malloc((tempCnt + 1) * sizeof(char));

            // 문자열 처리
            strcpy(result[resultCnt], temp);

            for (int j = 0; j < tempCnt; j++)
            {
                temp[j] = '\0';
            }

            // 조건 처리
            tempCnt = 0;
            resultCnt++;
        }
        else if (myString[i] != 'x')
        {
            temp[tempCnt++] = myString[i];
        }
    }

    // 마지막 문자열 처리
    if (tempCnt != 0)
    {
        temp[tempCnt++] = '\0';
        result[resultCnt] = (char*)malloc((tempCnt) * sizeof(char));
        strcpy(result[resultCnt++], temp);
    }
    free(temp);

    // 정렬
    if (resultCnt != 0) qsort(result, resultCnt, sizeof(char*), compare);

    // 복사
    char** answer = (char**)malloc(resultCnt * sizeof(char*));
    for (int i = 0; i < resultCnt; i++)
    {
        answer[i] = (char*)malloc((strlen(result[i]) + 1) * sizeof(char));
        strcpy(answer[i], result[i]);
        free(result[i]);
    }

    free(result);
    return answer;
}

int main()
{
    solution("bxxaxx");
}