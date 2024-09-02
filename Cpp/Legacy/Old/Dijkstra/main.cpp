#include <iostream>

#define INF 10000000
#define N 5

using namespace std;

int weight[N][N]{ { 0,7,4,6,1},
	{INF,0,INF,INF,INF},
	{INF,2,0,5,INF},
	{INF,3,INF,0,INF},
	{INF,INF,INF,1,0}
};

bool visit[N];
int dist[N];
int min_node;

int Get_Small_node()
{
	// 최소 비용 노트 탐색
	int min = INF;
	int minpos = 0;

	for (int i = 0; i < N; i++)
	{
		if (dist[i] < min && !visit[i])
		{
			min = dist[i];
			minpos = i;
		}
	}
	return minpos;
}

void dijkstra(int start)
{
	for (int i = 0; i < N; i++)
	{
		dist[i] = weight[start][i];
	}

	visit[start] = true;
	for (int repeat = 0; repeat < N - 1; repeat++)
	{
		min_node = Get_Small_node();
		visit[min_node] = true;
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
				if (dist[min_node] + weight[min_node][i] < dist[i])
					dist[i] = dist[min_node] + weight[min_node][i];
		}
	}
}

int main()
{
	dijkstra(0);
	for (int i = 0; i < N; i++)
		cout << dist[i] << " ";

	return 0;
}