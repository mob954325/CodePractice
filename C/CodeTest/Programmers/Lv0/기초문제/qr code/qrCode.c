#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문제
// 문자열을 q로 나누었을 때 나머지가 r인 위치 나열

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(int q, int r, const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int codeLen = strlen(code);
    char* answer = (char*)malloc((codeLen / q + 1) * sizeof(char));

    int answerCnt = 0;
    for (int i = 0; i < codeLen; i++)
    {
        int rest = i % q;
        if (rest == r) answer[answerCnt++] = code[i];
    }
    answer[answerCnt] = '\0';

    return answer;
}