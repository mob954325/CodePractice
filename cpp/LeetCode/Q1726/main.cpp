#include <iostream>
#include <vector>
#include <unordered_map>

int tupleSameProduct(std::vector<int>& nums);

int main()
{
    std::vector<int> v{ 2,3,4,6,8,12 };

    std::cout << tupleSameProduct(v) << "\n";
}


int tupleSameProduct(std::vector<int>& nums) {
    // 개별 양의 정수인 배열의 숫자를 준다.
    // a,b,c,d가 nums의 요소이고 서로 다른 숫자이며 a * b = c * d인 튜플의 개수을 반환해라

    // 해결
    // O(n^2)
    // 모든 두 요소의 곱을 찾은 후 해당 값의 개수를 저장해서 해당 개수를 반환한다.

    std::unordered_map<int, int> m;

    if (nums.size() < 4) return 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            std::cout << nums[i] << " * " << nums[j] << " = " << nums[i] * nums[j] << "\n";
            int product = nums[i] * nums[j];
            m[product]++;
        }
    }

    int count = 0;
    for (const auto& e : m)
    {
        std::cout << e.first << " : " << e.second << "\n";
        if (e.second >= 2) // 동일한 값이 존재한다.
        {
            // e.second - 1 만큼 튜플 종류가 늘어난다.
            // 두 요소의 조합 개수 * 나머지 조합 개수 * 4
            count += (e.second * (e.second - 1) * 4);
        }
    }

    return count;
}