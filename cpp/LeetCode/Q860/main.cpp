#include <iostream>
#include <vector>
#include <unordered_map>

bool lemonadeChange(std::vector<int>& bills);

int main()
{ 
    std::vector<int> v1{ 5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5 };  // true
    std::cout << std::boolalpha << lemonadeChange(v1) << "\n";

    std::vector<int> v2{ 5,5,10,10,20 }; // false
    std::cout << std::boolalpha << lemonadeChange(v2);
}

bool lemonadeChange(std::vector<int>& bills) {
    // �մԵ��� �ѹ��� ������� ������� ��⿭�� ����.
    // �׸��� �� 5 10 20�޷��� ����.
    // �մԿ��� �˸´� �ܵ��� �� 5�޷��� �����ؾ��Ѵ�.
    // Note. ó������ �ܵ��� ����.

    // �ذ�
    // ������� Ȯ��
    // unorderedmap ���
    // 5, 10, 20 �޷� �ޱ�
    // �Ž��� �� �� �ش� Ű���� value--
    // �� ������ �� value�� ������ �� ������ ������ false;
    // �� ����� true

    if (bills[0] == 10 || bills[0] == 20) return false;

    int five = 0, ten = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            ten++;
            five--;
        }
        else if (bills[i] == 20)
        {
            // 10 , 5 
            // 5 5 5 
            if (ten != 0)
            {
                ten--;
                five--;
            }
            else
            {
                five -= 3;
            }
        }

        if (five < 0 || ten < 0) return false; // ������ ������ false
    }

    return true;
}