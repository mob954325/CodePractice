#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

const int MAX = 100000;
int countList[MAX];

static void BFS(int start, int goal)
{
	std::queue<int> q;
	q.push(start);
	int count = 1;
	int qCount = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		qCount++;

		if (qCount == 3)
		{
			qCount == 0;
			count++;
		}

		if (current == goal)
		{
			printf("%d", countList[current]);
			break;
		}

		if (current + 1 >= 0)
		{
			q.push(current + 1);
			countList[current + 1] = count;
		}
		if (current - 1 >= 0)
		{
			q.push(current - 1);
			countList[current - 1] = count;
		}
		if (current * 2 >= 0)
		{
			q.push(current * 2);
			countList[current * 2] = count;
		}
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	std::fill(countList, countList + MAX, 0);
	BFS(n, k);
	int a = 0;
}