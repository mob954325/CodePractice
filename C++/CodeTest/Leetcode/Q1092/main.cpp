#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // ����
    // str1 str2 ����
    // str1�� str2�� ��� ���Ե� ����������� ���� ���� ª�� ���ڿ��� ��ȯ�ض� ( ���� ���ڿ��� ������ ������ �� �� �ϳ� ��ȯ)
    // ���ڿ� s�� ���ڿ� t���� Ư�� ���ڵ��� �� �� ���� t���ڿ��� subString�̴�.(0�� ����)
    //
    // �ذ�
    // Longest Common Subsequence(LCS) of the two strings using dp
    //
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if (str1 == str2) return str1; // ������ �ϳ� ��ȯ

        // Find the longest common subsequence using dynamic programming
        int str1Size = str1.length();
        int str2Size = str2.length();
        vector<vector<int>> dp(str1Size + 1, vector<int>(str2Size + 1, 0));

        // dp ���̺� ä���
        for (int i = 1; i <= str1Size; i++)
        {
            for (int j = 1; j <= str2Size; j++)
            {
                if (str1[i - 1] == str2[j - 1]) // ���� ���� ����
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // ���� = ���� + 1
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // �ٸ��� str1�� str2�� ���� ���� ������ �� ���� ���� ����
                }
            }
        } // for end

        // Construct the shortest common supersequence
        // start from the bottom right of the dp table
        int i = str1Size, j = str2Size;
        string result = "";

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1]) // ���ڰ� ������ �߰�
            {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // y���� �� ���� ������ str1 ���ڸ� ��������.
                result.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                // �׷��� ������, str2 ���� ��������
                result.push_back(str2[j - 1]);
                j--;
            }
        } // while end

        // ������ ���� �߰�
        while (i > 0)
        {
            result.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            result.push_back(str2[j - 1]);
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution sol = Solution();

    string str1 = "abac";
    string str2 = "cab";

    sol.shortestCommonSupersequence(str1, str2);
}