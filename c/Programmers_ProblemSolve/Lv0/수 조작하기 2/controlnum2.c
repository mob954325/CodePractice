#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 조건에 따라 변화한 수의 배열 numlog[]
// 해당 로그에 따라서 조작문자열 추출하기
// 현재로그 - 이전로그해서 조건 찾기
// 1 -> w
// -1 -> s
// 10 -> d
// -10 -> a


// numLog_len은 배열 numLog의 길이입니다.
char* solution(int numLog[], size_t numLog_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.    
    char* answer = (char*)malloc((numLog_len + 1) * sizeof(char));

    int answer_cnt = 0;
    for (int i = 1; i < numLog_len; i++)
    {
        int diff = numLog[i] - numLog[i - 1];
        if (diff == 1)
        {
            answer[answer_cnt++] = 'w';
        }
        else if (diff == -1)
        {
            answer[answer_cnt++] = 's';
        }
        else if (diff == 10)
        {
            answer[answer_cnt++] = 'd';
        }
        else if (diff == -10)
        {
            answer[answer_cnt++] = 'a';
        }
    }

    answer[answer_cnt] = '\0';

    return answer;
}