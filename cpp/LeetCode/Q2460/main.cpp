#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 문제 
    // 음수가 없는 인덱스가 0부터 시작하는 배열 nums 제공
    // i번째 인덱스마다 부호를 적용시켜야한다.
    // num에 있는 i번째 요소는 밑의 내용을 적용해야한다.
    // 1. nums[i] == nums[i + 1]이면 nums[i]를 2 곱하고 nums[i + 1]을 0으로 변경한다.
    // 그렇지 않으면 해당 부호를 스킵한다.
    // 2. 모든 부호 연산이 종료되면 0을 배열의 마지막으로 이동

    // 해결 
    // two pointer
    // 모든 배열을 한 번 돌아서 1번의 규칙을 적용시킨다.
    // two pointer로 0과 다음 0이 아닌 수를 서로 교환한다.
    // curr이 0이면 target이 0이 아닌 수가 나올 때까지 target 증가
    // target이 수를 찾으면 서로 스왑후 curr증가
public:
    vector<int> applyOperations(vector<int>& nums) {
        int size = nums.size();

        // 1. 1번 규칙 적용시키기
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int currPointer = 0;
        int targetPointer = 1;
        // 2. two pointer로 0과 0이 아닌 수 스왑
        while (currPointer < size && targetPointer < size)
        {
            int curr = nums[currPointer];
            int target = nums[targetPointer];

            if (curr == 0)
            {
                // 0이 아닌 수를 찾음
                if (target != 0 && targetPointer > currPointer)
                {
                    nums[currPointer] = target;
                    nums[targetPointer] = 0;

                    currPointer++;
                    targetPointer = currPointer + 1;

                    if (targetPointer == size) break; // currPointer의 다음이 배열의 끝이면 반복 탈출
                }
                else
                {
                    // targetPointer++
                    if (targetPointer <= currPointer)
                    {
                        targetPointer = currPointer + 1;
                    }
                    else
                    {
                        targetPointer++;
                    }
                }
            }
            else // curr != 0
            {
                currPointer++;
            }
        } // while end

        return nums;
    }
};


int main()
{
    Solution sol = Solution();

    vector<int> v = {2,1 };

    sol.applyOperations(v);
}