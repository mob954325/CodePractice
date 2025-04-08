#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int myLen = strlen(my_str);
    char* checkStr = (char*)malloc((myLen + 1) * sizeof(char));
    memcpy(checkStr, my_str, myLen + 1);

    char** answer = (char**)malloc((myLen / n + 1) * sizeof(char*));
    int answerCount = 0;

    int start = 0;
    while (start < myLen)
    {
        answer[answerCount] = (char*)malloc((n + 1) * sizeof(char));
        if (start + n < myLen) memcpy(answer[answerCount], checkStr, n);
        else memcpy(answer[answerCount], checkStr, myLen - start + 1);

        answer[answerCount++][n] = '\0';

        start += n;
        checkStr = (checkStr + n);
    }


    return answer;
}

int main()
{
    const char* a = "asdfzxcvghjk";

    solution(a, 4);
}