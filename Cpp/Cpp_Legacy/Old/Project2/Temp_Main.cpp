#include <iostream>
#include <Queue>
#define MAX_SIZE 10000

using namespace std;

int graphSize;
int graph[MAX_SIZE][MAX_SIZE];
int minWeight = INT_MAX;

queue<int> q;

void Solution()
{
	int startVertex = graph[0][0];

	q.push(startVertex);

	while (q.empty())
	{
		int currnetVertex = q.front(); // 현재 큐의 첫번째 값
		q.pop();
		
		

	}
}

int main()
{
	cin >> graphSize;

	int input = 0;
	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			cin >> graphSize;
			graph[y][x] = graphSize;
		}
	}
}