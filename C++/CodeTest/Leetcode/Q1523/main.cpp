#include <iostream>

int countOdds(int low, int high);

int main()
{
	int low = 3;
	int high = 7;
	std::cout << countOdds(low, high);
}

int countOdds(int low, int high) {
    // ������ �ƴ� ���� low, high
    // low�̻� high���� ������ Ȧ���� ������ ���� ��ȯ

    // �ذ�
    // 1�� low - 1 ������ Ȧ�� ������ low / 2
    // 1�� high ������ Ȧ�� ������ (high + 1) / 2
    // ���� �信�� ���� ��
    // (1���� high������ ��� Ȧ�� ����) - (1�� low -1 ������ Ȧ������) 

    return ((high + 1) / 2) - (low / 2);
}
