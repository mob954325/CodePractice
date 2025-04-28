#include <iostream>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        // 세 개의 문자로만 구성되어있습니다 ( a, b, c)
        // 1부터 s.length - 1까지의 모든 i의 값은 s[i] != s[i + 1]이다 (문자열은 1-indexed).
        // 예로 "abc", "ac", "b" and "abcbabcbcb" 모두 happy stirngs이고 
        // "aa", "baa", "ababbc"는 happy string이 아닙니다.
        // 정수인 두 n 과 k를 받습니다.
        // 사전순으로 정렬된 길이가 n인 happy string 리스트를 고려합니다.
        // 위 리스트의 k번째 문자열을 반환하거나 k보다 happy strings의 길이 n이 낮으면 empty string을 반환하세요
        // -> 길이가 n인 happy string중 k번째 문자열을 반환해라 없으면 empty string을 반환해라

        // 해결
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
                // 문자열 추가 (같은 길이가 될 때까지)
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
            else // 문자열 길이가 n과 같으면 확인하기
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