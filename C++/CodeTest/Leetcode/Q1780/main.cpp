#include <iostream>
#include <math.h>

class Solution {
    // 문제
    // 3을 밑으로 하는 제곱수의 합인지 확인
    // 위 값이 맞으면 true아니면 false

    // 해결
    // 가장 가까운 제곱값을 뺀다.
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