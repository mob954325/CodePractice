#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s1, string s2, int s) {
    string answer = "";

    for (int i = 0; i < s; i++)
    {
        answer += s1[i];
    }

    for (int j = 0; j < s2.length(); j++)
    {
        answer += s2[j];
        s++;
    }

    for (int i = s; i < s1.length(); i++)
    {
        answer += s1[i];
    }

    return answer;
}