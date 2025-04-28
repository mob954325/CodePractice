#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 문제 
    // 밑의 조건에 따라 nums배열을 재정렬(rearrange)하세요
    // 1. pivot보다 낮은 모든 요소는 pivot보다 높은 요소보다 먼저 등장한다.
    // 2. pivot과 같은 모든 요소는 피벗보다 낮거나 높은 요소 사이에 등장한다.
    // 3. pivot보다 작거나 큰 요소들은 유지된다.
    // 재정렬된 nums 배열을 반환해라

    // 해결
    // 낮은값 높은 값을 저장할 배열 따로 만들고 저장
    // 정렬하고 다시 리스트에 있는 값 재배열하기
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        if (n == 1) return nums; // 하나 밖에 없음

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