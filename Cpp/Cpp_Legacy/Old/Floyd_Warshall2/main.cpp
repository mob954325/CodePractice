#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

int cityNum, roadNum, personNum, minRotationTime = INF; // 도시수, 도로수, 사람수, 최소 왕복시간
vector<vector<int>> Lake; // 지도
vector<vector<int>> dist; // 각 도시별 시간
vector<vector<int>> rotationTime; // 각 도시별 왕복 시간
int getCity[201]; // 친구들과 본인이 사는 도시받는 배열


void init(int n)
{
	// vector 메모리 확보
	Lake.assign(n + 1, vector<int>(n + 1, INF));
	dist.assign(n + 1, vector<int>(n + 1, INF));
	rotationTime.assign(n + 1, vector<int>(n + 1, 0));
}

void show(vector<vector<int>>& map)
{
	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void Floyd_Warshall()
{
	// dist 초기화
	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			if (i == j) dist[i][j] = 0;
			else if (Lake[i][j]) dist[i][j] = Lake[i][j];
			else dist[i][j] = INF;
		}
	}

	// 최단 시간 저장
	for (int k = 1; k <= cityNum; k++)
	{
		for (int i = 1; i <= cityNum; i++)
		{
			for (int j = 1; j <= cityNum; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main()
{
	cin >> cityNum >> roadNum;

	init(cityNum);

	for (int i = 1; i <= roadNum; i++)
	{
		int cityA, cityB, time;
		// 도시간의 시간 정보 입력
		cin >> cityA >> cityB >> time;

		Lake[cityA][cityB] = time;
	}


	Floyd_Warshall();


	// 왕복 시간 찾기

	cin >> personNum; // 인원수 입력

	for (int k = 1; k <= personNum; k++) // 0 < 
	{
		cin >> getCity[k];
	}

	for (int i = 1; i <= personNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			if (i == j) continue;

			rotationTime[getCity[i]][j] = dist[getCity[i]][j] + dist[j][getCity[i]];

			if (rotationTime[getCity[i]][j] < minRotationTime)
			{
				minRotationTime = rotationTime[getCity[i]][j];
			}
		}
	}

	show(rotationTime);

	// 출력
	// 출력 결과값 오름차순으로 정리하기
	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			if (rotationTime[i][j] == minRotationTime)
			{
				cout << j << " ";
			}
		}
			cout << "\n";
	}
}