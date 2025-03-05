#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b);

int main()
{
    std::string a = "100";
    std::string b = "110010";
    std::cout << addBinary(a, b) << "\n"; // 11110
}

// 100011

std::string addBinary(std::string a, std::string b) 
{
    // ���� ���ڿ� a b�� ���Ͻÿ�

    // �ذ�
    // ���ڷ� �ذ��ؾ��� ( �ִ� ���� => 10^4 2�� -> �����÷ο� )
    // 1. two pointer
    // 2. a�� b �������� ��ġ���� �Ѵ� 1�̴� == �ش� ��ġ���� 0,
    // ���� ��ġ���� 1 �߰�

    int pointerA = a.length() - 1;
    int pointerB = b.length() - 1;
    int pointerS = 0; // ���� ū �ڸ����� ������ �� ( �� ���翩�� Ȯ�ο� )
    std::string s = "";

    while (pointerA >= 0 && pointerB >= 0) // ??
    {
        if (a[pointerA] == '1' && b[pointerB] == '1') // �Ѵ� 1�̴�.
        {
            if (s[pointerS] == '1')
            {
                s[pointerS] = '1';
                s += "1";  
            }
            else 
            {
                s += "0";
                s += "1"; 
            }  
        }
        else if (a[pointerA] == '0' && b[pointerB] == '0') // �Ѵ� 0
        {
            if (s[pointerS] != '1') s += "0";   // �ش� ��ġ�� ���� ������ �߰�
        }
        else // ���� �ٸ�
        {
            if (s[pointerS] == '1') // �̹� 1�� ������ �ڸ��� �ѱ��
            {
                s[pointerS] = '0';
                s += "1";
            }
            else // ���� ����.
            {
                s += "1";
            }
        }

        pointerA--;
        pointerB--;
        pointerS++;
    }

    // ���� �迭 ó�� ( s��ġ���� ������ ���ϱ� )
    if (pointerA < 0)
    {
        while (pointerB >= 0)
        {
            if (s[pointerS] == '1')
            {
                if (b[pointerB] == '1')
                {
                    s[pointerS] = '0';
                    s += "1";
                }
            }
            else /// ���� ����
            {
                if (b[pointerB] == '1')
                {
                    s += '1';
                }
                else
                {
                    s += '0';
                }
            }

            pointerB--;
            pointerS++;
        }
    }
    else if (pointerB < 0)
    {
        while (pointerA >= 0)
        {
            if (s[pointerS] == '1')
            {
                if (a[pointerA] == '1')
                {
                    s[pointerS] = '0';
                    s += "1";
                }
            }
            else // ���� ����
            {
                if (a[pointerA] == '1')
                {
                    s += '1';
                }
                else
                {
                    s += '0';
                }
            }

            pointerA--;
            pointerS++;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}