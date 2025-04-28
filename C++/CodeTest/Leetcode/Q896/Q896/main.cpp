#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int>& nums);

int main()
{
    std::vector<int> v = { 1,2,2,3 };

    std::cout << std::boolalpha << isMonotonic(v);
}

bool isMonotonic(std::vector<int>& nums) {
    // monotonic �迭���� Ȯ���ϱ�
    // monotonic(���� �Լ�) : ����������� ���� ���������� �����ϰų� �����ϴ� ����

    // �ذ� 
    // true
    // i <= j �� �� nums[i] <= nums[j] �̰ų� (����)
    // i <= j �� �� nums[i] >= nums[j] �̴�.  (����)

    int size = nums.size();
    if (size < 2) return true; // �Ѱ� �ۿ� ����.        

    int diff = nums[0] - nums[1];

    for (int i = 1; i < size - 1; i++)
    {
        if (nums[i] == nums[i + 1]) continue; // ���� �����ϴ�.

        if ((diff <= 0 && nums[i] <= nums[i + 1]) ||
            (diff >= 0 && nums[i] >= nums[i + 1])) // ���� �����ϰų� �����Ѵ�.
        {
            diff = nums[i] - nums[i + 1];
            continue;
        }
        else return false;

    }

    return true;
}