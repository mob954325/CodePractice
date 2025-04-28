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
    // ���� ���� ������ �迭�� ���ڸ� �ش�.
    // a,b,c,d�� nums�� ����̰� ���� �ٸ� �����̸� a * b = c * d�� Ʃ���� ������ ��ȯ�ض�

    // �ذ�
    // O(n^2)
    // ��� �� ����� ���� ã�� �� �ش� ���� ������ �����ؼ� �ش� ������ ��ȯ�Ѵ�.

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
        if (e.second >= 2) // ������ ���� �����Ѵ�.
        {
            // e.second - 1 ��ŭ Ʃ�� ������ �þ��.
            // �� ����� ���� ���� * ������ ���� ���� * 4
            count += (e.second * (e.second - 1) * 4);
        }
    }

    return count;
}