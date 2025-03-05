#include <vector>

bool isArraySpecial(std::vector<int>& nums) {
    // 특정 조건을 가진 배열인지 확인
    // 순서대로 한 쌍이 홀짝으로 이뤄져 있으면 Special 배열이라고한다.
    // 해당 조건에 만족하면 true 아니면 false 반환
    // 참고> 모든 배열 요소가 해당 조건에 만족해야 true

    if (nums.size() == 1) return true;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] % 2 == nums[i + 1] % 2) return false;
    }

    return true;
}