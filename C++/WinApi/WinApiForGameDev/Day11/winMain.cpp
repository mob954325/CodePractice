#include <iostream>
#include <thread>
#include <Windows.h>

// 실행하는지 확인하는 구조체
struct WindowStuff 
{
	bool running = true;
};

WindowStuff windowStuff;

LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
	// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nc-winuser-wndproc
	LRESULT rez = 0;

	switch (msg) // msg = 시스템 제공 메세지
	{
		// if the window is closed we want to handle that case and singal that to our program
	case WM_CLOSE: // 창 닫기
		windowStuff.running = false; // 
		break;
	
	default:
		// there are many messages that we didn't treat so we want to call the default window callback for those
		rez = DefWindowProc(wind, msg, wp, lp);
		break;
	}

	return rez;
}

//this is the function that will process all of the windows' messages.
int main()
{
	// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/ns-winuser-wndclassa
	WNDCLASS wc = { sizeof(WNDCLASS) }; // 창 클래스 특성 구조체

	wc.hCursor = LoadCursor(0, IDC_CROSS);	// 윈도우에서 커서를 가져온다.
	wc.hInstance = GetModuleHandle(0);		// 프로그램 인스턴스
	wc.lpszClassName = "EpicWindowClass";		
	wc.style = CS_HREDRAW | CS_VREDRAW;		// refresh window on resize
	wc.lpfnWndProc = windProc;				// pass our callback function

	if (!RegisterClass(&wc)) { return 0; };

	HWND wind = CreateWindowA(
		wc.lpszClassName,
		"We have a Window!",				// window title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	// default window
		CW_USEDEFAULT,						// position x
		CW_USEDEFAULT,						// position y
		CW_USEDEFAULT,						// size x
		CW_USEDEFAULT,						// size y
		0, 0, GetModuleHandle(0), 0			// other uninteresting sutff
	);

	while (windowStuff.running) 
	{
		MSG msg = {};

		//https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-peekmessagea
		while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0) // remove all mesage from queue
		{
			TranslateMessage(&msg); // 다음 쓰래드가 PeekMessage가 호출될 때 읽을 쓰래드의 메세지
			DispatchMessage(&msg);	// call our window callback
		}

		// game code and other stuff
	}// 윈도우 창 while문
}

//https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues
// window는 윈도우에서 일어날 수 있는 일을 대기열(queue)에 저장하고 처리한다.
// ex> 입력, 사이즈 줄이기 등등
// 그리고 큐에서 해당 이벤트를 읽고 콜백(callBack)을 사용하여 해당 이벤트를 어떻게 처리할지 결정한다.
// 그러므로 윈도우에서 지속적으로 이벤트를 받고 어떻게 처리할 지 지시해야한다.
// 그렇지 않으면 윈도우의 이벤트 큐는 지속적으로 쌓이고 무한루프에 갇히게 된다.
// 그러면 시스템에서 창을 종료할 수 있는 옵션을 제공할 것이다. (응용프로그램 응답없음)