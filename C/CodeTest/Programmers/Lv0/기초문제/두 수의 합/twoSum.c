#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* a, const char* b) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.        
    int alen = strlen(a);
    int blen = strlen(b);

    char* temp = (char*)malloc((100002) * sizeof(char));

    int tempCnt = 100001;
    int ap = alen - 1, bp = blen - 1;

    int up = 0;
    while (ap >= 0 && bp >= 0)
    {
        temp[tempCnt] = up;
        int curr = (int)(a[ap] - '0') + (int)(b[bp] - '0');
        up = curr / 10; // 올림확인
        curr %= 10;

        temp[tempCnt] += (char)(curr + '0');
        if (temp[tempCnt] == 58)
        {
            up++;
            temp[tempCnt] = '0';
        }

        tempCnt--;
        ap--;
        bp--;
    }

    // 남은거 처리
    while (ap >= 0)
    {
        temp[tempCnt] = a[ap--] + up;
        up = 0;
        if (temp[tempCnt] == 58)
        {
            temp[tempCnt] = '0';
            up = 1;
        }
        tempCnt--;
    }

    while (bp >= 0)
    {
        temp[tempCnt] = b[bp--] + up;
        up = 0;
        if (temp[tempCnt] == 58)
        {
            temp[tempCnt] = '0';
            up = 1;
        }
        tempCnt--;
    }

    if (up != 0)
    {
        temp[tempCnt] = (char)(up + '0');
        tempCnt--;
    }

    char* answer = (char*)malloc((100002 - tempCnt) * sizeof(char));
    for (int i = 0; i < 100002 - tempCnt; i++)
    {
        answer[100001 - 1 - tempCnt - i] = temp[100001 - i];
    }

    answer[100001 - tempCnt] = '\0';

    return answer;
}

int main()
{
    solution("18446744073709551615", "287346502836570928366");
}