#include "MoveEvensToFront.h"

// ����
// �迭���� ¦���� ������ �̵���Ű��, �迭 ���� ������ �������Ѷ�.
vector<int> MoveEvensToFront(vector<int>& nums)
{
	int evenIndex = 0; // ���� �� ¦�� ��ġ

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] % 2 == 0) // ¦�����
		{
			swap(nums[i], nums[evenIndex]); // �ڸ���ȯ
			evenIndex++; // ���� �� ���� ��ġ�� �̵�
		}
	}

	return nums;
}