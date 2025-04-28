#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFERSIZE 1024

// 문제
// 왼쪽 모스부호 표를 통해 letter 해석하고 반환하기

// 해결
// 2차원배열로 모스부호와 해당 문자값을 저장하고 letter랑 비교하기
// -> 'a'를 더해서 문자 찾기
// left부터 시작해서 모스부호를 찾으면 끝위치에 left를 이동시키고 반복하기


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char morse[][5] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    char* converted = (char*)malloc(MAXBUFFERSIZE * sizeof(char));

    int convertedCnt = 0;
    int n = strlen(letter);
    int left = 0, right = 0;

    while (left < n)
    {
        for (int i = 0; i < 26; i++)
        {
            int morseLen = 0;
            int correct = 0;
            for (int j = 0; j < 5; j++)
            {
                if (morse[i][j] == '\0') break;
                if (letter[left + j] == morse[i][j]) correct++;
                morseLen++;
            }

            // 공백 구분이거나 마지막 위치인지 확인 후 추가
            if (correct == morseLen && (letter[left + morseLen] == ' ' || (left + morseLen == n))) 
            {
                converted[convertedCnt++] = (char)(i + 'a');
                left += morseLen + 1;
                break;
            }
        }
    }

    converted[convertedCnt] = '\0';
    char* answer = (char*)malloc(convertedCnt * sizeof(char));
    strcpy(answer, converted);
    free(converted);

    return answer;
}

int main()
{
    const char str[40] = ".... . .-.. .-.. ---";

    solution(str);
}