#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// a는 0 - \0이 아닌 곳까지
// op는 a확인이 끝난 다음 칸
// b는 op 다음 칸부터 끝까지

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* binomial) {
    int n = strlen(binomial);
    int a = 0, b = 0, currPos = 0, numPos = 1;
    char op;

    while (binomial[numPos] != ' ')
    {
        numPos++;
    }

    // a
    int pos = 1;
    for (int i = numPos - 1; i > -1; --i)
    {
        a += (int)(binomial[i] - '0') * pos;
        pos *= 10;
    }

    // op
    numPos++;
    op = binomial[numPos];

    numPos++;
    // b
    pos = 1;
    for (int i = n - 1; i > numPos; --i)
    {
        b += (int)(binomial[i] - '0') * pos;
        pos *= 10;
    }

    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }

    return 0;
}

int main()
{
    const char* s = "43 + 12";
    solution(s);
}