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
    // 배열이 순서대로 나열되어 있는지 확인
    // 배열 중 일부는 순환되어 있다 ex> 3 4 5 1 2

    // 해결
    // 배열을 2개 연결해서 순환되는지 확인하기

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