#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int** score, size_t score_rows, size_t score_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(score_rows, sizeof(int));
    double* temp = (double*)calloc(score_rows, sizeof(double));
    int* same = (int*)calloc(score_rows, sizeof(int));
    int sameCount = 0;
    for (int i = 0; i < score_rows; i++)
    {
        temp[i] = ((double)score[i][0] + (double)score[i][1]) / 2.0;
    }
    for (int i = 0; i < score_rows; i++)
    {
        int rank = 1;
        for (int j = 0; j < score_rows; j++)
        {
            if (i == j) continue;
            if (temp[j] > temp[i])
            {
                rank++;
            }

            if (temp[j] == temp[i])
            {
                same[sameCount++] = j;
            }
        }

        for (int j = 0; j < sameCount; j++)
        {
            answer[same[j]] = rank;
        }
        answer[i] = rank;
        sameCount = 0;
    }

    return answer;
}


int main()
{
    int inputData[6][2] = {
        {1, 3},
        {3, 1},
        {2, 3},
        {3, 2},
        {1, 2},
        {1, 1}
    };

    int** input = (int**)malloc(sizeof(int*) * 6);
    for (int i = 0; i < 6; i++) {
        input[i] = (int*)malloc(sizeof(int) * 2);
        input[i][0] = inputData[i][0];
        input[i][1] = inputData[i][1];
    }

    int expected[6] = { 3, 3, 1, 1, 5, 6 };

    solution(input, 6, 2);
}