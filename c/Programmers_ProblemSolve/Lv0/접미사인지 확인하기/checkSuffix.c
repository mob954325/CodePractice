#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문제
// my_string에서 파생되는 접미사들 중 is_suffix가 있는지 확인

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_suffix) {
    // 접미사 저장
    int strLen = strlen(my_string);
    int suffixLen = strlen(is_suffix);

    if (suffixLen > strLen) return 0;
    if (strcmp(my_string + strLen - suffixLen, is_suffix) == 0) return 1;

    return 0;
}