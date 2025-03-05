#include <iostream>
#include <thread>
#include <Windows.h>

void ThreadFunction()
{
	MessageBox(0, "content", "title", MB_OK);
	
	exit(0);
}

void createTheWindow()
{
	std::thread t(ThreadFunction);
	t.detach(); // 쓰래드 분리 ( 쓰래드가 끝나면 할당된 모든 자원은 free )
	Sleep(32);	// wait some time for the thread and the window to open
}

int main()
{
	createTheWindow();

	HWND wind = FindWindow(0, "title"); // HWND ( 윈도우 핸들 )
	std::cout << wind << "\n";

	while (true)
	{
		// show window
		if (GetAsyncKeyState('A') & 1) // if a was pressed
		{
			std::cout << "pressed A\n";
			ShowWindow(wind, SW_SHOW);
		}

		// hide window
		if (GetAsyncKeyState('S') & 1)
		{
			std::cout << "Pressed S\n";
			ShowWindow(wind, SW_HIDE);
		}

		// change window border
		if (GetAsyncKeyState('Q') & 1)
		{
			std::cout << "Pressed Q\n";
			// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-getwindowlongptra
			auto style = GetWindowLongPtrA(wind, GWL_STYLE); // 창에 대한 정보를 검색 (GWL_STYLE : 창 스타일)
			style ^= WS_BORDER; // 보더 제거 (XOR)
			SetWindowLongPtrA(wind, GWL_STYLE, style);
		}

		// disalbe window
		if (GetAsyncKeyState('W') & 1)
		{
			std::cout << "Pressed W\n";
			auto style = GetWindowLongPtrA(wind, GWL_STYLE);
			style ^= WS_DISABLED;
			SetWindowLongPtrA(wind, GWL_STYLE, style);
		}

		// get window size
		if (GetAsyncKeyState('E') & 1)
		{
			std::cout << "Pressed E\n";

			RECT r = {};

			// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-getwindowrect
			GetWindowRect(wind, &r);

			std::cout << "Window width: " << r.right - r.left << 
				" window height : " << r.bottom - r.top << '\n';
		}

		// set window pos
		if (GetAsyncKeyState('R') & 1)
		{
			std::cout << "Pressed R\n";
			// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-setwindowpos
			SetWindowPos(wind, 0, 100, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		}

		// set window size
		if(GetAsyncKeyState('T') & 1)
		{
			std::cout << "Pressed T\n";

			SetWindowPos(wind, 0, 0, 0, 300, 300, SWP_NOMOVE | SWP_NOZORDER);
		}

		// set window on top
		if (GetAsyncKeyState('Y') & 1)
		{
			std::cout << "Pressed Y\n";

			SetWindowPos(wind, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // HWND_TOP : 윈도우를 z 순서의 가장 높은 곳에 배치
		}

		// set windwo as topmost
		if (GetAsyncKeyState('U') & 1)
		{
			std::cout << "pressed U\n";
			SetWindowPos(wind, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // HWND_TOPMOST : topmost가 아닌 윈도우들 위에 배치, 비활성화 상태에서도 유지
		}
	}
}