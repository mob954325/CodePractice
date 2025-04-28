#include <vector>

bool isArraySpecial(std::vector<int>& nums) {
    // Ư�� ������ ���� �迭���� Ȯ��
    // ������� �� ���� Ȧ¦���� �̷��� ������ Special �迭�̶���Ѵ�.
    // �ش� ���ǿ� �����ϸ� true �ƴϸ� false ��ȯ
    // ����> ��� �迭 ��Ұ� �ش� ���ǿ� �����ؾ� true

    if (nums.size() == 1) return true;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] % 2 == nums[i + 1] % 2) return false;
    }

    return true;
}