#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2);

int main()
{
    std::string n1 = "123", n2 = "456";
    std::cout << multiply(n1, n2);
}

std::string multiply(std::string num1, std::string num2)
{
        // ��ȯ���� �ʰ� ������ �ƴ� �� ���ڿ������� ������ ���ϱ�
        
        // 0 ���� ó��
        if (num1 == "0" || num2 == "0") return "0";

        // ���� ������ŭ �ִ� vector
        std::vector<int> num(num1.size() + num2.size(), 0);

        // �ѹ��� ���ڸ����� ���Ͽ� ���� ����
        for(int i = num1.size() - 1; i >= 0; --i)
        {
            for(int j = num2.size() - 1; j >= 0; --j)
            {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // ����
                num[i + j] += num[i + j + 1] / 10; // 10�� �ʰ��ϸ� �ڸ��� �ø���
                num[i + j + 1] %= 10;              // -10 
            }
        }

        // 0�� ĭ üũ (���ڿ� ��ȯ �� ���� 0�� ������ �� ����)
        int i = 0;
        while(1 < num.size() && num[i] == 0) ++i;

        // vector�� ���ڿ��� ��ȯ
        std::string res = "";
        while(i < num.size()) res.push_back(num[i++] + '0'); // ���� �߰� , i��°���� ��ȯ

        return res;    
}
