#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1 2 4 5 9 
// 1 2 4 9
// 1 4 9

// lines_rows�� 2���� �迭 lines�� �� ����, lines_cols�� 2���� �迭 lines�� �� �����Դϴ�.
int solution(int** lines, size_t lines_rows, size_t lines_cols) {
    int answer = 0;

    for (int i = 0; i < lines_rows; i++)
    {
        for (int j = 0; j < lines_rows; j++)
        {
            if (i == j) continue;

            if (lines[i][0] < lines[j][1] && lines[i][1] > lines[j][0])
            {
                int result = 0;
                if (lines[i][1] < lines[j][1] && lines[i][0] < lines[j][0]) // i ������ ������ ��
                {
                    result = lines[i][1] - lines[j][0];

                    // ��ġ�� ���� ����
                    int temp = lines[i][1];
                    lines[i][1] = lines[j][0];
                    lines[j][0] = temp;
                }
                else if (lines[i][1] > lines[j][1] && lines[i][0] > lines[j][0]) // i ������ �������� ��
                {
                    result = lines[j][1] - lines[i][0];

                    // ��ġ�� ���� ����
                    int temp = lines[i][0];
                    lines[i][0] = lines[j][1];
                    lines[j][1] = temp;
                }
                else // i��° ������ j ���оȿ� ���� ��
                {
                    result = lines[i][1] - lines[i][0];

                    // ��ġ�� ������ �����ϰ� ���ο� ���� �� �� �߰��ϱ�
                    if (lines[i][0] > lines[j][0])
                    {
                        result = lines[i][1] - lines[i][0];
                        // i�� j���� ���� ��
                        int temp1 = lines[i][0];
                        int temp2 = lines[i][1];

                        lines[i][0] = temp2;
                        lines[i][1] = lines[j][1];
                        lines[j][1] = temp1;
                    }
                    else
                    {
                        result = lines[j][1] - lines[j][0];
                        // i�� j���� Ŭ ��
                        int temp1 = lines[j][0];
                        int temp2 = lines[j][1];

                        lines[j][0] = temp2;
                        lines[j][1] = lines[i][1];
                        lines[i][1] = temp1;
                    }
                }

                answer += result;
            }
        }
    }
    return answer;
}

int main()
{
    int rows = 3;
    int cols = 2;

    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // �� �ʱ�ȭ
    arr[0][0] = 0; arr[0][1] = 5;
    arr[1][0] = 2; arr[1][1] = 4;
    arr[2][0] = 3; arr[2][1] = 5;

    solution(arr, 3, 2);
}