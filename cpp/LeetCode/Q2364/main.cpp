#include <iostream>
#include <vector>
#include <map>

long long countBadPairs(std::vector<int>& nums) {
    // 0-indexed ���� �迭 nums�� �����Ѵ�. 
    // indices(����) �� pair (i,j)���� i < j �̰ų� j - i != nums[j] - nums[i]�� bad pair�̴�
    // nums���� bad pair�� ������ ��ȯ�϶�

    // �ذ�
    // hashmap�� ��� ������ ����
    // ������� �迭�� ��ü pair ���� - ���� pair ����

    std::map<int, long long> count; // ���ǿ� �����ϴ� pair ����
    int n = nums.size();
    long long total = (long long)n * (n - 1) / 2; // ��ü pair ����

    for (int i = 0; i < n; ++i) count[nums[i] - i]++; // nums[i] - i�� �����ϴ� ����

    long long equal = 0;
    for (auto& it : count) equal += ((it.second * (it.second - 1)) / 2); // �� ������ ���ǿ� �����ϴ� ���� �ٸ� 2���� pair�� ������ ��ü ��
    return total - equal; // �����
}

int main()
{
    std::vector<int> v = { 4,1,3,3 };
    std::cout << countBadPairs(v) << "\n";
}