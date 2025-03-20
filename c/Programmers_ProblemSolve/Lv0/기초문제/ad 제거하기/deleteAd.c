#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* strArr[], size_t strArr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* remain = (int*)malloc(strArr_len * sizeof(int)); // 출력할 문자열 확인용 (1 : 출력, 0 : 미출력)
    char* ad = (char*)malloc(3 * sizeof(char));
    strcpy(ad, "ad");
    // remain 초기화
    int cnt = strArr_len;
    for (int i = 0; i < strArr_len; i++)
    {
        remain[i] = 1;
    }

    for (int i = 0; i < strArr_len; i++)
    {
        int currLen = strlen(strArr[i]);
        // 각 문자열 검사
        for (int j = 0; j < currLen - 1; j++)
        {
            int correct = 0;
            for (int k = 0; k < 2; k++)
            {
                if (strArr[i][j + k] == ad[k]) correct++;
            }

            if (correct == 2)
            {
                remain[i] = 0;
                cnt--;
                break;
            }
        }
    }

    char** answer = (char**)malloc(cnt * sizeof(char*));
    int answer_cnt = 0;
    for (int i = 0; i < strArr_len; i++)
    {
        if (remain[i] == 0) continue;

        int currLen = strlen(strArr[i]);
        answer[answer_cnt] = (char*)malloc(currLen * sizeof(char));
        strcpy(answer[answer_cnt++], strArr[i]);
    }

    free(remain);
    free(ad);
    return answer;
}

int main()
{
    char* str[] = {"and", "notad", "abcd"};
    solution(str, 3);


    //int* remain = (int*)malloc(6 * sizeof(int)); // 출력할 문자열 확인용 (1 : 출력, 0 : 미출력)
    //char* ad = (char*)malloc(3 * sizeof(char));
    ////ad = "ad"; -> "ad"가 할당된 다른 주소 저장
    //strcpy(ad, "ad");
    //// for문 넣기
    ////ad[0] = 'a';
    ////ad[1] = 'd';

    //free(remain);
    //free(ad);
}