#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* s1 = str1;
    char* s2 = str2;
    char* answer = (char*)malloc(10);

    int cnt = 0, answerCnt = 0;
    while (*(s1 + cnt) >= 'a' && *(s1 + cnt) <= 'z')
    {
        *(answer + answerCnt++) = *(s1 + cnt);
        *(answer + answerCnt++) = *(s2 + cnt++);
    }

    *(answer + answerCnt) = '\0';
    return answer;
}

int main()
{
    const char* str1 = "aaaaa";
    const char* str2 = "bbbbb";

    solution(str1, str2);
}