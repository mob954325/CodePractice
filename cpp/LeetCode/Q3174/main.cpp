#include <iostream>
#include <string>

class Solution {
public:
    std::string clearDigits(std::string s) {
        // ����
        // �ش� �۾��� �ݺ��Ͽ� ��� ���ڸ� �����ϱ�
        // ���ʺ��� ù ���ڿ� ������ ���ڰ� �ƴ� ���ڸ� �����Ѵ�.
        // ��� ���ڸ� ������ string�� ��ȯ�ض�

        // �ذ�
        // ���ʺ��� Ȯ�� 
        // ���ڰ� �ִ� ���ڸ� �ش� ���ڿ��� ���� ����� ���ڸ� Ȯ�� �� ���ڿ� ���ڸ� '!'�� ǥ���ϱ�
        // �ݺ�

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] <= '9') // �ش� ���ڰ� ���ڴ�
            {
                // ���� ����� ���� ã��
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
