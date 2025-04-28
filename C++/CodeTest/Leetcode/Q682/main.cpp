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
    // 야구게임 (이상한 룰이 있는)
    // 아래의 규칙에 따라 operations 순서대로 규칙을 적용해라
    // 1. 정수 : 새로운 점수 x
    // 2. + : 이전에 등록된 2개의 점수를 더한다
    // 3. D : 새로 등록된 점수를 두배
    // 4. C : 이전에 등록된 점수 무효화
    
    // 모든 점수를 규칙대로 적용 시킨 후의 합을 반환

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