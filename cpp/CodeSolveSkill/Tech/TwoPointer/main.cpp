#include "TwoSum.h"
#include "LengthOfLongestSubstring.h"
#include "MoveEvensToFront.h"

int main()
{
	// 1. ���ĵ� �� �迭���� �� ������ ���� target�� �Ǵ� ���� ���� �ϴ��� Ȯ���϶�
	vector<int> nums = { 1,2,3,5,7,10 };
	int target = 9; // 2 + 7 = 9
	cout << (TwoSum(nums, target) ? "True" : "False") << "\n"; // true

	// 2. ���ڿ� s���� �ߺ��� ���� ���� �� �κ� ���ڿ��� ���̸� ���϶�.
	string s = "abcabcbb"; // abc
	cout << "maxLength : " << LengthOfLongestSubstring(s) << "\n"; // 3

	// 3. �迭���� ¦���� ������ �̵���Ű��, ¦�� ���� ������ �������Ѷ�.(Ȧ���� ���� ����)
	nums = { 3, 1, 2, 4, 7, 6 };
	MoveEvensToFront(nums); // 2, 4, 6, 1, 3, 7
	for (int num : nums)
	{
		cout << num << " ";
	}

	return 0;
}