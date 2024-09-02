#include <iostream>
#include <vector>
#include <queue>

#define MAX 1501

using namespace std;

int mapX, mapY;

char Lake[MAX][MAX]; // 호수
bool visited[MAX * MAX]; // 방문
queue<pair<int, int>> water_q, water_nq, swan_q, swan_nq; // 물큐, 다음 물큐, 백조큐, 다음 백조큐
pair<int, int> swan_pos; // 백조 위치

bool IsFind = false; // 백조가 서로 만났는가

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Swan_BFS()
{
    while (!swan_q.empty() && !IsFind)
    {
        int curX = swan_q.front().first;
        int curY = swan_q.front().second;
        swan_q.pop();

        for (int next = 0; next < 4; next++)
        {
            int nextX = curX + dx[next];
            int nextY = curY + dy[next];
            if (nextX < 0 || nextX >= mapX || nextY < 0 || nextY >= mapY)
                continue;

            if (!visited[nextY * mapX + nextX])
            {
                if (Lake[nextY][nextX] == 'X') // 빙판이면
                {
                    swan_nq.push(make_pair(nextX, nextY));
                    visited[nextY * mapX + nextX] = true;
                }
                else if (Lake[nextY][nextX] == '.') // 물이면
                {
                    swan_q.push(make_pair(nextX, nextY));
                    visited[nextY * mapX + nextX] = true;
                }
                else if (Lake[nextY][nextX] == 'L') // 백조이면
                {
                    visited[nextY * mapX + nextX] = true;
                    IsFind = true;
                    break;
                }
            }
        }
    }
}

void Water_BFS()
{
    while (!water_q.empty())
    {
        int curX = water_q.front().first;
        int curY = water_q.front().second;

        water_q.pop();

        for (int next = 0; next < 4; next++)
        {
            int nextX = curX + dx[next];
            int nextY = curY + dy[next];
            if (nextX < 0 || nextX >= mapX || nextY < 0 || nextY >= mapY)
                continue;

            if (Lake[nextY][nextX] == 'X')
            {
                Lake[nextY][nextX] = '.';
                water_nq.push(make_pair(nextX, nextY));
            }
        }
    }
}

///// <summary>
///// 맵 보여주는 함수
///// </summary>
///// <param name="day"></param>
//void show(int day)
//{
//    if (day > 10)
//        return;
//
//    for (int y = 0; y < mapY; y++)
//    {
//        for (int x = 0; x < mapX; x++)
//        {
//            cout << Lake[y][x] << " ";
//        }
//
//        cout << endl;
//    }
//    cout << endl;
//}

void Check()
{
    int day = 0;

    int swan_X = swan_pos.first;
    int swan_Y = swan_pos.second;

    swan_q.push(make_pair(swan_X, swan_Y));

    visited[swan_Y * mapX + swan_X] = true;

    while (!IsFind)
    {
        Swan_BFS();
        if (!IsFind)
        {
            Water_BFS();
            swan_q = swan_nq;
            water_q = water_nq;

            while(!swan_nq.empty()) swan_nq.pop();
            while(!water_nq.empty()) water_nq.pop();

            day++;
        }
        //show(day);
    }
    cout << day;
}

int main()
{
    cin >> mapY >> mapX;
    for (int y = 0; y < mapY; y++)
    {
        for (int x = 0; x < mapX; x++)
        {
            cin >> Lake[y][x];

            if (Lake[y][x] == 'L') // 백조이면
            {
                swan_pos = make_pair(x, y); // 위치 저장
            }
            if (Lake[y][x] == 'X') // 얼음이면
            {
                water_q.push(make_pair(x, y)); // 위치 저장
            }
        }
    }

    Check();
}