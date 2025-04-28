// 1516

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 501

// ��, ����, �����, �ð�
int n, inDegree[MAX], result[MAX], time[MAX];
vector<int> a[MAX];

void topolgySort()
{
	queue<int> q;

	// ���������� 0�� ���� �ִ´�.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			result[i] = time[i];
			q.push(i);
		}
	}

	// ���� ��ŭ �ݺ��Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		int front = q.front();
		q.pop();

		//result[i] = front;

		for (int j = 0; j < a[front].size(); j++)
		{
			int next = a[front][j];

			result[next] = max(result[next], result[front] + time[next]);

			if (--inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	for (int k = 1; k <= n; k++)
	{
		cout << result[k] << "\n";
	}
}

int main()
{
	int t;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];

		while (1)
		{
			int x;
			cin >> x;

			if (x == -1)
				break;

			inDegree[i]++;
			a[x].push_back(i);
		}
		
	}

	topolgySort();

	return 0;
}