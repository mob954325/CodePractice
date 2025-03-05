#include <iostream>
#include <string>

int lengthOfLastWord(std::string s);

int main()
{
	std::string s = "luffy is still joyboy";
	std::cout << lengthOfLastWord(s);
}

int lengthOfLastWord(std::string s)
{
	// 문자열의 마지막 단어 반환
	int size = s.size();
	int count = 0;

	for (int i = size - 1; i > -1; i--)
	{
		char c = s[i];
		if (count != 0 && c == ' ') break; // 다음 빈칸이면 탈출
		if (c != ' ') count++; // 빈칸이 아니면
	}

	return count;
}