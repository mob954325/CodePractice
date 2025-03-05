#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        // ����
        // s���ڿ����� part�� �ִ� subString �����ϱ�

        // �ذ�
        // �� �ε������� substr�� Ȯ���ϱ�
        // part�� �����ϸ� �������� �ʱ�

        int pointer = 0;

        while (pointer < s.length())
        {
            char c = s[pointer];
            if (c == part[0]) // part�� ���� subString�� ã����
            {
                std::string check = "";
                for (int i = 0; i < part.length(); i++)
                {
                    if (pointer + i > s.length()) return s; // part üũ���� ��� s��ȯ -> ������ �� �ִ� subString�� ����
                    check += s[pointer + i];
                }

                if (check == part)
                {
                    s.erase(pointer, part.length());
                    pointer = 0; // �ٽ� ã��
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