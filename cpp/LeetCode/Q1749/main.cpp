#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    // 문제 
    // 정수 배열 제공
    // nums의 subarray 절대값의 최대 합을 반환해라

    // 해결 Kadane's Algorithm ...? -> dynamic programing의 일종
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxm_sum = INT_MAX, max_result = 0;
        int size = nums.size();

        int minm_sum = INT_MAX, min_result = 0;

        for (int i = 0; i < size; i++)
        {
            // 최대
            max_result += nums[i];
            maxm_sum = max(max_result, maxm_sum);

            if (max_result < 0) max_result = 0;

            // 최소
            min_result += nums[i];
            minm_sum = min(min_result, minm_sum);

            if (min_result > 0) min_result = 0;
        }


        return max(abs(min_result), abs(max_result));
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> v = { 2,-5,1,-4,3,-2 };
    sol.maxAbsoluteSum(v);
}