// 2252
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 32001

// ��, ����, �����
int n, inDegree[MAX], result[MAX];
vector<int> a[MAX];

void topolgySort()
{
	queue<int> q;

	// ���������� 0�� ���� �ִ´�.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	// ���� ��ŭ �ݺ��Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		int front = q.front();
		q.pop();

		result[i] = front;

		for (int j = 0; j < a[front].size(); j++)
		{
			int next = a[front][j];

			if (--inDegree[next] == 0)
			{
				q.push(next);
			}
		}

	}

	for (int k = 1; k <= n; k++)
	{
		cout << result[k] << " ";
	}
}

int main()
{
	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		a[x].push_back(y);
		inDegree[y]++;
	}

	topolgySort();

	return 0;
}