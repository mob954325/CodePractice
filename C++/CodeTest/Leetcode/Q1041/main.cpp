#include <iostream>
#include <string>
#include <vector>

bool isRobotBounded(std::string instructions);

int main()
{
    std::string s = "GLGLGGLGL";
    std::cout << isRobotBounded(s);
}

bool isRobotBounded(std::string instructions)
{
    // 무한한 평면에 로봇이 (0, 0), 북쪽을 바라보고 있다.
    // 북 : y 방향
    // 남 : -y 방향
    // 동 : x 방향
    // 서 : -x 방향
    
    // 로봇은 3개의 지침을 받는다
    // G : 1유닛만큼 직진
    // L : 왼쪽으로 90도만큼 회전
    // R : 오른쪽으로 90도만큼 회전
    
    // 로봇은 지침을 순서에 따라서 영원히 반복한다.
    // 평면안에 있는원을 떠나지 않으면 true

    int x = 0;
    int y = 0;
    int i = 0; // 방향 인덱스 (0 == 방향 x)

    std::vector<std::vector<int>> d{ {0,1}, {1,0},{0,-1} ,{-1,0} };
    for (char& ins : instructions)
    {
        if (ins == 'R')
            i = (i + 1) % 4;
        else if (ins == 'L')
            i = (i + 3) % 4;
        else
            x += d[i][0], y += d[i][1];
    }

    return x == 0 && y == 0 || i > 0;
}