#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size = 52;
    int* answer = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        answer[i] = 0;
    }

    for (int i = 0; i < strlen(my_string); i++)
    {
        if (my_string[i] >= 'A' && my_string[i] <= 'Z') answer[(int)(my_string[i] - 'A')]++;
        else answer[(int)(my_string[i] - 'A') - 6]++;
    }

    return answer;
}