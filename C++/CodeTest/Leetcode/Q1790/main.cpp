#include <iostream>
#include <string>

bool areAlmostEqual(std::string s1, std::string s2);

int main()
{
    std::string s1 = "abcd";
    std::string s2 = "abcd";

    std::cout << areAlmostEqual(s1, s2);
}

bool areAlmostEqual(std::string s1, std::string s2) {
    // 두 동일한 길이의 문자열 제공
    // 한 문자열에서 두 지점을 고르고 두 지점의 문자를 서로 교환하는 것을 string swap이라고 한다.
    // string swap을 통해 두 문자열이 같을 수 있으면 true 아니면 false
    // -> 정확히 한 문자열에서 한번의 스왑으로 같아야한다.

    // 해결
    // O(n)
    // two pointer
    // 문자마다 각 위치의 문자를 스왑하여서 같은지 확인하기
    // 같으면 true
    // 문자를 다 확인했는데 없으면 false

    if (s1.size() == 1) return true;

    int currentIndex = 0;
    int swapIndex = 1;

    while (currentIndex != s2.size() - 1)
    {
        if (swapIndex >= s2.size())
        {
            currentIndex++;
            swapIndex = currentIndex + 1;
        }

        // 교환
        std::string checkString = s2;
        char current = s2[currentIndex];
        char target = s2[swapIndex];

        checkString[currentIndex] = target;
        checkString[swapIndex] = current;

        // 확인
        if (checkString == s1) return true;

        swapIndex++;
    }

    return false;
}