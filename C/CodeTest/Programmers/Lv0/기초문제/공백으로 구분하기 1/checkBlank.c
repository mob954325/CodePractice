#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 1024

int GetLength(const char* str)
{
    const char* p = str;
    int cnt = 0;
    while (*p != '\0')
    {
        p++;
        cnt++;
    }

    return cnt + 1;
}

void CopyString(char target[], char source[])
{
    char* target_p = target;
    char* source_p = source;
    while (*source_p != '\0')
    {
        *target_p = *source_p;
        target_p++;
        source_p++;
    }
    *target_p = '\0';
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int my_string_len = GetLength(my_string);
    char** temp = (char**)malloc(MAXSIZE * sizeof(char*));

    char* p = my_string; // my_string 포인터
    int wordCount = 0, start = 0, end = 0;
    while (my_string[end] != '\0')
    {
        if (my_string[end] == ' ')
        {
            temp[wordCount] = (char*)malloc((end - start + 2) * sizeof(char));
            int tempCnt = 0;
            for (int i = start; i < end; i++)
            {
                temp[wordCount][tempCnt++] = my_string[i];
            }
            temp[wordCount][tempCnt] = '\0';

            start = end + 1;
            wordCount++;
        }
        end++;
    }

    // 마지막 처리 문자열 처리
    temp[wordCount] = (char*)malloc((end - start + 2) * sizeof(char));
    int tempCnt = 0;
    for (int i = start; i < end; i++)
    {
        temp[wordCount][tempCnt++] = my_string[i];
    }
    temp[wordCount++][tempCnt] = '\0';

    // temp 값을 answer로 옮기기
    char** answer = (char**)malloc((wordCount) * sizeof(char*));
    for (int i = 0; i < wordCount; i++)
    {
        answer[i] = (char*)malloc(GetLength(temp[i]) * sizeof(char));
        CopyString(answer[i], temp[i]);
    }

    free(temp);
    return answer;
}

int main()
{
    const char* str = (char*)malloc(sizeof(char) * 11);
    char c[] = "i love you";
    CopyString(str, c);

    solution(str);
}