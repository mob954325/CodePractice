#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

//struct Graph {
//	int NumVertices; // 정점개수
//	vector<vector<int>> adMatrix; // 2차원 행렬
//
//	Graph(int vectices) : NumVertices(vectices), adMatrix(vectices, vector<int>(vectices, 0)) {}
//
//	void addEdge(int start, int end)
//	{
//		adMatrix[start][end] = 1;
//		adMatrix[end][start] = 1;
//	}
//
//	void printGraph()
//	{
//		cout << "인접행렬 표현(Adjacency MAtrix)" << "\n";
//
//		for (int i = 0; i < NumVertices; i++)
//		{
//			for (int j = 0; j < NumVertices; j++)
//			{
//				cout << adMatrix[i][j] << " "; 
//			}
//			cout << "\n";
//		}
//	}
//};

//struct Graph { // List
//	int NumVertices; // 정점개수
//	vector<list<int>> adList; // 2차원 행렬
//
//	Graph(int vectices) : NumVertices(vectices), adList(vectices) {}
//
//	void addEdge(int start, int end)
//	{
//		adList[start].push_back(end);
//		adList[end].push_back(start);
//	}
//
//	void DFShelp(int vertex, vector<bool>& visited)
//	{
//		visited[vertex] = true; // 정점 저장
//
//		cout << vertex << " ";
//
//		for (auto& nei : adList[vertex])
//		{
//			if (!visited[nei])
//				DFShelp(nei, visited);
//		}
//	}
//
//	void DFS_Start(int startVertex) // 재귀함수
//	{
//		vector<bool> visited(NumVertices, false);
//
//		cout << "DFS 시작 " << startVertex << ": ";
//
//		DFShelp(startVertex, visited);
//		cout << "\n";
//	}
//
//	void printGraph()
//	{
//		cout << "인접행렬 표현(Adjacency List)" << "\n";
//
//		for (int i = 0; i < NumVertices; i++)
//		{
//			cout << i << "-> ";
//			for (auto& nei : adList[i])
//			{
//				cout << nei << " ";
//			}
//			cout << "\n";
//		}
//	}
//	
//	void DFS(int vertex) // stack
//	{
//		vector<bool> visited(NumVertices, false);
//		stack<int> stack;
//
//		cout << "DFS 시작 : " << vertex << " : ";
//
//		stack.push(vertex);
//
//		while (!stack.empty())
//		{
//			int currentvertex = stack.top();
//
//			stack.pop();
//
//			if (!visited[currentvertex])
//			{
//				visited[currentvertex] = true;
//				cout << currentvertex << " ";
//
//				for (auto& nei : adList[currentvertex])
//				{
//					if (!visited[nei])
//					{
//						stack.push(nei);
//					}
//				}
//			}
//		}
//	}
//
//	void BFS(int vertex)
//	{
//		vector<bool> visited(NumVertices, false);
//		queue<int> queue;
//
//		cout << "BFS 시작 " << vertex << " : ";
//
//		visited[vertex] = true;
//		queue.push(vertex);
//
//		while (!queue.empty())
//		{
//			int currentvertex = queue.front();
//			queue.pop();
//
//			cout << currentvertex << " ";
//
//			for (auto& nei : adList[currentvertex])
//			{
//				if (!visited[nei])
//				{
//					visited[nei] = true;
//					queue.push(nei);
//				}
//			}
//		}
//		cout << "\n";
//	}
//
//
//};

struct Edge
{
	int to;
	int weight;

	Edge(int t, int w) : to(t), weight(w) {}
};

struct Compare
{
	bool operator() (const Edge& e1, const Edge& e2)
	{
		return e1.weight > e2.weight;
	}
}; 

int prim(vector<vector<Edge>>& g)
{
	int VNum = g.size(); // 정점 수

	vector<int> minWeight(VNum, INT16_MAX);
	vector<int> parent(VNum, -1);
	vector<bool> inMST(VNum, false);

	int startVertex = 0; // 시작점

	minWeight[startVertex] = 0;

	for (int i = 0; i < VNum - 1; i++)
	{
		int minVertex = -1;
		for (int v = 0; v < VNum; v++)
		{
			if (!inMST[v] && minVertex == -1 || minWeight[v] < minWeight[minVertex])
			{
				minVertex = v;
			}
		}

		inMST[minVertex] = true;

		for (const Edge& e : g[minVertex])
		{
			int toVertex = e.to;
			int weight = e.weight;

			if (!inMST[toVertex] && weight < minWeight[toVertex])
			{
				minWeight[toVertex] = weight;
				parent[toVertex] = minVertex;
			}
		}

	}

	int total = 0;

	for (int v = 0; v < VNum; v++)
	{

		total += minWeight[v];
	}

	return total;
}




int main()
{
	//Graph g(10);
	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(1, 3);
	//g.addEdge(1, 4);
	//g.addEdge(1, 5);
	//g.addEdge(5, 6);
	//g.addEdge(5, 4);
	//g.addEdge(6, 4);
	//g.addEdge(2, 3);
	//g.addEdge(7, 3);
	////g.printGraph();
	///// <summary>
	///// X 0 1 2 3
	///// 0 0 1 0 1
	///// 1 1 0 1 0
	///// 2 0 1 0 0
	///// 3 1 0 0 0
	///// </summary>
	//
	//g.printGraph();
	//g.DFS_Start(0);
	//g.DFS(0);
	//g.BFS(0);

	vector<vector<Edge>> graph = { // 각 index별 {연결 노드, 가중치}
		{{1,2}, {2,1}, {3,3}},
		{{0,2}, {2,2}, {4,1}},
		{{0,1}, {1,2}, {4,4}},
		{{0,3}, {4,5}},
		{{1,1}, {2,4}, {3,5}},
	};

	int MSTWeight = prim(graph);

	cout << "최소신장 트리 가중치 합 : " << MSTWeight << "\n";
	return 0;
}