#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n; // ������ ����
vector<int> inDegree; // ���� ���� ����
vector<vector<int>> graph; // ������ ����
queue<int> q; // ���� ������ ���� ť

void input()
{
	cin >> n;

	// �޸� ������ ������ŭ �Ҵ�
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
	// ���������� 0�� ������ ť�� ����
	for (int cur = 1; cur <= n; cur++)
	{
		if (inDegree[cur] == 0)
			q.push(cur);
	}

	// �������� ��ŭ ����
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

		// queue���� ���̼� ���� �湮 ���� ����
		int cur = q.front();
		q.pop();

		cout << "�湮 ��� : " << cur << "\n";

		// ������ ������ Ȯ���ϸ� ������ 1�� ���ҽ�Ű��, ���������� 0�̸� queue�� ����
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