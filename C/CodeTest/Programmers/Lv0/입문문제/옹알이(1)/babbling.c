#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

// 문제
// "aya", "ye", "woo", "ma로 합쳐진 문자열인지 확인하기

// 해결
// 1. start와 end로 구간 유지하면서 값 확인하기
// 1.1 end는 발음 할 수 있는 단어의 길이값 + start위치 값이다.
// 1.2 만약 단어가 존재하면 start를 end + 1위치로 이동 시킨 후 다시 확인한다.
// 1.3 모든 단어를 확인하고 end가 문자열의 길이 - 1값에 있으면 다음 문자열을 확인한다.

#define MAX_BABBLING_COUNT 4

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 4, 17 -> 문자 확인중 중간에 문자가 다름

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

// 문제
// "aya", "ye", "woo", "ma로 합쳐진 문자열인지 확인하기

// 해결
// 0. 각 문자열 플래그 데이터 생성, 문자열 데이터 생성
// 1. 각 문자열 배열확인하기
//  1.1 만약 첫 번째시도에 동일한 문자열이 없으면 다음꺼 확인
//  1.2 모든 단어가 사용되었거나 그 전에 1.1상황이 없으면 개수 증가

#define MAX_BABBLING_COUNT 4

int solution(const char* babbling[], size_t babbling_len) {
    char* compWord[MAX_BABBLING_COUNT] = { "aya", "ye", "woo", "ma" }; // 발음 할 수 있는 개수 / 2차원 배열
    int isUsed[MAX_BABBLING_COUNT] = { 0,0,0,0 };                         // 해당 발음이 있는지 확인하는 배열

    int answer = 0;
    int checkIndex = 0;
    for (int i = 0; i < babbling_len; i++)
    {
        int currStrLen = strlen(babbling[i]);
        if (currStrLen < 2 || currStrLen > 10) continue; // 조건에 만족하지 않는 길이

        int compWordIndex = 0;
        int correct = 0, fullCorrect = 0;
        int checked = 0; // 동일한 위치에 확인한 횟수
        while (checkIndex < currStrLen)
        {
            if (checked == 4) break; // 아무런 결과 없이 모든 단어 체크하면 다음 문자열 확인
            compWordIndex %= MAX_BABBLING_COUNT;

            // 이미 사용한 단어는 건너뛰기
            if (isUsed[compWordIndex] == 1)
            {
                compWordIndex++;
                continue;
            }

            // 문자가 다르다
            if (babbling[i][checkIndex] != compWord[compWordIndex][checkIndex - fullCorrect])
            {
                // 문자 확인 도중에 문자가 다르면? 
                correct = 0;
                compWordIndex++;
                checked++;
                continue;
            }
            else // 문자가 같다
            {
                checked = 0;
                correct++;
                checkIndex++;
            }

            // 확인해서 모두 같다
            if (correct == strlen(compWord[compWordIndex]))
            {
                fullCorrect += correct;
                correct = 0;
                isUsed[compWordIndex++] = 1;
            }
        } // while end

        if (fullCorrect == currStrLen) answer++;

        // 초기화
        for (int j = 0; j < MAX_BABBLING_COUNT; j++)
        {
            isUsed[j] = 0;
        }
        checkIndex = 0;
    }

    return answer;
}

int main()
{
    const char* b[5] = { "ayaye", "uuuma", "ye", "yemawoo", "ayaa" };
    printf("%d", solution(b, 5));
}

