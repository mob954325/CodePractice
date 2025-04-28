#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // ���� 
    // ���� ���ǿ� ���� nums�迭�� ������(rearrange)�ϼ���
    // 1. pivot���� ���� ��� ��Ҵ� pivot���� ���� ��Һ��� ���� �����Ѵ�.
    // 2. pivot�� ���� ��� ��Ҵ� �ǹ����� ���ų� ���� ��� ���̿� �����Ѵ�.
    // 3. pivot���� �۰ų� ū ��ҵ��� �����ȴ�.
    // �����ĵ� nums �迭�� ��ȯ�ض�

    // �ذ�
    // ������ ���� ���� ������ �迭 ���� ����� ����
    // �����ϰ� �ٽ� ����Ʈ�� �ִ� �� ��迭�ϱ�
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        if (n == 1) return nums; // �ϳ� �ۿ� ����

        vector<int> ans(n, 0), M(n, 0), R(n, 0);

        int l = 0, m = 0, r = 0;
        for (int x : nums)
        {
            if (x < pivot) ans[l++] = x;
            else if (x > pivot) R[r++] = x;
            else M[m++] = x;
        }

        m = 0;
        r = 0;
        for (int i = l; i < ans.size(); i++)
        {
            if (M[m] != 0)
            {
                ans[i] = M[m++];
            }
            else if (R[r] != 0)
            {
                ans[i] = R[r++];
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> v = { 18,-13,-19,-11,5,-17,0,-18,-12,-6,-20,-8,-20,-4,8 };

    sol.pivotArray(v, -20);
}