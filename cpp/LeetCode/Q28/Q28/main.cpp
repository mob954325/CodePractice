#include <iostream>
#include <string>

std::string haystack = "iririrp"; // 7
std::string needle = "rirp"; // 4

int strStr(std::string m_hay, std::string m_needle);

int main() 
{
	std::cout << strStr(haystack, needle);
}

int strStr(std::string m_hay, std::string m_needle)
{
    // 문자열.substr(시작 인덱스, 문자열 길이)
    int haystackLen = haystack.length();
    int needleLen = needle.length();

    for (int i = 0; i < haystackLen - needleLen + 1; ++i)
    {
        if (haystack.substr(i, needleLen) == needle)
        {
            return i;
        }
    }

    return -1;
}