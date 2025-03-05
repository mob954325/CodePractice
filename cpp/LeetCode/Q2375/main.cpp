#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void BackTracking(string &pattern, string &res, int &pointer, int &count)
    {
        if (pointer == pattern.length()) // ������ ���� �߰��ϱ�
        {
            res += to_string(count);
            return;
        }

        if (pattern[pointer] == 'I') // ����
        {
            res += to_string(count); // ���� �߰�
        }
        else if (pattern[pointer] == 'D') // ����
        {
            pointer++;
            count++;
            BackTracking(pattern, res, pointer, count);
            count--;

            res += to_string(count);
        }
    }

    string smallestNumber(string pattern) {
        // 0 �ε������� �����ϴ� ���̰� n�� parttern ���ڿ��� �ִ�.
        // ���̰� n + 1�� ���ڿ� num�� ���� ���ǿ� ���� ���������.
        // num�� 1�� 9�� �����ȴ�. �ִ� �ѹ��� ��� �Ǿ���.
        // pattern[i] == I�� num[i] < num[i + 1]�̴�.
        // patter[i] == D�� num[i] > num[i + 1]�̴�.
        // ���� ������� ���� ���� ���ڿ��� num�� ��ȯ�ض�. �� ������ �����ϴ� 

        // �ذ�       
        // �ٸ� ���ڰ� ���� �� ���� ����
        // �ٸ� ���ڰ� ������ ���� �ְ� �ٽ� dfs ã�� ����
        // I�� �ٷ� ���� �߰��ϰ�, D�� �ִ� �Ÿ��ų� �ٸ� ���ڰ� ���� ������ �����͸� �����ߴٰ� �ش� ��ġ���� ���� ����

        string res = "";
        int count = 1;
        int pointer = 0;

        for (;pointer <= pattern.length(); pointer++)
        {
            BackTracking(pattern, res, pointer, count);
            count = pointer + 2; // ���� ���� ����
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();
    string str = "I";
    sol.smallestNumber(str);
}