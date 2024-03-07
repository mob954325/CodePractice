// Queue를 이용한 BFS탐색 알고리즘

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertexNum, edgeNum;			// 정점의 수, 간선의 수

vector<vector<int>> graph;		// 그래프
vector<bool> visited;			// 방문 여부
queue<int> q;					// 큐

/// <summary>
/// vector를 초기화 하는 함수
/// </summary>
/// <param name="vNum">정점의 개수</param>
/// <param name="eNum">간선의 개수</param>
void Initialize(int vNum, int eNum)
{
	graph.assign(vNum + 1, vector<int>());
	visited.assign(vNum + 1, false);
}

void BFS(int startVertex)
{
	// 시작 정점 큐에 넣기
	q.push(startVertex);

	while (!q.empty())
	{
		int currentVertex = q.front();	// 현재 정점
		visited[currentVertex] = true;	// 방문 처리

		q.pop();

		cout << currentVertex;

		for (int i = 0; i < graph[currentVertex].size(); i++)
		{
			int nextVertex = graph[currentVertex][i];

			if (visited[nextVertex])	// 방문한 정점이면 큐 삽입을 하지 않는다.
				continue;

			q.push(nextVertex);			// 인접 노드 큐 삽입
		}

		if(!q.empty()) cout << " -> ";
	}
}

int main()
{
	cin >> vertexNum >> edgeNum;

	Initialize(vertexNum, edgeNum);	// 초기화

	for (int i = 0; i < edgeNum; i++)
	{
		int vertex, to; // 정점, 연결된 정점
		cin >> vertex >> to;

		graph[vertex].push_back(to);
	}

	BFS(1);
}

// 6 5
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6