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
    //1. ������ ���ڿ� 1�� ���ϰ� 10���� �ƴ��� �Ǻ�
    //1.1 �ƴϸ� ���ϰ� ��ȯ
    //1.2 10�̸�
    // �ش���ġ�� ���� 0���� �ٲٰ� 
    // ������ �̵��ϸ鼭 9�� �ƴ� ������ ������ 1���ϱ�
    // �̵��ϸ鼭 9�� ��ġ�� 0���� ����

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

        if (count == size - 1) // ���� ���� �ڸ��� Ȯ��
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
    else // ���ڸ��� 1�� ���ϱ�
    {
        digits.back() += 1;
    }

    return digits;
}