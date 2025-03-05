#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

struct Edge {
	int to;
	int weight;

	Edge(int t, int w) : to(t), weight(w) {}

	bool operator>(const Edge& other) const
	{
		return weight > other.weight;
	}
};

vector<vector<int>> Dijksra(const vector<vector<Edge>>& g, int start)
{
	int V = g.size();
	vector<vector<int>> distance(V, vector<int>(V, INT_MAX)); // 거리
	vector<vector<int>> paths(V, vector<int>(V, -1)); // 경로 저장

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // queue 우선순위
	pq.push(Edge(start, 0));
	distance[start][start] = 0; // 자신

	while (!pq.empty())
	{
		Edge current = pq.top();
		pq.pop();

		int u = current.to;
		int weight_u = current.weight;

		for (const Edge& neighbor : g[u])
		{
			int v = neighbor.to;
			int weight_v = neighbor.weight;

			// 갱신
			if (distance[start][u] + weight_v < distance[start][v])
			{
				distance[start][v] = distance[start][u] + weight_v;
				paths[start][v] = u;
				pq.push(Edge(v, distance[start][v]));
			}
		}
	}

	return paths;
}

stack<int> constructPath(const vector<vector<int>>& paths, int start, int dest)
{
	stack<int> pathstack;
	int currnet = dest;

	while (currnet != start)
	{
		pathstack.push(currnet);
		currnet = paths[start][currnet];
	}

	pathstack.push(start);
	return pathstack;
}


int main()
{
	vector<vector<Edge>> g = {
		{{1,2}, {2,4}},
		{{2,1}, {3,7}},
		{{3,3}},
		{}
	};

	int startnode = 0;
	int destnode = 3;

	vector<vector<int>> shortestPaths = Dijksra(g, startnode);

	stack<int> pathStack = constructPath(shortestPaths, startnode, destnode);
	cout << "정점 " << startnode << " 에서 정점 " << destnode << " 로 최단경로";
	
	while (!pathStack.empty())
	{
		cout << pathStack.top() << " ";
		pathStack.pop();
	}
	cout << endl;

	return 0;
}