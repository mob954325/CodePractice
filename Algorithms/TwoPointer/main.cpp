#include "TwoSum.h"
#include "LengthOfLongestSubstring.h"
#include "MoveEvensToFront.h"

int main()
{
	// 1. 정렬된 두 배열에서 두 숫자의 합이 target이 되는 쌍이 존재 하는지 확인하라
	vector<int> nums = { 1,2,3,5,7,10 };
	int target = 9; // 2 + 7 = 9
	cout << (TwoSum(nums, target) ? "True" : "False") << "\n"; // true

	// 2. 문자열 s에서 중복이 없는 가장 긴 부분 문자열의 길이를 구하라.
	string s = "abcabcbb"; // abc
	cout << "maxLength : " << LengthOfLongestSubstring(s) << "\n"; // 3

	// 3. 배열에서 짝수만 앞으로 이동시키되, 짝수 값의 순서는 유지시켜라.(홀수는 관계 없음)
	nums = { 3, 1, 2, 4, 7, 6 };
	MoveEvensToFront(nums); // 2, 4, 6, 1, 3, 7
	for (int num : nums)
	{
		cout << num << " ";
	}

	return 0;
}