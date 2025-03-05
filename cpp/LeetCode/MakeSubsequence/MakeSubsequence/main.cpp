#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    // Subsequence : ���� ���ڿ����� �� ���� ������ ������ ���ڿ� (���� ������ ������� ��ġ�� ���� ����)
    // str2�� str1�� ����������� �Ǹ� true �ƴϸ� false    

    // hint
    // 1�� 2�� �ְų� ������ 1�� 2�� ������ ������ ��� ����, �׷��� ������ i�� ����

    int i = 0;
    int j = 0;


    while (i < str1.length())
    {
        int next = str1[i] + 1 > 122 ? 97 : str1[i] + 1;

        if (str1[i] == str2[j] || next == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return j == str2.length();
}

int main()
{
    string str1 = { 'a', 'b', 'c'};
    string str2 = { 'a', 'd' };

    cout << canMakeSubsequence(str1, str2);
}