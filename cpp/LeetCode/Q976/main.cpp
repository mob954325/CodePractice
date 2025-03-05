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
    // 0이 아닌 가장 큰 삼각형 둘레 찾기 
    // 0이 아닌 삼각형을 만드는 것이 안되면 0
    // 조건 가장 긴 변의 길이가 다른 두 변의 길이의 합보다 작아야한다.

    // 해결 O(n^2)?
    // nums 내림차순 정렬
    // 10 9 2 ...
    // i번을 가장 긴변으로 하고 i + 1과 i + 2번째의 합이 
    // i보다 큰지 확인 후 맞으면 true 아니면 false

    // sort default가 오름차순 정렬이므로 거꾸로 하기
    std::sort(nums.begin(), nums.end()); // 오름차순 정렬
    for (int i = nums.size() - 1; i > 1; i--)
    {
        // [i] < [i - 1] + [i - 2]인지 확인
        if (nums[i] < nums[i - 1] + nums[i - 2])
            return nums[i] + nums[i - 1] + nums[i - 2];
    }

    return 0;
}