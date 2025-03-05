#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSum(std::vector<int>& nums) {
        // 문제
        // 배열에 양수 정수들이 담긴 nums를 제공
        // 특정 인덱스 i j에서 (i != j 일 때) 인덱스번째 숫자를 각각 더한 값이 같은 한 쌍의 숫자들 중 가장 높은 값을 반환해라

        // 해결
        // O(n^2)
        // 각 숫자를 더한 값과 이전 값을 map으로 정리 후 같은 값끼리 더한 것중 가장 높은거 반환
        // map은 반복기로 확인해야해서 비효율적이므로 벡터의 페어 데이터를 넣어서 인덱스 확인

        int size = nums.size();

        std::vector<int> v; // sum 컨테이너
        int ans = -1;
        std::vector<std::pair<int, int>> p; // (sum, index번의 정수)

        for (int i = 0; i < size; i++)
        {
            int curr = 0, sum = 0;
            curr = nums[i];
            while (curr != 0)
            {
                sum += curr % 10;
                curr = curr / 10;
            }

            v.push_back(sum);
        }

        for (int i = 0; i < size; i++)
        {
            p.push_back(std::make_pair(v[i], nums[i]));
        }

        sort(p.begin(), p.end()); // 정렬

        for (int i = 0; i < size - 1; i++)
        {
            if (p[i].first == p[i + 1].first) // 같은 합이면 
            {
                ans = std::max(ans, p[i].second + p[i + 1].second);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol = Solution();

    std::vector<int> v = { 4,6,10,6 };
    std::cout << sol.maximumSum(v);
}