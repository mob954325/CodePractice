#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix);

int main()
{

}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    // 0을 찾으면 가로 세로 모두 0으로 변경

    // 해결
    // O(n^2) 시간 복잡도
    // 모든위치 탐색 후 해당 위치가 0이면 변경

    int columnSize = matrix.size();
    int rowSize = matrix[0].size();

    std::vector<bool> visited(rowSize * columnSize, false);

    for (int y = 0; y < columnSize; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            if (matrix[y][x] == 0 && !visited[y * rowSize + x])
            {
                // 4 방향 모두 0으로 만들기
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
            else // 0이 아니면 무시
            {
                visited[y * rowSize + x] = true;
                continue;
            }
        }
    }
}