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
    // ������ ��鿡 �κ��� (0, 0), ������ �ٶ󺸰� �ִ�.
    // �� : y ����
    // �� : -y ����
    // �� : x ����
    // �� : -x ����
    
    // �κ��� 3���� ��ħ�� �޴´�
    // G : 1���ָ�ŭ ����
    // L : �������� 90����ŭ ȸ��
    // R : ���������� 90����ŭ ȸ��
    
    // �κ��� ��ħ�� ������ ���� ������ �ݺ��Ѵ�.
    // ���ȿ� �ִ¿��� ������ ������ true

    int x = 0;
    int y = 0;
    int i = 0; // ���� �ε��� (0 == ���� x)

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