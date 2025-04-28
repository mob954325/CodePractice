#include <iostream>
#include <vector>
#include <map>

long long countBadPairs(std::vector<int>& nums) {
    // 0-indexed 정수 배열 nums를 제공한다. 
    // indices(지수) 의 pair (i,j)에서 i < j 이거나 j - i != nums[j] - nums[i]면 bad pair이다
    // nums에서 bad pair의 개수를 반환하라

    // 해결
    // hashmap에 결과 데이터 저장
    // 결과값은 배열의 전체 pair 개수 - 옳은 pair 개수

    std::map<int, long long> count; // 조건에 만족하는 pair 개수
    int n = nums.size();
    long long total = (long long)n * (n - 1) / 2; // 전체 pair 개수

    for (int i = 0; i < n; ++i) count[nums[i] - i]++; // nums[i] - i에 만족하는 개수

    long long equal = 0;
    for (auto& it : count) equal += ((it.second * (it.second - 1)) / 2); // 각 값마다 조건에 만족하는 서로 다른 2개의 pair를 선택한 전체 합
    return total - equal; // 결과값
}

int main()
{
    std::vector<int> v = { 4,1,3,3 };
    std::cout << countBadPairs(v) << "\n";
}