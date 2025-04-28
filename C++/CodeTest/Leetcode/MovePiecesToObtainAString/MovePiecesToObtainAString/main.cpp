#include <iostream>

using namespace std;

bool canChange(string start, string target)
{
    // string은 L, R, _으로 표현한다.
    // _는 빈칸으로 표현하고 L 과 R이 이동할 수 있는 공간이다.
    // L은 왼쪽으로 R은 오른쪽으로 이동한다. (이동할 공간이 _일때만)
    // target 모양이 될 수 있으면 true 아니면 false

    // solution
    // 각 문자별로 target에서의 위치 확인
    // 갈 수 있는지 체크
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