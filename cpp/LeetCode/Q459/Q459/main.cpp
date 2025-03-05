#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s);

int main()
{
	std::string str = "babbabbabbabbab";
    std::cout << repeatedSubstringPattern(str);
}

bool repeatedSubstringPattern(std::string s) {
    // ����
    // substring�� ������ ���� ���ڿ����� Ȯ���ϱ�

    //�ذ�
    // substring �����
    // ���ڿ� �ϳ��ϳ� substring�̶� ���ϱ�

    int length = s.length();
    int subLength = length / 2; // �������� ������

    if (length == 1) return false; // ���� �Ѱ��� ������ false;

    // O(n^2)
    while (subLength > 1)
    {
        std::string subString = s.substr(0, subLength); // substring ����

        int checkCount = length / subLength; // Ȯ���� ����

        int checked = 0;

        // ���ϱ�
        for (int i = 0; i < checkCount; i++)
        {
            // ���Ͽ� ���� ���� ���ڿ��̸� false
            if (s.compare(subLength * i, subLength, subString) != 0)
            {
                break; // for�� ���ͼ� ���� ���ڿ� üũ
            }
            else 
            {
                checked++;
            }
        }

        if (checked == checkCount)
        {
            if (length % subLength != 0)
            {
                subLength--;
                continue;
            }

            return true; // for�� ������ ����Ǹ� true
        }

        subLength--;
    }

    return false;
}