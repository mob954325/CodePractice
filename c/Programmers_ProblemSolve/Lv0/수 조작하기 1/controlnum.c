#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(int n, const char* control) {
    int answer = n;

    int cnt = 0;
    while (control[cnt] != '\0')
    {
        char orderChar = control[cnt];
        if (orderChar == 'w')
        {
            answer++;
        }
        else if (orderChar == 's')
        {
            answer--;
        }
        else if (orderChar == 'd')
        {
            answer += 10;
        }
        else if (orderChar == 'a')
        {
            answer -= 10;
        }
        cnt++;
    }

    return answer;
}