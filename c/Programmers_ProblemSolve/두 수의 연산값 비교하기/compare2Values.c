#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0, ab = 0, ab2 = 2 * a * b;
    
    int cnt = 0;
    while(b != 0)
    {
        ab += b % 10 * pow(10, cnt++);
        b /= 10;
    }
    
    while(a != 0)
    {
        ab += a % 10 * pow(10, cnt++);
        a /= 10;
    }
    
    return answer = ab > ab2 ? ab : ab2;
}