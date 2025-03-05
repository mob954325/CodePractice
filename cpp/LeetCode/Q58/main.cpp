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
	// ���ڿ��� ������ �ܾ� ��ȯ
	int size = s.size();
	int count = 0;

	for (int i = size - 1; i > -1; i--)
	{
		char c = s[i];
		if (count != 0 && c == ' ') break; // ���� ��ĭ�̸� Ż��
		if (c != ' ') count++; // ��ĭ�� �ƴϸ�
	}

	return count;
}