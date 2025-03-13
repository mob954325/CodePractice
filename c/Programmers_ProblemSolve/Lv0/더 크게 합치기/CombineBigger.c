#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a + b, b + a 각 각 구하고 max 구하기

int solution(int a, int b) {
    int answer = 0;
    int pos = 1, ab = 0, ba = 0;

    int a1 = a, b1 = b;
    // a b
    while (b1 != 0)
    {
        ba += (b1 % 10) * pos;
        pos *= 10;
        b1 /= 10;
    }
    while (a1 != 0)
    {
        ba += (a1 % 10) * pos;
        pos *= 10;
        a1 /= 10;
    }

    // b a
    pos = 1;
    a1 = a, b1 = b;
    while (a1 != 0)
    {
        ab += (a1 % 10) * pos;
        pos *= 10;
        a1 /= 10;
    }

    while (b1 != 0)
    {
        ab += (b1 % 10) * pos;
        pos *= 10;
        b1 /= 10;
    }

    if (ab > ba) answer = ab;
    else answer = ba;
    return answer;
}

int main()
{
    int a = 9;
    int b = 91;

    solution(9, 91);
}