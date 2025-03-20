#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 해결
// 모든 걸 k개 만큼 추가해보자

// picture_len은 배열 picture의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* picture[], size_t picture_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((picture_len * k) * sizeof(char*));
    for (int i = 0; i < picture_len * k; i++) // 문자열 위치 
    {
        int currStrLen = strlen(picture[i / k]);
        answer[i] = (char*)malloc((currStrLen * k + 1) * sizeof(char));
        for (int j = 0; j < currStrLen; j++) // 해당 문자열
        {
            for (int loop = 0; loop < k; loop++) // 해당 문자열 키우기
            {
                answer[i][j * k + loop] = picture[i / k][j];
            }
        }
        answer[i][currStrLen * k] = '\0';
    }

    return answer;
}

int main()
{
    const char* p[3] =
    {
        "x.x", ".x.", "x.x"
    };

    solution(p, 3, 3);
}