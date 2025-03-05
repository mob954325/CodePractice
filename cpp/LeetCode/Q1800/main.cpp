class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // num 양의 정수가 있는 배열 제공
        // 오름차순으로 나열된 부분 배열중 가장 큰 합을 반환해라

        // 해결
        // 순서대로 확인하기
        // 현재가 이전보다 낮으면 해당 위치부터 다시 합 구하기
        // 저장된 합이 현재 합보다 낮으면 갱신

        if (nums.size() == 1) return nums[0];

        int sum = nums[0];
        int maxSum = sum;

        // 2번째 수부터 확인
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i]) sum = 0;

            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
        }

        return maxSum;
    }
};