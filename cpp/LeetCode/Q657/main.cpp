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
    // �κ��� 0,0�� �������� 2������ ���� �ִ�.
	// ������ �������� ������ �������� ����� �� �κ��� 0,0�� �ִ��� �Ǵ��Ѵ�.
	// ���ڿ����� ������ �������� �ε��� ������� �����Ѵ�.
	// R : ������
	// L : ����
	// U : ��
	// D : �Ʒ�
	// ��� �������� ����ǰ� origin��ġ�� ���ƿ��� true �ƴϸ� false
	// �κ��� �ٶ󺸴� ������ ������� �ʴ´�. (���������� ������)

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
