class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // num ���� ������ �ִ� �迭 ����
        // ������������ ������ �κ� �迭�� ���� ū ���� ��ȯ�ض�

        // �ذ�
        // ������� Ȯ���ϱ�
        // ���簡 �������� ������ �ش� ��ġ���� �ٽ� �� ���ϱ�
        // ����� ���� ���� �պ��� ������ ����

        if (nums.size() == 1) return nums[0];

        int sum = nums[0];
        int maxSum = sum;

        // 2��° ������ Ȯ��
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i]) sum = 0;

            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
        }

        return maxSum;
    }
};