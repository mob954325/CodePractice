#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int l[], size_t n) {
    int odd = 0, even = 0;
    int oddPos = 1, evenPos = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (l[i] % 2 == 0)// 짝
        {
            even += l[i] * evenPos;
            evenPos *= 10;
        }
        else // 홀
        {
            odd += l[i] * oddPos;
            oddPos *= 10;
        }
    }

    return odd + even;
}

int main()
{
    int l[5] = { 3,4,5,2,1 };
    solution(l, 5);
}