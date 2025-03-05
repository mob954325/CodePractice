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
    // 0과 1로 이뤄진 그리드에서 단 한번 0을 1로 바꾸었을 때
    // 가장 넓은 범위를 가진 개수 값을 반환해라

    int sizeY = grid.size();
    int sizeX = grid[0].size();
    int island_id = 2; // 0과 1이 아닌 새로운 섬 ID 할당
    std::unordered_map<int, int> island_size; // 섬 ID -> 크기 저장

    int dirX[4] = { 1, -1, 0, 0 };
    int dirY[4] = { 0, 0, 1, -1 };

    // 1. 모든 섬을 BFS/DFS로 탐색하여 섬 크기 저장 (O(N²))
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

                        // 범위 초과나 이미 방문한 위치면 무시
                        if (nextX < 0 || nextX >= sizeX || 
                            nextY < 0 || nextY >= sizeY || 
                            grid[nextY][nextX] != 1)
                            continue;

                        grid[nextY][nextX] = island_id;
                        q.push({ nextY, nextX });
                    }
                }

                island_size[island_id] = size;
                island_id++; // 다음 섬 ID 증가
            }
        }
    }

    // 2. 최대섬 크기 저장
    int largest = 0;
    for (const auto& p: island_size)
    {
        largest = std::max(largest, p.second);
    }

    // 3. 0을 1로 바꿨을 때의 최대 크기 찾기 (O(N²))
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            if (grid[y][x] == 0)
            {
                std::unordered_map<int, bool> visited;
                int new_size = 1; // 현재 위치를 1로 바꿧으므로 크기 1부터 시작

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