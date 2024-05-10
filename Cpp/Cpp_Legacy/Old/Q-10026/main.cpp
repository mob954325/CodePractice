// 적록색약 10026
// 빨초

//5
//RRRBB
//GGBBB
//BBBRR
//BBRRR
//RRRRR

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<char>> graph;
vector<bool> visited;
queue<char> q;

int nextX[4] = { 1,-1,0,0 };
int nextY[4] = { 0,0,1,-1 };

int gSize, cnt = 0;

void Init(int s)
{    // 초기화
	graph.assign(s, vector<char>(s, 0));
	visited.assign(s * s, false);
}

void show()
{
	for (int y = 0; y < gSize; y++)
	{
		for (int x = 0; x < gSize; x++)
		{
			cout << graph[y][x];
		}
		cout << endl;
	}
}

void BFS(int startX, int startY)
{
	cnt++;
	q.push(graph[startY][startX]);

	graph[startX][startY] = 'X';//

	visited[startY * gSize + startX] = true; // 시작점 방문

	// 좌표값
	int xIndex = startX;
	int yIndex = startY;

	// 모든 그래프 정좀 순회
	while (!q.empty())
	{
		char currentVertex = q.front();
	
		q.pop();
		// 다음 정점 확인
		for (int i = 0; i < 4; i++)
		{
			int nextXIndex = startX + nextX[i];
			int nextYIndex = startY + nextY[i];
	
			if (nextXIndex < 0 || nextXIndex >= gSize || nextYIndex < 0 || nextYIndex >= gSize)
				continue;
	
			char nextVertex = graph[nextYIndex][nextXIndex];
			graph[nextYIndex][nextXIndex] = 'X';//
	
			if (nextVertex == currentVertex && !visited[nextYIndex * gSize + nextXIndex])
			{
				visited[nextYIndex * gSize + nextXIndex] = true;
	
				startX = nextXIndex;
				startY = nextYIndex;
	
				q.push(graph[nextYIndex][nextYIndex]);
			}
		}
	}

		show();//
		cout << endl;//
} // end of BFS

int main()
{
	cin >> gSize;

	Init(gSize);

	char input;

	for (int y = 0; y < gSize; y++)
	{
		for (int x = 0; x < gSize; x++)
		{
			cin >> input;
			graph[y][x] = input;
		}
	}

	cout << endl;


	for (int y = 0; y < gSize; y++)
	{
		for (int x = 0; x < gSize; x++)
		{
			if(!visited[y * gSize + x])
				BFS(y, x);
		}
	}

	cout << cnt << endl;
}