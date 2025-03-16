#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// my_string에서 각 요소에서 시작하는 부분 문자열들을 반환해라

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int strLen = strlen(my_string);
    char** answer = (char**)malloc(strLen * sizeof(char*));

    for (int i = 0; i < strLen; i++)
    {
        char* temp = (char*)malloc(101 * sizeof(char));
        int tempLen = 0;
        for (int j = i; j < strLen; j++)
        {
            temp[tempLen++] = my_string[j];
        }
        temp[tempLen] = '\0';
        answer[i] = (char*)malloc((tempLen + 1) * sizeof(char));
        answer[i] = strcpy(answer[i], temp);
        free(temp);
    }
    // 여기까지는 모든 접미사 찾음
    // 사전 순 정렬하기
    qsort(answer, strLen, sizeof(char*), compareStrings);

    return answer;
}