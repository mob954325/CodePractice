#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

int num = 4;
int INF = 1000000000;

int a[4][4] = {
	{0,   5,  INF,  8},
	{7,   0,  9,    INF},
	{2,   INF,0,    4},
	{INF, INF,3,    8},
};

void FW()
{
	int d[4][4];

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; i < num; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	// 거쳐가는 노드
	for (int k = 0; k < num; k++)
	{
		// start
		for (int i = 0; i < num; i++)
		{
			// goal
			for (int j = 0; j < num; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; i < num; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	FW();
	return 0;
}

