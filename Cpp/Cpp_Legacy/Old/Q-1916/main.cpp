#include <iostream>
#include <vector>
#define INF 100000001

using namespace std;

int vertexNum, edgeNum;

vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;
int min_node;

void init(int n) // √ ±‚»≠
{
	graph.assign(n + 1, vector<int>(n + 1, INF));
	dist.assign(n + 1, INF);
	visited.assign(n + 1, false);
}

int Get_Small_Node()
{
	int min = INF;
	int minPos = 0;

	for (int i = 1; i <= vertexNum; i++)
	{
		if(dist[i] < min && !visited[i])
		{
			min = dist[i];
			minPos = i;
		}
	}
	return minPos;
}

void dijkstra(int start)
{
	for (int i = 1; i <= vertexNum; i++)
	{
		dist[i] = graph[start][i];
	}

	visited[start] = true;

	for (int r = 1; r < vertexNum; r++)
	{
		min_node = Get_Small_Node();
		visited[min_node] = true;

		for (int i = 1; i <= vertexNum; i++)
		{
			if (!visited[i])
			{
				if (dist[min_node] + graph[min_node][i] < dist[i])
					dist[i] = dist[min_node] + graph[min_node][i];
			}
		}
	} 
}

int main()
{
	cin >> vertexNum >> edgeNum;
	init(vertexNum);

	for(int i = 1; i <= vertexNum; i++)
		graph[i][i] = 0;

	for (int i = 0; i < edgeNum; i++)
	{
		int start, to, weight;
		cin >> start >> to >> weight;

		if(weight < graph[start][to])
			graph[start][to] = weight;

	}


	int start, goal;
	cin >> start >> goal;

	dijkstra(start);
	cout << dist[goal];
}