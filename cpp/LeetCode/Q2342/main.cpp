#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSum(std::vector<int>& nums) {
        // ����
        // �迭�� ��� �������� ��� nums�� ����
        // Ư�� �ε��� i j���� (i != j �� ��) �ε�����° ���ڸ� ���� ���� ���� ���� �� ���� ���ڵ� �� ���� ���� ���� ��ȯ�ض�

        // �ذ�
        // O(n^2)
        // �� ���ڸ� ���� ���� ���� ���� map���� ���� �� ���� ������ ���� ���� ���� ������ ��ȯ
        // map�� �ݺ���� Ȯ���ؾ��ؼ� ��ȿ�����̹Ƿ� ������ ��� �����͸� �־ �ε��� Ȯ��

        int size = nums.size();

        std::vector<int> v; // sum �����̳�
        int ans = -1;
        std::vector<std::pair<int, int>> p; // (sum, index���� ����)

        for (int i = 0; i < size; i++)
        {
            int curr = 0, sum = 0;
            curr = nums[i];
            while (curr != 0)
            {
                sum += curr % 10;
                curr = curr / 10;
            }

            v.push_back(sum);
        }

        for (int i = 0; i < size; i++)
        {
            p.push_back(std::make_pair(v[i], nums[i]));
        }

        sort(p.begin(), p.end()); // ����

        for (int i = 0; i < size - 1; i++)
        {
            if (p[i].first == p[i + 1].first) // ���� ���̸� 
            {
                ans = std::max(ans, p[i].second + p[i + 1].second);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol = Solution();

    std::vector<int> v = { 4,6,10,6 };
    std::cout << sol.maximumSum(v);
}