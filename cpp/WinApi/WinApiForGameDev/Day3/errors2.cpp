// Get error from handle

#include <Windows.h>
#include <iostream>
#include <codecvt>

std::string getLastErrorAsString();

int main()
{
	HANDLE stdhandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO c = {};

	if (GetConsoleCursorInfo(0, &c))
	{
		std::cout << "Good";
	}
	else
	{
		std::string msg = getLastErrorAsString();

		int msBoxID = MessageBox(
			0,
			msg.c_str(),
			"Error !!!",
			MB_ICONERROR);
	}
}

std::string getLastErrorAsString()
{
	DWORD err = GetLastError();	// 에러 메세지

	if (!err) { return ""; } // 에러 없음 

	char* message = 0;

	// 메세지 포맷 지정
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		0, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (char*)&message, 0, nullptr);

	std::string rez(message, size); // 문자열로 데이터 복사

	LocalFree(message); // FORMAT_MESSAGE_ALLOCATE_BUFFER가 메모리를 할당하기 때문에 정리한다.

	return rez;
}