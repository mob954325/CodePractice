#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* polynomial) {
    // 문자열 복사
    int polynomialLen = strlen(polynomial);
    char* temp = (char*)malloc((polynomialLen + 1) * sizeof(char));
    strcpy(temp, polynomial);

    // 시작
    int calculatResult[2] = { 0,0 }; // x항, 그냥 숫자

    // 첫번째
    char* buffer = strtok(temp, " ");
    int bufferLen = 0;

    while (buffer != NULL)
    {
        bufferLen = strlen(buffer);
        int currNum = 0;
        int isX = 0; // 1 = true

        // 값 찾기
        for (int i = 0; i < bufferLen; i++)
        {
            if (isX == 0 && buffer[i] == 'x') isX = 1;
            else
            {
                currNum *= 10;
                currNum += buffer[i] - '0';
            }
        }

        if (isX == 1)
        {
            if (buffer[0] == 'x') calculatResult[0]++;
            else calculatResult[0] += currNum;
        }
        else
        {
            calculatResult[1] += currNum;
        }

        buffer = strtok(NULL, " "); // + 찾기
        buffer = strtok(NULL, " "); // 다음 수 찾기
    }

    char* xNumStr;
    char* numStr;

    int xNumStrLen = 0;
    int numStrLen = 0;

    // itoa
    // 길이 구하기
    int xNum = calculatResult[0];
    while (xNum != 0)
    {
        xNum /= 10;
        xNumStrLen++;
    }

    int num = calculatResult[1];
    while (num != 0)
    {
        num /= 10;
        numStrLen++;
    }

    xNumStr = (char*)malloc((xNumStrLen + 1) * sizeof(char));
    numStr = (char*)malloc((numStrLen + 1) * sizeof(char));

    xNum = calculatResult[0];
    for (int i = xNumStrLen - 1; i >= 0; i--)
    {
        int currNum = xNum % 10;
        xNumStr[i] = currNum + '0';
        xNum /= 10;
    }
    xNumStr[xNumStrLen] = '\0';

    num = calculatResult[1];
    for (int i = numStrLen - 1; i >= 0; i--)
    {
        int currNum = num % 10;
        numStr[i] = currNum + '0';
        num /= 10;
    }
    numStr[numStrLen] = '\0';

    int xNumLen = strlen(xNumStr);
    int numLen = strlen(numStr);
    int totalLen = xNumLen + numLen + 5;

    char* answer = (char*)calloc(totalLen, sizeof(char));

    // 숫자x 붙이기
    if (calculatResult[0] != 0)
    {
        if(calculatResult[0] != 1) strcat(answer, xNumStr);
        strcat(answer, "x");
    }

    // +
    if (calculatResult[0] != 0 && calculatResult[1] != 0)
    {
        strcat(answer, " + ");
    }

    // 숫자 붙이기
    if (calculatResult[1] != 0)
    {
        strcat(answer, numStr);
    }

    free(temp);

    return answer;
}

int main()
{
    const char* s = "20";
    solution(s);
}