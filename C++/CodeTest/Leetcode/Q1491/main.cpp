#include <iostream>
#include <vector>
#include <algorithm>

double average(std::vector<int>& salary);

int main()
{
    std::vector<int> v = { 48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000 };

    std::cout << average(v);
}

double average(std::vector<int>& salary) {
    // salary�� �� i��° ������ �޿� �����Ѵ�.
    // �ּ�, �ִ븦 ������ ������ ��� �޿��� ��ȯ�ض�
    // 10^-5�̳��� ���� ��ȯ�ؾ��Ѵ�.

    // �ذ�
    // ¦��, ������ / 2�� ���� ����� ���� 2���� ��� 
    // Ȧ�� ������ / 2�� ���

    sort(salary.begin(), salary.end());
    int size = salary.size();
    int sum = 0;

    for (int i = 1; i < size - 1; i++)
    {
        sum += salary[i];
    }

    return (double)sum / (size - 2);
}