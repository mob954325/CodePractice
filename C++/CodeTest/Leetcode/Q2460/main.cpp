#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // ���� 
    // ������ ���� �ε����� 0���� �����ϴ� �迭 nums ����
    // i��° �ε������� ��ȣ�� ������Ѿ��Ѵ�.
    // num�� �ִ� i��° ��Ҵ� ���� ������ �����ؾ��Ѵ�.
    // 1. nums[i] == nums[i + 1]�̸� nums[i]�� 2 ���ϰ� nums[i + 1]�� 0���� �����Ѵ�.
    // �׷��� ������ �ش� ��ȣ�� ��ŵ�Ѵ�.
    // 2. ��� ��ȣ ������ ����Ǹ� 0�� �迭�� ���������� �̵�

    // �ذ� 
    // two pointer
    // ��� �迭�� �� �� ���Ƽ� 1���� ��Ģ�� �����Ų��.
    // two pointer�� 0�� ���� 0�� �ƴ� ���� ���� ��ȯ�Ѵ�.
    // curr�� 0�̸� target�� 0�� �ƴ� ���� ���� ������ target ����
    // target�� ���� ã���� ���� ������ curr����
public:
    vector<int> applyOperations(vector<int>& nums) {
        int size = nums.size();

        // 1. 1�� ��Ģ �����Ű��
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
        // 2. two pointer�� 0�� 0�� �ƴ� �� ����
        while (currPointer < size && targetPointer < size)
        {
            int curr = nums[currPointer];
            int target = nums[targetPointer];

            if (curr == 0)
            {
                // 0�� �ƴ� ���� ã��
                if (target != 0 && targetPointer > currPointer)
                {
                    nums[currPointer] = target;
                    nums[targetPointer] = 0;

                    currPointer++;
                    targetPointer = currPointer + 1;

                    if (targetPointer == size) break; // currPointer�� ������ �迭�� ���̸� �ݺ� Ż��
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