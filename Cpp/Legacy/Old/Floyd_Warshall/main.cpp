#include<iostream>
#include <vector>
#include <algorithm>

#define INF 10000000

using namespace std;

int cityNum, busNum;
vector<vector<int>> graph;
vector<vector<int>> dist;

void Init(int n)
{
	graph.assign(n+1, vector<int>(n+1,INF));
	dist.assign(n+1, vector<int>(n+1,INF));
}

void Print()
{
	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			if (dist[i][j] == INF)
				dist[i][j] = 0;

			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

void Floyd_warshall()
{
	int i, j, k;

	for (i = 1; i <= cityNum; i++)
	{
		for (j = 1; j <= cityNum; j++)
		{
			if (i == j) dist[i][j] = 0;
			else if (graph[i][j]) dist[i][j] = graph[i][j];
			else dist[i][j] = INF;
		}
	}

	for (k = 1; k <= cityNum; k++)
	{
		for (i = 1; i <= cityNum; i++)
		{
			for (j = 1; j <= cityNum; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main()
{
	cin >> cityNum >> busNum;

	Init(cityNum);

	for (int i = 1; i <= busNum; i++)
	{
		int vertex, to, weight;
		cin >> vertex >> to >> weight;

		if(graph[vertex][to] > weight)
			graph[vertex][to] = weight;
	}

	Floyd_warshall();

	Print();

	return 0;
}