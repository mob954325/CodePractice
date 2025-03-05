#include <iostream>
#include <vector>
#include <string>
#include <list>

int calPoints(std::vector<std::string>&operations);

int main()
{
    std::vector<std::string> v = { "5", "2", "C", "D", "+" };
    std::cout << calPoints(v);
}

int calPoints(std::vector<std::string>& operations)
{
    // �߱����� (�̻��� ���� �ִ�)
    // �Ʒ��� ��Ģ�� ���� operations ������� ��Ģ�� �����ض�
    // 1. ���� : ���ο� ���� x
    // 2. + : ������ ��ϵ� 2���� ������ ���Ѵ�
    // 3. D : ���� ��ϵ� ������ �ι�
    // 4. C : ������ ��ϵ� ���� ��ȿȭ
    
    // ��� ������ ��Ģ��� ���� ��Ų ���� ���� ��ȯ

    std::vector<int> v;
    int size = operations.size();
    int result = 0;   

    for (int i = 0; i < size; i++)
    {
        if (operations[i] == "+")
        {
            int first = v[v.size() - 1];
            int second = v[v.size() - 2];

            v.push_back(first + second);
        }
        else if (operations[i] == "D")
        {
            int first = v.back();

            v.push_back(first * 2);
        }
        else if (operations[i] == "C")
        {
            v.pop_back();
        }
        else
        {
            std::size_t pos{};
            const int curNum{ std::stoi(operations[i].c_str(), &pos) };
            v.push_back(curNum);
        }
    }

    for (int num : v)
    {
        result += num;
    }

    return result;
}