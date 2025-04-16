#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int solution(const char* A, const char* B) {
    int len = strlen(A);
    int answer = 0;
    int start = 0;
    int min = 101;

    while (start < len)
    {
        int correct = 0;
        for (int i = 0; i < len; i++)
        {
            int checkIndex = (start + i) % len;
            if (A[checkIndex] == B[i]) correct++;
        }

        if (correct == len)
        {
            if (len - start < min) min = len - start;
        }
        start++;
    }
	
	if(min == n) min = 0;
    return min == 101 ? -1 : min;
}

int main()
{
    const char* a = "hello";
    const char* b = "elloh";
    solution(a, b);
}