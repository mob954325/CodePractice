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
	// ���ڿ� s�� �ִ� ��� �빮�ڸ� �ҹ��ڷ� �ٲ��
	int size = s.size();

	for (char& c : s)
	{
		c = tolower(c);
	}

	return s;
}