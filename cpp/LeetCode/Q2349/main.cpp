#include <iostream>
#include <map>
#include <set>

class NumberContainers {
public:
    std::map<int, int> container_value; // index�� ������ �ִ� value ����
    std::map<int, std::set<int>> container_index; // �ش� value�� ���� index ����

    NumberContainers() {
    }

    void change(int index, int number) {
        if (this->container_value[index] != number) // �ش� ���ڰ� �̹� �����Ѵ�
        {
            int prev_num = container_value[index]; // ��������
            auto it = container_index[prev_num].find(index);
            if (it != container_index[prev_num].end()) // �ش� ������ �ε����� �ִ��� Ȯ�� 
            {
                container_index[prev_num].erase(it); // �ε��� ����
            }

            container_value[index] = number; // �ε����� ���� ����
        }

        container_index[number].insert(index); // ����� �ε��� �߰�
    }

    int find(int number) {
        if (container_index[number].size() == 0) return -1; // �ش� �ε����� ���� ���ڰ� ����

        return *container_index[number].begin(); // �ش� ���ڸ� ���� �ε��� �� ���� ���� �ε��� ��ȯ�ϱ�
    }
};

int main()
{
    NumberContainers nc = NumberContainers();

    nc.find(10);
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    nc.find(10);
}