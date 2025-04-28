#include <Windows.h>
#include <iostream>

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char* data = "hello world";
	DWORD characters = 0; // 쓴 문자들

	if (1)
	{
		// version 1
		
		WriteConsoleOutputCharacter(h, data, strlen(data), {}, &characters);
	}
	else
	{
		// version 2
		// 메모리 누수를 원하지 않으면 closeHandle();로 핸들을 닫아야한다.
		// 이번엔 프로그램의 전체에서 계쏙 사용되기 때문에 사용하지 않았다.

		HANDLE consolebuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, 0);
		SetConsoleActiveScreenBuffer(consolebuffer);

		WriteConsoleOutputCharacter(h, data, strlen(data), {}, &characters);
	}

	std::cin.get();
	return 0;
}