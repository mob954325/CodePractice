#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n; // 정점의 개수
vector<int> inDegree; // 진입 차수 정보
vector<vector<int>> graph; // 간선의 정보
queue<int> q; // 위상 정렬을 위한 큐

void input()
{
	cin >> n;

	// 메모리 공간을 정점만큼 할당
	inDegree.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>(0,0));

	for (int i = 0; i < n; i++)
	{
		int start, edge;
		cin >> start >> edge;

		graph[start].emplace_back(edge);
		inDegree[edge]++;
	}
}

void topology_sort()
{
	// 진입차수가 0인 정점들 큐에 삽입
	for (int cur = 1; cur <= n; cur++)
	{
		if (inDegree[cur] == 0)
			q.push(cur);
	}

	// 정점개수 만큼 실행
	for (int i = 0; i < n; i++)
	{
		if (q.empty())
		{
			cout << "cycle Detected\n";
			return;
		}
	}

	while (!q.empty())
	{

		// queue에서 뽑이서 현재 방문 노드로 설정
		int cur = q.front();
		q.pop();

		cout << "방문 노드 : " << cur << "\n";

		// 인저한 노드들을 확인하며 차수를 1씩 감소시키고, 진입차수가 0이면 queue에 삽입
		for (int k = 0; k < graph[cur].size(); k++)
		{
			int next = graph[cur][k];
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	input();
	topology_sort();
}