#include <iostream>
#include <math.h>

class Solution {
    // ����
    // 3�� ������ �ϴ� �������� ������ Ȯ��
    // �� ���� ������ true�ƴϸ� false

    // �ذ�
    // ���� ����� �������� ����.
public:
    bool checkPowersOfThree(int n) {

        int power = 0;
        while (n > 0)
        {
            if (n % 3 == 2) return false;
            n /= 3;
        }

        return true;
    }
};

int main()
{
    Solution sol = Solution();
    int n = 91;
    sol.checkPowersOfThree(n);
}