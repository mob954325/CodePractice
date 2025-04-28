#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 10 -> 5
// 30 -> 10
// 50 -> 20

int solution(int price) {
    if (price >= 500000)
    {
        price = price - price * 0.2f;
    }
    else if (price >= 300000)
    {
        price = price - price * 0.1f;
    }
    else if (price >= 100000)
    {
        price = price - price * 0.05f;
    }

    return price;
}