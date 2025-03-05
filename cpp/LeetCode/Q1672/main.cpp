#include <iostream>
#include <vector>

int maximumWealth(std::vector<std::vector<int>>& accounts);

int main()
{
	
}

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    // 가장 부자의 재산값을 찾기
    // 2차원 배열의 재산이 있다.
    // i번째 손님은 j개의 은행이 있고 각 은행은 재산 값을 가지고 있다.

    // 해결
    // 각 i번째 손님의 j번 값을 다 합치고 가장 높은 값을 저장후 반환

    int richestWealth = 0;
    for (int i = 0; i < accounts.size(); i++) {
        int currentWealth = 0;
        for (int j = 0; j < accounts[i].size(); j++) {
            currentWealth += accounts[i][j];
        }

        if (currentWealth > richestWealth)
            richestWealth = currentWealth;
    }

    return richestWealth;
}