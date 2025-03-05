#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>

int const MAX = 100;

std::vector<int> adjacencyList[MAX * MAX];
int maze[MAX][MAX];
int visitCount[MAX * MAX];
int directionX[4] = { 1 , -1, 0, 0 };
int directionY[4] = { 0, 0,  1, -1 };

static bool isVaild(int x, int y, int x_max, int y_max)
{
	return x >= 0 && y >= 0 && x < x_max && y < y_max;
}

static void BFS(int xLength, int yLegnth)
{ 
	std::queue<int> q;
	int count = 0;
	visitCount[0] = 1;

	for (int i = 0; i < adjacencyList[0].size(); i++)
	{
		int adjacency = adjacencyList[0][i];
		q.push(adjacency);
		visitCount[adjacency] = visitCount[0] + 1;
	}

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < adjacencyList[current].size(); i++)
		{
			if (visitCount[adjacencyList[current][i]] == 0)
			{
				q.push(adjacencyList[current][i]);
				visitCount[adjacencyList[current][i]] = visitCount[current] + 1;
			}
		}
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	// 미로 생성
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			scanf("%1d", &maze[y][x]);
		}
	}

	// 인접 리스트 정리
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (maze[y][x] == 0)
				continue;

			for (int d = 0; d < 4; d++)
			{
				int nextX = x + directionX[d];
				int nextY = y + directionY[d];

				if (!isVaild(nextX, nextY, m, n))
					continue;

				if (maze[nextY][nextX] == 1)
				{
					adjacencyList[y * m + x].push_back(nextY * m + nextX);
				}
			}
		}
	}

	// BFS 실행
	std::fill(visitCount, visitCount + n * m, 0);
	BFS(m, n);

	if (n > 0 && m > 0)
	{
		printf("%d", visitCount[n * m - 1]);
	}
}