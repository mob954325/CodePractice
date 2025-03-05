#include <iostream>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        // �� ���� ���ڷθ� �����Ǿ��ֽ��ϴ� ( a, b, c)
        // 1���� s.length - 1������ ��� i�� ���� s[i] != s[i + 1]�̴� (���ڿ��� 1-indexed).
        // ���� "abc", "ac", "b" and "abcbabcbcb" ��� happy stirngs�̰� 
        // "aa", "baa", "ababbc"�� happy string�� �ƴմϴ�.
        // ������ �� n �� k�� �޽��ϴ�.
        // ���������� ���ĵ� ���̰� n�� happy string ����Ʈ�� ����մϴ�.
        // �� ����Ʈ�� k��° ���ڿ��� ��ȯ�ϰų� k���� happy strings�� ���� n�� ������ empty string�� ��ȯ�ϼ���
        // -> ���̰� n�� happy string�� k��° ���ڿ��� ��ȯ�ض� ������ empty string�� ��ȯ�ض�

        // �ذ�
        // dfs
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");

        int count = 1;
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            if (curr.length() < n)
            {
                // ���ڿ� �߰� (���� ���̰� �� ������)
                string str1 = "", str2 = "";
                if (curr[curr.length() - 1] == 'a')
                {
                    str1 += curr + 'b';
                    str2 += curr + 'c';
                }
                else if (curr[curr.length() - 1] == 'b')
                {
                    str1 += curr + 'a';
                    str2 += curr + 'c';
                }
                else if (curr[curr.length() - 1] == 'c')
                {
                    str1 += curr + 'a';
                    str2 += curr + 'b';
                }

                q.push(str1);
                q.push(str2);
            }
            else // ���ڿ� ���̰� n�� ������ Ȯ���ϱ�
            {
                if (count == k) return curr;

                count++;
            }

        } // while end

        return "";
    }
};

int main()
{
    Solution sol = Solution();

    int n = 3;
    int k = 9;
    sol.getHappyString(n, k);
}