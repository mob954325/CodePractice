#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        // 문제
        // s문자열에서 part가 있는 subString 제거하기

        // 해결
        // 매 인덱스마다 substr로 확인하기
        // part와 동일하면 저장하지 않기

        int pointer = 0;

        while (pointer < s.length())
        {
            char c = s[pointer];
            if (c == part[0]) // part와 같은 subString을 찾으면
            {
                std::string check = "";
                for (int i = 0; i < part.length(); i++)
                {
                    if (pointer + i > s.length()) return s; // part 체크보다 길면 s반환 -> 제거할 수 있는 subString이 없음
                    check += s[pointer + i];
                }

                if (check == part)
                {
                    s.erase(pointer, part.length());
                    pointer = 0; // 다시 찾기
                    continue;
                }
            }
            pointer++;
        }

        return s;
    }
};

int main()
{
    Solution sol = Solution();

    std::string s = "daabcbaabcbc";
    std::string part = "abc";

    sol.removeOccurrences(s, part);
}