#include <iostream>
#include <vector>

int arraySign(std::vector<int>& nums);

int main()
{
    std::vector<int> v = { 9,72,34,29,-49,-22,-77,-17,-66,-75,-44,-30,-24 };
    arraySign(v);
}

int arraySign(std::vector<int>& nums) {
    // �Լ� �����ϱ�

    // x�� ����� 1
    // x�� ������ -1
    // x�� 0�̸� 0

    // nums �迭�� �����ȴ�.
    // �迭�� ��� ���ڸ� ���ض�
    // �� ���� signFunc(product)�� ��ȯ

    // �ذ�
    // ��� ���� ���ϱ�
    // signFunc ��ȯ ���� ���� ��ȯ

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