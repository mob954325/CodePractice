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

	WINDOWINFO wInfo{sizeof(WINDOWINFO)};
	SetWindowPos(wind, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);

	RECT r = {};
	GetWindowRect(wind, &r);
	int width = r.right - r.left;
	int height = r.bottom - r.top;

	// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-getcursorpos
	POINT pCursor {}; // 커서의 화면 좌표를 수신하는 POINT 구조체

	LONG minDistance = 20;

	while (true)
	{
		if (GetAsyncKeyState('Q') & 1)
		{
			std::cout << "Program Exit\n";
			break;
		}

		if (GetCursorPos(&pCursor))
		{
			if (GetWindowInfo(wind, &wInfo))
			{
				if (pCursor.x > wInfo.rcWindow.left - minDistance && pCursor.x < wInfo.rcWindow.left + width + minDistance &&
					pCursor.y > wInfo.rcWindow.top - minDistance && pCursor.y < wInfo.rcWindow.top + height + minDistance)
				{
					int leftToCursor = wInfo.rcWindow.left - pCursor.x;
					int RightToCursor = pCursor.x - (wInfo.rcWindow.left + width);
					int TopToCursor = wInfo.rcWindow.top - pCursor.y;
					int BottomToCursor = pCursor.y - (wInfo.rcWindow.top + height);

					if (leftToCursor > 0 && leftToCursor < minDistance) // 왼쪽 체크
					{
						SetWindowPos(wind, HWND_TOPMOST, wInfo.rcWindow.left + leftToCursor, wInfo.rcWindow.top, 0, 0, SWP_NOSIZE);
					}
					if (RightToCursor > 0 && RightToCursor < minDistance) // 오른쪽 체크
					{
						SetWindowPos(wind, HWND_TOPMOST, wInfo.rcWindow.left - RightToCursor, wInfo.rcWindow.top, 0, 0, SWP_NOSIZE);
					}
					if (TopToCursor > 0 && TopToCursor < minDistance) // 위 체크
					{
						SetWindowPos(wind, HWND_TOPMOST, wInfo.rcWindow.left, wInfo.rcWindow.top + TopToCursor, 0, 0, SWP_NOSIZE);
					}
					if (BottomToCursor > 0 && BottomToCursor < minDistance) // 아래 체크
					{
						SetWindowPos(wind, HWND_TOPMOST, wInfo.rcWindow.left, wInfo.rcWindow.top - BottomToCursor, 0, 0, SWP_NOSIZE);
					}
					//std::cout << leftToCursor << " | " << RightToCursor << " | " << TopToCursor << " | " <<  BottomToCursor <<"\n";
				}
			}
			else
			{
				std::cout << GetLastError() << '\n';
			}
		}
		else
		{
			std::cout << GetLastError() << '\n';
		}

		if (GetAsyncKeyState('A') & 1)
		{
		}
	}
}