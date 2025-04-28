#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// spell_len�� �迭 spell�� �����Դϴ�.
// dic_len�� �迭 dic�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    int answer = 0;
    int check[10];

    for (int i = 0; i < 10; i++)
    {
        check[i] = 0;
    }

    for (int i = 0; i < dic_len; i++)
    {
        int index = 0, count = 0;
        int len = strlen(dic[i]);

        for (int j = 0; j < 10; j++)
        {
            check[j] = 0;
        }

        if (len != spell_len) continue;

        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < spell_len; k++)
            {
                if (check[k] != 1 && (dic[i][j] == spell[k][0]))
                {
                    check[k] = 1;
                    count++;
                    break;
                }
            }

            index++;
        }

        if (count == len) return 1;
    }
    return 2;
}

int main()
{
    // ù ��° �迭
    const char* words1[] = { "s", "o", "m", "d" };
    int size1 = sizeof(words1) / sizeof(words1[0]);

    // �� ��° �迭
    const char* words2[] = { "moos", "dzx", "smm", "sunmmo", "som" };
    int size2 = sizeof(words2) / sizeof(words2[0]);

    solution(words1, 4, words2, 6);
}