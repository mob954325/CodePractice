// Queue�� �̿��� BFSŽ�� �˰���

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertexNum, edgeNum;			// ������ ��, ������ ��

vector<vector<int>> graph;		// �׷���
vector<bool> visited;			// �湮 ����
queue<int> q;					// ť

/// <summary>
/// vector�� �ʱ�ȭ �ϴ� �Լ�
/// </summary>
/// <param name="vNum">������ ����</param>
/// <param name="eNum">������ ����</param>
void Initialize(int vNum, int eNum)
{
	graph.assign(vNum + 1, vector<int>());
	visited.assign(vNum + 1, false);
}

void BFS(int startVertex)
{
	// ���� ���� ť�� �ֱ�
	q.push(startVertex);

	while (!q.empty())
	{
		int currentVertex = q.front();	// ���� ����
		visited[currentVertex] = true;	// �湮 ó��

		q.pop();

		cout << currentVertex;

		for (int i = 0; i < graph[currentVertex].size(); i++)
		{
			int nextVertex = graph[currentVertex][i];

			if (visited[nextVertex])	// �湮�� �����̸� ť ������ ���� �ʴ´�.
				continue;

			q.push(nextVertex);			// ���� ��� ť ����
		}

		if(!q.empty()) cout << " -> ";
	}
}

int main()
{
	cin >> vertexNum >> edgeNum;

	Initialize(vertexNum, edgeNum);	// �ʱ�ȭ

	for (int i = 0; i < edgeNum; i++)
	{
		int vertex, to; // ����, ����� ����
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