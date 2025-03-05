#include <iostream>
#include <string>

std::string toLowerCase(std::string s);

int main()
{
	std::string s = "al&phaBET";
	std::cout << toLowerCase(s);
}

std::string toLowerCase(std::string s)
{
	// 문자열 s에 있는 모든 대문자를 소문자로 바꿔라
	int size = s.size();

	for (char& c : s)
	{
		c = tolower(c);
	}

	return s;
}