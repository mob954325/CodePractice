#include <iostream>
#include <string>

bool judgeCircle(std::string moves);

int main()
{
	std::string s = "LL";
	std::cout << judgeCircle(s);
}

bool judgeCircle(std::string moves)
{
    // 로봇은 0,0을 시작으로 2차원판 위에 있다.
	// 움직임 시퀀스를 받으면 움직임이 종료된 후 로봇이 0,0에 있는지 판단한다.
	// 문자열에는 움직임 시퀀스를 인덱스 순서대로 제공한다.
	// R : 오른쪽
	// L : 왼쪽
	// U : 위
	// D : 아래
	// 모든 움직임이 종료되고 origin위치로 돌아오면 true 아니면 false
	// 로봇이 바라보는 방향은 고려하지 않는다. (직관적으로 움직임)

	int size = moves.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < size; i++)
	{
		if (moves[i] == 'R') x++;
		else if (moves[i] == 'L') x--;
		else if (moves[i] == 'U') y++;
		else if (moves[i] == 'D') y--;
	}

	return x == 0 && y == 0;
}
