#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
    // ����
    // ���� ������ �����ϰ� (strictly) ������ �迭 arr�� �����Ѵ�.
    // ���� ������ arr���� ���� �� �Ǻ���ġ(Fibonacci) ������ ���̸� ��ȯ�ض� (������ 0)
    // subsequence�� ���ĵ� ������ ��ҵ��� �ٲ��� �ʰ� ������ ����� ���ڸ� ������ arr�� �ٸ� sequence�κ��� �Ļ��ȴ�.(���ž��� ���� ����) 
    // ���� ���� ����
    // -> �ش� ������ ��Ȯ�� �Ǻ���ġ ������ �����ϴ� ���� ������ �ƴ� �Ǻ���ġ �������� �迭�� ����
    // �̰� �� �Ҹ����� �𸣰ڴµ� �����Ǵ� �迭������ �Ǻ���ġ������ �迭�� ���ϴµ� �̿� ���� ������ �����ϹǷ� ���� �Ǻ���ġ�� ã�� �� �迭 ���� ���� ������ + 1�� ó���ؼ� ����Ҳ���

    // �ذ�
    // map�� �迭 �� �߰�
    // arr�� �Ǻ���ġ ���� �˻��ϱ�
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // ��-> �ε��� ��
        vector<vector<int>> dp(n, vector<int>(n, 2)); // �ּ� ���� 2

        int maxLength = 0;

        // �� ���� �ε��� ����
        for (int i = 0; i < n; i++)
        {
            index[arr[i]] = i; // ?
        }

        // DP ���
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                int num = arr[j] - arr[i]; // �Ǻ���ġ ���� : arr[k] = arr[i] + arr[j]
                if (index.find(num) != index.end() && index[num] < i)
                {
                    int k = index[num]; // num�� ��ġ�� �ε��� k
                    dp[i][j] = dp[k][i] + 1; // ���� �Ǻ���ġ ���� + 1
                    maxLength = max(maxLength, dp[i][j]); // ��
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