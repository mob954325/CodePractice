#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

// n m 의 조건을 저장하고 ineq와 eq를 비교하여 같으면 true 아니면 false 반환
int solution(const char* ineq, const char* eq, int n, int m) {

    char* c1 = ineq;
    char* c2 = eq;
    if (*c2 == '!')
    {
        if (*c1 == '<')
        {
            return (n < m) == 1 ? 1 : 0;
        }
        else if (*c1 == '>')
        {
            return (n > m) == 1 ? 1 : 0;
        }
    }
    else if (*c2 == '=')// =
    {
        if (*c1 == '<')
        {
            return (n <= m) == 1 ? 1 : 0;
        }
        else if (*c1 == '>')
        {
            return (n >= m) == 1 ? 1 : 0;
        }
    }

    return 0;
}

int main()
{
    const char* a = "<";
    const char* b = "=";
    int n = 20;
    int n2 = 50;
    printf("%d", solution(a, b, n, n2));
}