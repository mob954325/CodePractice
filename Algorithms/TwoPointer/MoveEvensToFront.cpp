#include "MoveEvensToFront.h"

// 문제
// 배열에서 짝수만 앞으로 이동시키되, 배열 값의 순서는 유지시켜라.
vector<int> MoveEvensToFront(vector<int>& nums)
{
	int evenIndex = 0; // 저장 할 짝수 위치

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] % 2 == 0) // 짝수라면
		{
			swap(nums[i], nums[evenIndex]); // 자리교환
			evenIndex++; // 저장 할 다음 위치로 이동
		}
	}

	return nums;
}