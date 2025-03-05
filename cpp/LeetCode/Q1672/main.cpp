#include <iostream>
#include <vector>

int maximumWealth(std::vector<std::vector<int>>& accounts);

int main()
{
	
}

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    // ���� ������ ��갪�� ã��
    // 2���� �迭�� ����� �ִ�.
    // i��° �մ��� j���� ������ �ְ� �� ������ ��� ���� ������ �ִ�.

    // �ذ�
    // �� i��° �մ��� j�� ���� �� ��ġ�� ���� ���� ���� ������ ��ȯ

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