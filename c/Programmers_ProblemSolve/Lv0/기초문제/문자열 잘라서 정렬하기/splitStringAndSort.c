#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100001

int compare(void* arg1, void* arg2)
{
    char* str1 = (char*)arg1;
    char* str2 = (char*)arg2;

    int strLen1 = strlen(str1);
    int strLen2 = strlen(str2);
    int n = strLen1 < strLen2 ? strLen1 : strLen2;

    for (int i = 0; i < n; i++)
    {
        if (str1[i] == str2[i]) continue;
        
        return str1[i] < str2[i];
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int n = strlen(myString);

    char** result = (char**)malloc(MAXSIZE * sizeof(char*));
    char* temp = (char*)malloc(MAXSIZE * sizeof(char)); // 문자열 저장용
    int tempCnt = 0, resultCnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (myString[i] == 'x')
        {
            result[resultCnt] = (char*)malloc((tempCnt + 1) * sizeof(char));

            // 문자열 처리
            strcpy(result[resultCnt], temp);

            // 조건 처리
            tempCnt = 0;
            resultCnt++;
        }
        else // x가 아니면
        {
            temp[tempCnt++] = myString[i];
            temp[tempCnt] = '\0';
        }
    }

    // 마지막 문자열 처리
    result[resultCnt] = (char*)malloc((tempCnt + 1) * sizeof(char));
    strcpy(result[resultCnt++], temp);
    free(temp);

    qsort(result, resultCnt, MAXSIZE, compare);
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
    solution("dxccxbbbxaaaa");
}