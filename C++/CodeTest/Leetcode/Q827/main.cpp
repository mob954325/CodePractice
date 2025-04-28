#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

int largestIsland(std::vector<std::vector<int>>& grid);

int main()
{
    std::vector<std::vector<int>> v =
    {
        {0,1},
        {1,0}
    };

    std::cout << largestIsland(v);
}



int largestIsland(std::vector<std::vector<int>>& grid) {
    // 0�� 1�� �̷��� �׸��忡�� �� �ѹ� 0�� 1�� �ٲپ��� ��
    // ���� ���� ������ ���� ���� ���� ��ȯ�ض�

    int sizeY = grid.size();
    int sizeX = grid[0].size();
    int island_id = 2; // 0�� 1�� �ƴ� ���ο� �� ID �Ҵ�
    std::unordered_map<int, int> island_size; // �� ID -> ũ�� ����

    int dirX[4] = { 1, -1, 0, 0 };
    int dirY[4] = { 0, 0, 1, -1 };

    // 1. ��� ���� BFS/DFS�� Ž���Ͽ� �� ũ�� ���� (O(N��))
    for (int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if (grid[y][x] == 1)
            {
                int size = 0;
                std::queue<std::pair<int, int>> q;
                q.push({ y,x });
                grid[y][x] = island_id;

                while (!q.empty())
                {
                    auto front = q.front();
                    q.pop();
                    size++;

                    for (int d = 0; d < 4; d++)
                    {
                        int nextY = front.first + dirY[d];
                        int nextX = front.second + dirX[d];

                        // ���� �ʰ��� �̹� �湮�� ��ġ�� ����
                        if (nextX < 0 || nextX >= sizeX || 
                            nextY < 0 || nextY >= sizeY || 
                            grid[nextY][nextX] != 1)
                            continue;

                        grid[nextY][nextX] = island_id;
                        q.push({ nextY, nextX });
                    }
                }

                island_size[island_id] = size;
                island_id++; // ���� �� ID ����
            }
        }
    }

    // 2. �ִ뼶 ũ�� ����
    int largest = 0;
    for (const auto& p: island_size)
    {
        largest = std::max(largest, p.second);
    }

    // 3. 0�� 1�� �ٲ��� ���� �ִ� ũ�� ã�� (O(N��))
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            if (grid[y][x] == 0)
            {
                std::unordered_map<int, bool> visited;
                int new_size = 1; // ���� ��ġ�� 1�� �مf���Ƿ� ũ�� 1���� ����

                for (int d = 0; d < 4; d++)
                {
                    int nextY = y + dirY[d];
                    int nextX = x + dirX[d];

                    if (nextX < 0 || nextX >= sizeX ||
                        nextY < 0 || nextY >= sizeY) continue;

                    int neighbor_id = grid[nextY][nextX];
                    if (neighbor_id > 1 && !visited[neighbor_id])
                    {
                        new_size += island_size[neighbor_id];
                        visited[neighbor_id] = true;
                    }
                }
                largest = std::max(largest, new_size);
            }
        }
    }

    return largest;
}