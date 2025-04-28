#include <iostream>
#include <vector>
#include <algorithm>

int largestPerimeter(std::vector<int>& nums);

int main()
{
    std::vector<int> v = { 2,1,2 };
    std::cout << largestPerimeter(v);//5
}

int largestPerimeter(std::vector<int>& nums) {
    // 0�� �ƴ� ���� ū �ﰢ�� �ѷ� ã�� 
    // 0�� �ƴ� �ﰢ���� ����� ���� �ȵǸ� 0
    // ���� ���� �� ���� ���̰� �ٸ� �� ���� ������ �պ��� �۾ƾ��Ѵ�.

    // �ذ� O(n^2)?
    // nums �������� ����
    // 10 9 2 ...
    // i���� ���� �亯���� �ϰ� i + 1�� i + 2��°�� ���� 
    // i���� ū�� Ȯ�� �� ������ true �ƴϸ� false

    // sort default�� �������� �����̹Ƿ� �Ųٷ� �ϱ�
    std::sort(nums.begin(), nums.end()); // �������� ����
    for (int i = nums.size() - 1; i > 1; i--)
    {
        // [i] < [i - 1] + [i - 2]���� Ȯ��
        if (nums[i] < nums[i - 1] + nums[i - 2])
            return nums[i] + nums[i - 1] + nums[i - 2];
    }

    return 0;
}