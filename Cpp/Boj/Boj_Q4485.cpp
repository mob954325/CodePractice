#include <iostream>
#include <queue>

#define MAX_SIZE 125
#define MAX_VALUE 999999
using namespace std;

int graphSize;						// MapSize
int graph[MAX_SIZE][MAX_SIZE];		// Map
int weight[MAX_SIZE][MAX_SIZE];		// 방문 확인 배열 (MAX_VALUE : 방문 안함)
int dx[4] = { 1,-1, 0, 0 };			// direction X
int dy[4] = { 0, 0, 1, -1 };		// derection Y
queue<pair<int,int>> q;

/// <summary>
/// 그래프 보여주는 함수
/// </summary>
void show()
{
	cout << endl;

	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			cout << graph[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			cout << weight[y][x] << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// 배열 초기화 함수
/// </summary>
void Initialize()
{
	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			graph[y][x] = 0;
			weight[y][x] = MAX_VALUE;
		}
	}
}

/// <summary>
/// 해당 위치가 존재하는 위치인지 확인하는 함수 ( true : 존재함, false : 존재하지않음 )
/// </summary>
/// <param name="x">확인할 X 좌표값</param>
/// <param name="y">확인할 Y 좌표값</param>
/// <returns></returns>
bool IsValidPosition(int x, int y)
{
	return x > -1 && y > -1 && x < graphSize && y < graphSize;
}

/// <summary>
/// 경로 반환 함수
/// </summary>
void GetPath()
{
	weight[0][0] = graph[0][0];
	q.push(make_pair(0,0));	// 시작점 큐 삽입

	while (!q.empty())	// BFS 알고리즘
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (curX == graphSize - 1 && curY == graphSize - 1 && q.empty()) // 모든 경로를 다 돌았으면 반복문 탈출
			return; 

		for (int d = 0; d < 4; d++)		// 다음 4방향 위치 접근
		{
			int nextX = curX + dx[d];	// 다음 위치
			int nextY = curY + dy[d];	// 다음 위치

			if (IsValidPosition(nextX, nextY) /*&& weight[nextY][nextX] == MAX_VALUE*/)
			{
				// 최소값 찾기 (기존에 있던 weight값 vs 더한 값)
				int savedValue = weight[nextY][nextX];
				weight[nextY][nextX] = min(weight[nextY][nextX], graph[nextY][nextX] + weight[curY][curX]);
				
				// 최단 경로에 큐 삽입 ( 값이 변했으면 추가 )
				if(savedValue != weight[nextY][nextX]) 
					q.push(make_pair(nextX, nextY));
			}
		}
	}
}

int main()
{
    int index = 0; // 반복 횟수
	while (true)
	{
        index++;

		cin >> graphSize;
		int maxSize = graphSize;

		if (graphSize == 0)	// 반복문 종료
			break;

		Initialize();
		for (int y = 0; y < graphSize; y++)
		{
			for (int x = 0; x < graphSize; x++)
			{
				int input;
				cin >> input;
				graph[y][x] = input;
			}
		}
		GetPath();

		cout << "Problem " << index << ": " << weight[maxSize - 1][maxSize - 1] << "\n";
	}
}