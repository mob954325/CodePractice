class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // strictly increasing, strictly decreasing �� subarray�� ���� ū ���̸� ��ȯ�ض�

        // �ذ�
        // O(n)
        // �迭�� ���鼭 increase decrest ���� Ƚ���� �� �ݺ����� Ȯ�� �� ���� ū ���� ��ȯ

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