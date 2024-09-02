#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

int cityNum, roadNum, personNum, minRotationTime = INF; // ���ü�, ���μ�, �����, �ּ� �պ��ð�
vector<vector<int>> Lake; // ����
vector<vector<int>> dist; // �� ���ú� �ð�
vector<vector<int>> rotationTime; // �� ���ú� �պ� �ð�
int getCity[201]; // ģ����� ������ ��� ���ù޴� �迭


void init(int n)
{
	// vector �޸� Ȯ��
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
	// dist �ʱ�ȭ
	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			if (i == j) dist[i][j] = 0;
			else if (Lake[i][j]) dist[i][j] = Lake[i][j];
			else dist[i][j] = INF;
		}
	}

	// �ִ� �ð� ����
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
		// ���ð��� �ð� ���� �Է�
		cin >> cityA >> cityB >> time;

		Lake[cityA][cityB] = time;
	}


	Floyd_Warshall();


	// �պ� �ð� ã��

	cin >> personNum; // �ο��� �Է�

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

	// ���
	// ��� ����� ������������ �����ϱ�
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