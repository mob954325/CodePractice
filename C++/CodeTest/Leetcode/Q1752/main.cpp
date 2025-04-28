#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::vector<int>& nums);


int main()
{
    std::vector<int> v = { 1,4,1,2,3,5 };
    std::cout << check(v);
}

bool check(std::vector<int>& nums) {
    // �迭�� ������� �����Ǿ� �ִ��� Ȯ��
    // �迭 �� �Ϻδ� ��ȯ�Ǿ� �ִ� ex> 3 4 5 1 2

    // �ذ�
    // �迭�� 2�� �����ؼ� ��ȯ�Ǵ��� Ȯ���ϱ�

    if (nums.size() == 1) return true;

    int size = nums.size();
    int smallestIndex = 0;
    int largestIndex = 0;

    for (int i = 0; i < size; i++)
    {
        nums.push_back(nums[i]);

        if (nums[i] < nums[smallestIndex])
        {
            smallestIndex = i;
        }

        if (nums[i] > nums[largestIndex])
        {
            largestIndex = i;
        }
    }

    for (int i = smallestIndex; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1] && 
           (nums[i + 1] != nums[smallestIndex] ||
            nums[i] != nums[largestIndex])) return false;
    }

    return true;
};