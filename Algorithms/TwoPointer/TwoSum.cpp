#include "TwoSum.h"

// 문제
// 정렬된 두 배열에서 두 숫자의 합이 target이 되는 쌍이 존재 하는지 확인하라
bool TwoSum(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;

	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (sum == target) return true; // target과 같은 수를 찾음
		else if (sum < target) left++;	// 합이 target보다 낮음 -> left 포인터 증가
		else right--;					// sum > traget, 합이 target보다 높음 -> right 포인터 감소
	}

	return false; // target과 같은 값이 없음
}