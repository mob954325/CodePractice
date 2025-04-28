#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int>& nums);

int main()
{
    std::vector<int> v = { 1,2,2,3 };

    std::cout << std::boolalpha << isMonotonic(v);
}

bool isMonotonic(std::vector<int>& nums) {
    // monotonic 배열인지 확인하기
    // monotonic(단조 함수) : 통계학적으로 값이 지속적으로 증가하거나 감소하는 형태

    // 해결 
    // true
    // i <= j 일 때 nums[i] <= nums[j] 이거나 (증가)
    // i <= j 일 때 nums[i] >= nums[j] 이다.  (감소)

    int size = nums.size();
    if (size < 2) return true; // 한개 밖에 없다.        

    int diff = nums[0] - nums[1];

    for (int i = 1; i < size - 1; i++)
    {
        if (nums[i] == nums[i + 1]) continue; // 값이 동일하다.

        if ((diff <= 0 && nums[i] <= nums[i + 1]) ||
            (diff >= 0 && nums[i] >= nums[i + 1])) // 값이 증가하거나 감소한다.
        {
            diff = nums[i] - nums[i + 1];
            continue;
        }
        else return false;

    }

    return true;
}