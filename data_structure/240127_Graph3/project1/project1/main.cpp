#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, removeNum, startVertex;
int leafCount = 0;

vector<int> graph[51];
vector<bool> visited(51, false);
vector<int> check(51, 0);

void DFS()
{
	stack<int> s;

	s.push(startVertex);
	visited[startVertex] = true;

	while(!s.empty())
	{
		int topVertex = s.top();
		s.pop();

		if (topVertex == removeNum)
			continue;

		if (check[topVertex] == 0)
		{
			leafCount++;
		}


		for (int i = 0; i < graph[topVertex].size(); i++)
		{
			int nextVertex = graph[topVertex][i];
			if (!visited[nextVertex])
			{
				visited[nextVertex] = true;
				s.push(nextVertex);
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;


		if (parent == -1)
		{
			startVertex = i;
			continue;
		}

		check[parent]++;

		graph[i].push_back(parent);
		graph[parent].push_back(i);
	}

	cin >> removeNum;

	for (int i = 0; i < graph[removeNum].size(); i++)
	{
		int removeEdgeNum = graph[removeNum][i];
		check[removeEdgeNum]--;
	}

	DFS();

	cout << leafCount;
}