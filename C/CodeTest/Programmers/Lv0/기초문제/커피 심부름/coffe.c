#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문제
// 아메리카노 4500
// 라테 5000
// 계산 합 반환

int checkCoffee(const char* order)
{
    int n = strlen(order);
    char americano[10] = "americano";
    char cafelatte[10] = "cafelatte";

    int americano_len = strlen(americano);
    int cafelatte_len = strlen(cafelatte);

    // 아메리카노
    for (int i = 0; i <= n - americano_len; i++)
    {
        int correct = 0;
        for (int j = 0; j < americano_len; j++)
        {
            if (americano[j] == order[i + j]) correct++;
        }

        if (correct == americano_len) return 4500;
    }

    // 라테
    for (int i = 0; i <= n - cafelatte_len; i++)
    {
        int correct = 0;
        for (int j = 0; j < cafelatte_len; j++)
        {
            if (cafelatte[j] == order[i + j]) correct++;
        }

        if (correct == cafelatte_len) return 5000;
    }

    return 4500; // 아무거나
}

// order_len은 배열 order의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* order[], size_t order_len) {
    int answer = 0;

    for (int i = 0; i < order_len; i++)
    {
        int price = checkCoffee(order[i]);
        answer += price;
    }

    return answer;
}

int main()
{
    const char* order[4];
    order[0] = "cafelatte";
    order[1] = "americanoice";
    order[2] = "hotcafelatte";
    order[3] = "anything";

    solution(order, 4);
}