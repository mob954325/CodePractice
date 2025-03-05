#include <iostream>
#include <vector>

int arraySign(std::vector<int>& nums);

int main()
{
    std::vector<int> v = { 9,72,34,29,-49,-22,-77,-17,-66,-75,-44,-30,-24 };
    arraySign(v);
}

int arraySign(std::vector<int>& nums) {
    // 함수 구현하기

    // x가 양수면 1
    // x가 음수면 -1
    // x가 0이면 0

    // nums 배열이 제공된다.
    // 배열의 모든 숫자를 곱해라
    // 그 수를 signFunc(product)로 반환

    // 해결
    // 모든 숫자 곱하기
    // signFunc 반환 값에 따라 반환

    int size = nums.size();
    long producted = nums[0] / nums[0];

    for (int i = 1; i < size; i++)
    {
        if (nums[i] > 0)
        {
            producted *= 1;
        }
        else if (nums[i] < 0)
        {
            producted *= -1;
        }
        else
        {
            producted = 0;
        }

        std::cout << producted << "\n";
    }


    // return
    if (producted > 0)
    {
        return 1;
    }
    else if (producted < 0)
    {
        return -1;
    }

    return 0;
}