#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    // Subsequence : 원본 문자열에서 몇 개를 제거해 구성한 문자열 (남은 문자의 상대적인 위치와 방해 없이)
    // str2가 str1의 서브시퀀스가 되면 true 아니면 false    

    // hint
    // 1과 2가 있거나 증가한 1과 2가 있으면 포인터 모두 증가, 그렇지 않으면 i만 증가

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