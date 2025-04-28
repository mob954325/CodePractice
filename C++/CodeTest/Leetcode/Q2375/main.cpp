#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void BackTracking(string &pattern, string &res, int &pointer, int &count)
    {
        if (pointer == pattern.length()) // 마지막 숫자 추가하기
        {
            res += to_string(count);
            return;
        }

        if (pattern[pointer] == 'I') // 증가
        {
            res += to_string(count); // 숫자 추가
        }
        else if (pattern[pointer] == 'D') // 감소
        {
            pointer++;
            count++;
            BackTracking(pattern, res, pointer, count);
            count--;

            res += to_string(count);
        }
    }

    string smallestNumber(string pattern) {
        // 0 인덱스부터 시작하는 길이가 n인 parttern 문자열이 있다.
        // 길이가 n + 1인 문자열 num은 밑의 조건에 따라서 만들어진다.
        // num은 1과 9로 구성된다. 최대 한번만 사용 되었다.
        // pattern[i] == I면 num[i] < num[i + 1]이다.
        // patter[i] == D면 num[i] > num[i + 1]이다.
        // 사전 순서대로 가장 작은 문자열인 num을 반환해라. 위 조건을 만족하는 

        // 해결       
        // 다른 문자가 나올 때 까지 갱신
        // 다른 문자가 나오면 숫자 넣고 다시 dfs 찾기 시작
        // I면 바로 숫자 추가하고, D면 최대 거리거나 다른 문자가 나올 때까지 데이터를 저장했다가 해당 위치부터 숫자 증가

        string res = "";
        int count = 1;
        int pointer = 0;

        for (;pointer <= pattern.length(); pointer++)
        {
            BackTracking(pattern, res, pointer, count);
            count = pointer + 2; // 다음 숫자 갱신
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();
    string str = "I";
    sol.smallestNumber(str);
}