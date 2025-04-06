#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(int n) {
    int* temp = (int*)calloc(10001, sizeof(int));
    int tempCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) temp[tempCnt++] = i;
    }

    int* answer = (int*)malloc(tempCnt * sizeof(int));
    memcpy(answer, temp, tempCnt * sizeof(int));

    return answer;
}

int main()
{
    int n = 24;
    solution(n);
}