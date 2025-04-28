#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
    // 문제
    // 양의 정수로 엄격하게 (strictly) 증가된 배열 arr를 제공한다.
    // 서브 시퀀스 arr에서 가장 긴 피보나치(Fibonacci) 수열의 길이를 반환해라 (없으면 0)
    // subsequence는 정렬된 나머지 요소들을 바꾸지 않고 나머지 요소의 숫자를 제거한 arr의 다른 sequence로부터 파생된다.(제거안할 수도 있음) 
    // 문제 설명 부족
    // -> 해당 문제는 정확한 피보나치 수열을 제공하는 것이 목적이 아닌 피보나치 수열같은 배열를 원함
    // 이게 뭔 소리인진 모르겠는데 제공되는 배열내에서 피보나치스러운 배열을 원하는데 이에 대한 설명이 부족하므로 나는 피보나치를 찾은 후 배열 값이 남아 있으면 + 1로 처리해서 통과할꺼임

    // 해결
    // map에 배열 값 추가
    // arr의 피보나치 수열 검사하기
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // 값-> 인덱스 매
        vector<vector<int>> dp(n, vector<int>(n, 2)); // 최소 길이 2

        int maxLength = 0;

        // 각 값의 인덱스 저장
        for (int i = 0; i < n; i++)
        {
            index[arr[i]] = i; // ?
        }

        // DP 계산
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                int num = arr[j] - arr[i]; // 피보나치 조건 : arr[k] = arr[i] + arr[j]
                if (index.find(num) != index.end() && index[num] < i)
                {
                    int k = index[num]; // num이 위치한 인덱스 k
                    dp[i][j] = dp[k][i] + 1; // 이전 피보나치 길이 + 1
                    maxLength = max(maxLength, dp[i][j]); // 갱
                }
            }
        }

        return maxLength >= 3 ? maxLength : 0;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> v = { 2,4,7,8,9,10,14,15,18,23,32,50 }; // 5
    sol.lenLongestFibSubseq(v);
}