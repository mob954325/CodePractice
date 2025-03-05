#include <Windows.h>
#include <iostream>
#include <cctype>
#include <chrono>


// Global values
int boardWidth = 10;
int boardHeight = 10;

// str to wstring 
std::wstring s2ws(const std::string& s);

bool IsVaildPosition(int x, int y);

bool CheckHandleError(HANDLE handle);

std::string getLastErrorAsString();

void DrawGame(HANDLE stdbuffer, HANDLE consoleBuffer, int boardX, int boardY, COORD pos);

int main()
{
	// Handle
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD characters = 0; //characters written

	// string to LPCWSTR
	const char* strData = "hello world";
	std::wstring stemp = s2ws(strData);
	LPCWSTR data = stemp.c_str(); // wstring to lpcwstr

	// player
	COORD playerCoord;
	playerCoord.X = 0;
	playerCoord.Y = 0;

	int version = 0;

	CheckHandleError(stdHandle);

	if (version)
	{
		//version 1		 
		// 저장용 다음 위치값
		COORD nextCoord;

		nextCoord.X = 0;
		nextCoord.Y = 0;

		auto start = std::chrono::high_resolution_clock::now();
		while (true)
		{
			std::system("cls"); //clear the screen

			auto stop = std::chrono::high_resolution_clock::now();
			float deltaTime = (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count() / 1'000'000.0f;
			start = stop;

			static float counter = 0.5; //0.5 secconds
			counter -= deltaTime;
			if (counter <= 0)
			{
				counter += 0.5; //0.5 secconds

				//move player
				if (IsVaildPosition(nextCoord.X, nextCoord.Y))
				{
					playerCoord.X = nextCoord.X;
					playerCoord.Y = nextCoord.Y;
				}
				else
				{
					nextCoord.X = playerCoord.X;
					nextCoord.Y = playerCoord.Y;
				}
			}

			//get the player's input here
			for (int i = 0; i < 256; i++)
			{
				// check key input
				if (GetAsyncKeyState(i) & 0b1)
				{
					int nextX = playerCoord.X;
					int nextY = playerCoord.Y;

					if (i == VK_UP)
					{
						nextY--;
					}
					else if (i == VK_DOWN)
					{
						nextY++;
					}
					else if (i == VK_LEFT)
					{
						nextX--;
					}
					else if (i == VK_RIGHT)
					{
						nextX++;
					}

					nextCoord.X = playerCoord.X;
					nextCoord.Y = playerCoord.Y;
				}
			}

			//draw the game using std::cout
			int curPosX = nextCoord.X + 1;
			int curPosY = nextCoord.Y + 1;

			// 위 모서리 출력
			for (int x = 0; x < boardWidth + 2; x++)
			{
				std::cout << "-";
			}

			std::cout << "\n";

			// 게임 보드 안쪽 출력 (좌측 상단 : (1, 1), 우측 하단(boardX, boradY)
			for (int y = 1; y < boardHeight + 1; y++)
			{
				// 끝에 "|" 출력
				for (int x = 0; x < boardWidth + 2; x++)
				{
					if (x == 0 || x == boardWidth + 1)
					{
						std::cout << "|";
					}
					else if (curPosX == x && curPosY == y)
					{
						std::cout << "O";
					}
					else
					{
						std::cout << " ";
					}

				}

				std::cout << "\n";
			}

			// 아랫 모서리 출력
			for (int x = 0; x < boardWidth + 2; x++)
			{
				std::cout << "-";
			}
		}
	}
	else
	{
		//version 2
		//This handle has to be closed with closeHandle(); if you don't want to leak memory.
		//I'm not closing it now because it will be used for the entire continuation of the program.

		bool isMove = false;

		COORD nextCoord;
		nextCoord.X = 0;
		nextCoord.Y = 0;

		HANDLE consolebuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr,
			CONSOLE_TEXTMODE_BUFFER, 0);		
		CheckHandleError(consolebuffer);

		consolebuffer = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO consolCursorInfo;
		GetConsoleCursorInfo(consolebuffer, &consolCursorInfo);	// get the old setting
		consolCursorInfo.bVisible = 0;							// changing them
		SetConsoleCursorInfo(consolebuffer, &consolCursorInfo);	// applying the changes

		while (!(GetAsyncKeyState(VK_F1) & 0b1))
		{	
			//get the player's input here
			for (int i = 0; i < 256; i++)
			{
				// check key input
				if (GetAsyncKeyState(i) & 0b1)
				{
					short nextX = playerCoord.X;
					short nextY = playerCoord.Y;

					if (i == VK_UP)
					{
						nextY--;
						isMove = true;
					}
					else if (i == VK_DOWN)
					{
						nextY++;
						isMove = true;
					}
					else if (i == VK_LEFT)
					{
						nextX--;
						isMove = true;
					}
					else if (i == VK_RIGHT)
					{
						nextX++;
						isMove = true;
					}

					nextCoord.X = nextX;
					nextCoord.Y = nextY;
				}
			}

			if (IsVaildPosition(nextCoord.X, nextCoord.Y) && isMove)
			{	
				// 이전 위치 제거
				const char* strData = " ";
				std::wstring stemp = s2ws(strData);
				LPCWSTR data = stemp.c_str(); // wstring to lpcwstr

				DWORD resultWritten = 0;
				WriteConsoleOutputCharacter(consolebuffer, data, strlen(strData), { (short)(playerCoord.X + 1), (short)(playerCoord.Y + 1) }, &resultWritten);

				playerCoord.X = nextCoord.X;
				playerCoord.Y = nextCoord.Y;

				isMove = false;
			}
			else
			{
				nextCoord.X = playerCoord.X;
				nextCoord.Y = playerCoord.Y;
			}

			DrawGame(stdHandle, consolebuffer, boardWidth, boardHeight, playerCoord);		

		}//while End

		CloseHandle(stdHandle);
		CloseHandle(consolebuffer);
	}

	// print board no bug
	// how to move the cursor

	//SetConsoleCursorPosition(); // q3. make Player to this func
	//WriteConsoleOutputCharacter(h, data, strlen(strData), {}, &characters); // 문제2. 콘솔에 문자열 출력
	std::cin.get(); // 문제1. 왜 작동이 안될까?
	return 0;

}

void DrawGame(HANDLE stdbuffer, HANDLE consoleBuffer, int boardX, int boardY, COORD pos)
{
	DWORD characters = 0; //characters written

	short curPosX = pos.X + 1;
	short curPosY = pos.Y + 1;

	// 위 모서리 출력
	for (int x = 0; x < boardX + 2; x++)
	{
		const char* c = "-";
		std::wstring stemp = s2ws(c);
		LPCWSTR data = stemp.c_str();

		WriteConsoleOutputCharacter(stdbuffer, data, strlen(c), { (short)x, 0 }, &characters);
	}

	// 게임 보드 안쪽 출력 (좌측 상단 : (1, 1), 우측 하단(boardX, boradY)
	for (int y = 1; y < boardY + 1; y++)
	{
		const char* c = "|";
		std::wstring stemp = s2ws(c);
		LPCWSTR data = stemp.c_str();

		// 끝에 "|" 출력
		for (int x = 0; x < boardX + 2; x++)
		{
			if (x == 0 || x == boardX + 1)
			{
				WriteConsoleOutputCharacter(stdbuffer, data, strlen(c), { (short)x, (short)(y) }, &characters);
			}
			else if (curPosX == x && curPosY == y)
			{
				const char* str = "0";
				std::wstring stemp = s2ws(str);
				LPCWSTR strData = stemp.c_str();
				DWORD resultWritten = 0;

				const WORD red = FOREGROUND_RED;

				SetConsoleCursorPosition(consoleBuffer, { curPosX, curPosY });
				WriteConsoleOutputCharacter(consoleBuffer, strData, strlen(str), { curPosX, curPosY }, &resultWritten);
				WriteConsoleOutputAttribute(consoleBuffer, &red, strlen(str), { curPosX, curPosY }, &resultWritten);
			}
		}
	}

	// 아랫 모서리 출력
	for (int x = 0; x < boardX + 2; x++)
	{
		const char* c = "-";
		std::wstring stemp = s2ws(c);
		LPCWSTR data = stemp.c_str();

		WriteConsoleOutputCharacter(stdbuffer, data, strlen(c), { (short)x, (short)(boardHeight + 1) }, &characters);
	}
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

bool IsVaildPosition(int x, int y)
{
	return x >= 0 && y >= 0 && x < boardWidth && y < boardHeight;
}

bool CheckHandleError(HANDLE _handle)
{
	HANDLE tempHandle = _handle;
	CONSOLE_CURSOR_INFO c = {};

	bool result = GetConsoleCursorInfo(_handle, &c);

	if (!result)
	{
		std::string msg = getLastErrorAsString();
		std::wstring stemp = s2ws(msg);
		LPCWSTR lpcwstr = stemp.c_str();

		int msBoxID = MessageBox(
			0,
			lpcwstr,
			(LPCWSTR)L"Error !!!",
			MB_ICONERROR);
	}

	return result;
}

std::string getLastErrorAsString()
{
	DWORD err = GetLastError();

	if (!err) { return ""; } // no error

	char* message = 0;

	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		0, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (char*)&message, 0, nullptr);

	std::string rez(message, size); // copy the data into a string

	LocalFree(message); // FORMAT_MESSAGE_ALLOCATE_BUFFER allocates memory for us so we need to clear it.

	return rez;
}