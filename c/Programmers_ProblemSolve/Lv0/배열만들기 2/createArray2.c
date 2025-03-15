#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문제
// 5나 0으로 이뤄진 수를 오름차순으로 반환하기
#define MAX_BUFFER_SIZE 1024

int* solution(int l, int r) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    char** strOnly0and5 = (char**)malloc(MAX_BUFFER_SIZE * sizeof(char*)); // 조건 값 저장용 배열
    char* temp = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char)); // 현재 확인할 문자열

    int tempLength = 1, currNum = 0, dataSize = 0, answerSize = 0;
    temp[0] = '5', temp[tempLength] = '\0'; // 초기값 5설정

    // 저장
    strOnly0and5[dataSize] = (char*)malloc((tempLength + 1) * sizeof(char));
    strOnly0and5[dataSize] = strcpy(strOnly0and5[dataSize], temp);
    dataSize++;

    // 5부터 r까지의 조건 값 추출
    while (currNum < r)
    {
        // 1. 모든 위치가 5인가?
        int count = 0;
        for (int i = 0; i < tempLength; i++)
        {
            if (temp[i] == '5') count++;
        }

        if (count == tempLength) // 모든 자리가 5다
        {
            tempLength++;
            // 첫 자리를 제외한 모든 값을 0으로 변경
            for (int i = 1; i < tempLength; i++)
            {
                temp[i] = '0';
            }
            temp[tempLength] = '\0';
        }
        else // 모든 자리가 5가 아님
        {
            for (int i = tempLength - 1; i > 0; i--)
            {
                if (temp[i] == '0')
                {
                    temp[i] = '5';
                    break;
                }
                else // 해당 위치가 5임
                {
                    temp[i] = '0';
                }
            }
        }

        strOnly0and5[dataSize] = (char*)malloc((tempLength + 1) * sizeof(char));
        strOnly0and5[dataSize] = strcpy(strOnly0and5[dataSize], temp);
        dataSize++;
        if (temp)
        {
            currNum = atoi(temp);
            if (currNum >= l && currNum <= r) answerSize++;
        }
    }
    free(temp);

    // 범위 내에 있는 값 저장 후 반환
    currNum = 0;
    int answerCount = 0;
    int* answer = (int*)malloc((answerSize) * sizeof(int));
    for (int i = 0; i < dataSize; i++)
    {
        currNum = atoi(strOnly0and5[i]);
        if (currNum >= l && currNum <= r)
        {
            answer[answerCount++] = currNum;
        }
    }
    free(strOnly0and5);

    // 범위내 값이 존재 하지 않음
    if (answerCount == 0)
    {
        free(answer);
        answer = (int*)malloc(1 * sizeof(int));
        answer[0] = -1;
        return answer;
    }

    return answer;
}

int main()
{
    solution(5, 555);
}