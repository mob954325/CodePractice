#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_prefix) {
    int myLen = 0, prefixLen = 0;
    myLen = strlen(my_string);
    prefixLen = strlen(is_prefix);

    char* buffer = (char*)malloc((prefixLen + 1) * sizeof(char));
    int bufferCnt;
    for (bufferCnt = 0; bufferCnt < prefixLen; bufferCnt++)
    {
        buffer[bufferCnt] = my_string[bufferCnt];
    }

    buffer[bufferCnt] = '\0';

    return strcmp(buffer, is_prefix) == 0 ? 1 : 0;
}