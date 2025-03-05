#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

char findTheDifference(string s, string t)
{
    // 두 문자열 중 추가된 글자 찾기
    int pointer_s = 0;
    int pointer_t = 0;
    int maxLength_s = s.size();
    int maxLength_t = t.size();

    char result = ' ';

    vector<int> count_s;
    vector<int> count_t;

    count_s.resize(26);
    count_t.resize(26);
    fill(count_s.begin(), count_s.end(), 0);
    fill(count_t.begin(), count_t.end(), 0);

    while (pointer_s < maxLength_s || pointer_t < maxLength_t)
    {
        int cur_s = s[pointer_s];
        int cur_t = t[pointer_t];

        if (cur_s > 96)
        {
            count_s[cur_s - 97]++;
        }

        if (cur_t >= 96)
        {
            count_t[cur_t - 97]++;
        }

        pointer_s++;
        pointer_t++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count_t[i] > count_s[i])
        {
            result = i + 97;
            cout << result;
            return result;
        }
    }

    return result;
}

int main()
{
    string s = "a";
    string t = "aa";

    findTheDifference(s, t);
}