#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 17 : 실패 (signal: segmentation fault (core dumped))
// 문제
// 문자열 m을 rn으로 변경하고 반환하는 solution 완성하기

// 해결
// 그냥 문자열 탐색해서 m이면 rn으로 변경해서 저장하기
// m개수 체크해서 2곱한 사이즈를 더해서 동적할당하기

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rny_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요. 
    char temp[202] = "";
    int prev_n = sizeof(rny_string);
    int after_n = 0;

    int cnt = 0;
    while (*(rny_string + cnt) != '\0')
    {
        if (*(rny_string + cnt) == 'm')
        {
            temp[after_n++] = 'r';
            temp[after_n++] = 'n';
        }
        else
        {
            temp[after_n++] = *(rny_string + cnt);
        }

        cnt++;
    }

    int a = sizeof(temp);

    char* answer = (char*)malloc(after_n);

    for (int cnt = 0; cnt < after_n; cnt++)
    {
        *(answer + cnt) = temp[cnt];
    }
    *(answer + after_n) = '\0';
    return answer;
}