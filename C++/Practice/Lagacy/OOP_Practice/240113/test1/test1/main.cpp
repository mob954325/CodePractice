#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int height = 0;
int maxNum = 0;
int countNum = 0;
vector<vector<int>> m(100, vector<int>(100, 0));
vector<vector<bool>> visited(100,vector<bool>(100, false));

int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0, 0, 1,-1 };

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}
}

void BFS(int x, int y, int height)
{
	queue<pair<int,int>> q;
	
	q.push({ x, y });
	
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
	
		q.pop();
	
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
	
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
			{
				if (!visited[nextX][nextY])
				{
					visited[nextX][nextY] = true;
	
					if (m[nextX][nextY] > height)
					{
						q.push({ nextX, nextY });
					}
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int safeNum;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int n;
			cin >> n;
			m[i][j] = n;

			height = max(height, m[i][j]);
		}
	}
	
	while (height >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[i][j] > height)
				{
					BFS(i,j, height);
					countNum++;
				}
			}
		}
		
		maxNum = max(maxNum, countNum);

		reset();
		countNum = 0;
		height--;
	}

	cout << maxNum;
}