#include <iostream>
#include <vector>
#include <math.h>

// 1 <= digits.length <= 100

std::vector<int> plusOne(std::vector<int>& digits);

int main()
{
    std::vector<int> v = { 8,9,9,9 };

    plusOne(v);

    for (auto a : v)
    {
        std::cout << a << " ";
    }
}

std::vector<int> plusOne(std::vector<int>& digits)
{
    //1. 마지막 숫자에 1을 더하고 10인지 아닌지 판별
    //1.1 아니면 더하고 반환
    //1.2 10이면
    // 해당위치의 값을 0으로 바꾸고 
    // 포인터 이동하면서 9가 아닌 곳까지 간다음 1더하기
    // 이동하면서 9인 위치는 0으로 변경

    std::vector<int>::iterator it;
    int lastNum = digits.back();
    int size = digits.size();
    int count = 0;

    if (lastNum >= 9)
    {
        for (it = digits.end() - 1;  it > digits.begin();)
        {
            int curNum = *it;
            *it = curNum + 1;

            if (*it < 10) break;
            else
            {
                *it = 0;
                it--;

                count++;
            }
        }

        if (count == size - 1) // 가장 높은 자릿수 확인
        {
            int firstNum = *it;

            if (firstNum + 1 == 10)
            {
                *it = 1; 
                digits.push_back(0);
            }
            else
            {
                *it = *it + 1;
            }
        }
    }
    else // 뒷자리수 1만 더하기
    {
        digits.back() += 1;
    }

    return digits;
}