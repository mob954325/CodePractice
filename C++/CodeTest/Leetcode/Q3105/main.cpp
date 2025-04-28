class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // strictly increasing, strictly decreasing 인 subarray의 가장 큰 길이를 반환해라

        // 해결
        // O(n)
        // 배열을 돌면서 increase decrest 연속 횟수를 매 반복마다 확인 후 가장 큰 수를 반환

        int maxDecreaseStreak = 1;
        int maxIncreaseStreak = 1;
        int increaseStreak = 1;
        int decreaseStreak = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            int curr = nums[i];
            int next = nums[i + 1];

            curr < next ? increaseStreak++ : increaseStreak = 1;
            curr > next ? decreaseStreak++ : decreaseStreak = 1;

            if (decreaseStreak > maxDecreaseStreak) maxDecreaseStreak = decreaseStreak;
            if (increaseStreak > maxIncreaseStreak) maxIncreaseStreak = increaseStreak;
        }

        return max(maxIncreaseStreak, maxDecreaseStreak);
    }
};