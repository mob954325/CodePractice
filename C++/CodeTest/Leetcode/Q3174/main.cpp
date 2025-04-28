#include <iostream>
#include <string>

class Solution {
public:
    std::string clearDigits(std::string s) {
        // 문제
        // 해당 작업을 반복하여 모든 숫자를 제거하기
        // 왼쪽부터 첫 숫자와 근접한 숫자가 아닌 문자를 제거한다.
        // 모든 숫자를 제거한 string을 반환해라

        // 해결
        // 왼쪽부터 확인 
        // 숫자가 있는 문자면 해당 문자에서 가장 가까운 문자를 확인 후 숫자와 문자를 '!'로 표시하기
        // 반복

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] <= '9') // 해당 문자가 숫자다
            {
                // 가장 가까운 문자 찾기
                int nearestChar = i - 1;
                while (s[nearestChar] == '!')
                {
                    nearestChar--;
                }

                s[i] = '!';
                s[nearestChar] = '!';
            }
        }

        std::string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '!') res += s[i];
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();

    std::string s = "cb34";

    std::cout << sol.clearDigits(s);
}
