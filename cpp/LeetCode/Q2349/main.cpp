#include <iostream>
#include <map>
#include <set>

class NumberContainers {
public:
    std::map<int, int> container_value; // index가 가지고 있는 value 매핑
    std::map<int, std::set<int>> container_index; // 해당 value를 가진 index 추적

    NumberContainers() {
    }

    void change(int index, int number) {
        if (this->container_value[index] != number) // 해당 숫자가 이미 존재한다
        {
            int prev_num = container_value[index]; // 이전숫자
            auto it = container_index[prev_num].find(index);
            if (it != container_index[prev_num].end()) // 해당 숫자의 인덱스가 있는지 확인 
            {
                container_index[prev_num].erase(it); // 인덱스 제거
            }

            container_value[index] = number; // 인덱스의 숫자 변경
        }

        container_index[number].insert(index); // 변경된 인덱스 추가
    }

    int find(int number) {
        if (container_index[number].size() == 0) return -1; // 해당 인덱스를 가진 숫자가 없다

        return *container_index[number].begin(); // 해당 숫자를 가진 인덱스 중 가장 작은 인덱스 반환하기
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