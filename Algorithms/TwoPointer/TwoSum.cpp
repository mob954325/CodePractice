#include "TwoSum.h"

// ����
// ���ĵ� �� �迭���� �� ������ ���� target�� �Ǵ� ���� ���� �ϴ��� Ȯ���϶�
bool TwoSum(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;

	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (sum == target) return true; // target�� ���� ���� ã��
		else if (sum < target) left++;	// ���� target���� ���� -> left ������ ����
		else right--;					// sum > traget, ���� target���� ���� -> right ������ ����
	}

	return false; // target�� ���� ���� ����
}