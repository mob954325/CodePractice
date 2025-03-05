#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(std::string s);

int main()
{
    std::string s = "MCMXCIV";

    std::cout << romanToInt(s);
}

int romanToInt(std::string s)
{
    // �θ��ڸ� int�� ���ڷ� ��ȯ�ϱ�
    int res = 0;
    int size = s.size();
    std::unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for (int i = 0; i < size - 1; i++)
    {
        if (roman[s[i]] < roman[s[i + 1]]) // ����
        {
            res -= roman[s[i]];
        }
        else
        {
            res += roman[s[i]];
        }
    }

    return res;
}