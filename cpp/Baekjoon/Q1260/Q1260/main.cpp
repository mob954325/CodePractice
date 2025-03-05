#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>

const int MAX = 1001;

std::vector<int> adjacencyList[1001]; // 인접 리스트
bool visited[MAX];

static void DFS(int start)
{
	std::stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		int current = s.top();
		s.pop();

		if (!visited[current])
		{
			visited[current] = true;
			printf("%d ", current);
		}

		for (auto it = adjacencyList[current].rbegin(); it != adjacencyList[current].rend(); it++)
		{
			if (!visited[*it])
			{
				s.push(*it);
			}
		}
	}
}

static void BFS(int start)
{
	std::queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (!visited[current])
		{
			visited[current] = true;
			printf("%d ", current);
		}

		for (auto it = adjacencyList[current].begin(); it != adjacencyList[current].end(); it++)
		{
			if (!visited[*it])
			{
				q.push(*it);
			}
		}
	}
}

int main()
{
	int n = 0, m = 0, v = 0; // 정점의 개수, 간선의 개수, 탐색 시작할 정점의 번호
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int from = 0, to = 0;
		scanf("%d %d", &from, &to);

		adjacencyList[from].push_back(to);
		adjacencyList[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		std::sort(adjacencyList[i].begin(), adjacencyList[i].end());
	}

	std::fill(visited, visited + MAX, false);
	DFS(v);
	printf("\n");
	
	std::fill(visited, visited + MAX, false);
	BFS(v);
}