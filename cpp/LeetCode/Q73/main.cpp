#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix);

int main()
{

}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    // 0�� ã���� ���� ���� ��� 0���� ����

    // �ذ�
    // O(n^2) �ð� ���⵵
    // �����ġ Ž�� �� �ش� ��ġ�� 0�̸� ����

    int columnSize = matrix.size();
    int rowSize = matrix[0].size();

    std::vector<bool> visited(rowSize * columnSize, false);

    for (int y = 0; y < columnSize; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            if (matrix[y][x] == 0 && !visited[y * rowSize + x])
            {
                // 4 ���� ��� 0���� �����
                for (int i = 0; i < rowSize; i++)
                {
                    if (matrix[y][i] == 0) continue;

                    matrix[y][i] = 0;
                    visited[y * rowSize + i] = true;
                }
                for (int i = 0; i < columnSize; i++)
                {
                    if (matrix[i][x] == 0) continue;

                    matrix[i][x] = 0;
                    visited[i * rowSize + x] = true;
                }
            }
            else // 0�� �ƴϸ� ����
            {
                visited[y * rowSize + x] = true;
                continue;
            }
        }
    }
}