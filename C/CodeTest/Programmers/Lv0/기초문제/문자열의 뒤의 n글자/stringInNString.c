#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// my_string에 끝부터 n개의 글자로 이뤄진 문자열을 반환해라

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.       
    char* answer = (char*)malloc(1001 * sizeof(char));
    int strLen = strlen(my_string);

    int answerLen = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (i >= strLen - n) answer[answerLen++] = my_string[i];
    }

    answer[answerLen] = '\0';
    return answer;
}