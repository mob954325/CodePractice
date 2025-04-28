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
    // 손님들은 한번에 순서대로 사기위해 대기열을 선다.
    // 그리고 각 5 10 20달러를 낸다.
    // 손님에게 알맞는 잔돈을 내 5달러를 내게해야한다.
    // Note. 처음에는 잔돈이 없다.

    // 해결
    // 순서대로 확인
    // unorderedmap 사용
    // 5, 10, 20 달러 받기
    // 거스름 줄 때 해당 키에서 value--
    // 다 진행한 후 value가 음수가 된 지점이 있으면 false;
    // 다 통과후 true

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

        if (five < 0 || ten < 0) return false; // 개수가 음수면 false
    }

    return true;
}