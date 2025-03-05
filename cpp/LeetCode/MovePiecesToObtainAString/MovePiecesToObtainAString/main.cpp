#include <iostream>

using namespace std;

bool canChange(string start, string target)
{
    // string�� L, R, _���� ǥ���Ѵ�.
    // _�� ��ĭ���� ǥ���ϰ� L �� R�� �̵��� �� �ִ� �����̴�.
    // L�� �������� R�� ���������� �̵��Ѵ�. (�̵��� ������ _�϶���)
    // target ����� �� �� ������ true �ƴϸ� false

    // solution
    // �� ���ں��� target������ ��ġ Ȯ��
    // �� �� �ִ��� üũ
    int halfLength = start.length() / 2;

    for (int i = 0; i < start.length(); i++)
    {
        if (start[i] == '_' && start[i + 1] != '_')
        {
            char temp = start[i];
            if (start[i + 1] == 'L')
            {
                if (start[i] == 'R') return false;

                start[i] = start[i + 1];
                start[i + 1] = '_';
            }
        }
    }

    for (int i = start.length() - 1; i > 1; i--)
    {
        if (start[i] == '_' && start[i - 1] != '_')
        {
            char temp = start[i - 1];
            if (start[i - 1] == 'R')
            {
                if (start[i] == 'L') return false;

                start[i - 1] = '_';
                start[i] = temp;
            }
        }
    }

    return start == target;
}

int main()
{
    string str1 = "_L__R__R_";
    string str2 = "L______RR";

    cout << canChange(str1, str2);
}