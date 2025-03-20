#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** wordContainer = (char**)malloc(MAXSIZE * sizeof(char*));

    int wordCount = 0;
    char* word = strtok(my_string, " ");

    while (word != NULL)
    {
        wordContainer[wordCount] = (char*)malloc(strlen(word) * sizeof(char));
        wordContainer[wordCount++] = word;
        word = strtok(NULL, " ");
    }

    char** answer = (char**)malloc(wordCount * sizeof(char*));
    for (int i = 0; i < wordCount; i++)
    {
        answer[i] = (char*)malloc(strlen(wordContainer[i]) * sizeof(char));
        strcpy(answer[i], wordContainer[i]);
    }

    free(wordContainer);
    free(word);
    return answer;
}

int main()
{
    char a[] = "     programmer";
    solution(a);
}