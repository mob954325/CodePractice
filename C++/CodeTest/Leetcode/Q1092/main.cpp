#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 문제
    // str1 str2 제공
    // str1과 str2가 모두 포함된 서브시퀀스를 가진 가장 짧은 문자열을 반환해라 ( 만약 문자열이 여러개 있으면 그 중 하나 반환)
    // 문자열 s는 문자열 t에서 특정 문자들을 몇 개 지운 t문자열의 subString이다.(0도 가능)
    //
    // 해결
    // Longest Common Subsequence(LCS) of the two strings using dp
    //
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if (str1 == str2) return str1; // 같으면 하나 반환

        // Find the longest common subsequence using dynamic programming
        int str1Size = str1.length();
        int str2Size = str2.length();
        vector<vector<int>> dp(str1Size + 1, vector<int>(str2Size + 1, 0));

        // dp 테이블 채우기
        for (int i = 1; i <= str1Size; i++)
        {
            for (int j = 1; j <= str2Size; j++)
            {
                if (str1[i - 1] == str2[j - 1]) // 이전 값이 동일
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // 현재 = 이전 + 1
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 다르면 str1과 str2중 같은 문자 개수가 더 많은 것을 저장
                }
            }
        } // for end

        // Construct the shortest common supersequence
        // start from the bottom right of the dp table
        int i = str1Size, j = str2Size;
        string result = "";

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1]) // 문자가 같으면 추가
            {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // y값이 더 높은 값으면 str1 문자를 가져간다.
                result.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                // 그렇지 않으면, str2 문자 가져가기
                result.push_back(str2[j - 1]);
                j--;
            }
        } // while end

        // 나머지 문자 추가
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