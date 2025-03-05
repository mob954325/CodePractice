#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s);

int main()
{
	std::string str = "babbabbabbabbab";
    std::cout << repeatedSubstringPattern(str);
}

bool repeatedSubstringPattern(std::string s) {
    // 문제
    // substring이 여러번 사용된 문자열인지 확인하기

    //해결
    // substring 만들기
    // 문자열 하나하나 substring이랑 비교하기

    int length = s.length();
    int subLength = length / 2; // 절반으로 나누기

    if (length == 1) return false; // 문자 한개만 있으면 false;

    // O(n^2)
    while (subLength > 1)
    {
        std::string subString = s.substr(0, subLength); // substring 설정

        int checkCount = length / subLength; // 확인할 개수

        int checked = 0;

        // 비교하기
        for (int i = 0; i < checkCount; i++)
        {
            // 비교하여 맞지 않은 문자열이면 false
            if (s.compare(subLength * i, subLength, subString) != 0)
            {
                break; // for문 나와서 다음 문자열 체크
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

            return true; // for문 조건이 통과되면 true
        }

        subLength--;
    }

    return false;
}