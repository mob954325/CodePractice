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
    // �� ������ ������ ���ڿ� ����
    // �� ���ڿ����� �� ������ ���� �� ������ ���ڸ� ���� ��ȯ�ϴ� ���� string swap�̶�� �Ѵ�.
    // string swap�� ���� �� ���ڿ��� ���� �� ������ true �ƴϸ� false
    // -> ��Ȯ�� �� ���ڿ����� �ѹ��� �������� ���ƾ��Ѵ�.

    // �ذ�
    // O(n)
    // two pointer
    // ���ڸ��� �� ��ġ�� ���ڸ� �����Ͽ��� ������ Ȯ���ϱ�
    // ������ true
    // ���ڸ� �� Ȯ���ߴµ� ������ false

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

        // ��ȯ
        std::string checkString = s2;
        char current = s2[currentIndex];
        char target = s2[swapIndex];

        checkString[currentIndex] = target;
        checkString[swapIndex] = current;

        // Ȯ��
        if (checkString == s1) return true;

        swapIndex++;
    }

    return false;
}