#include <iostream>
#include <Windows.h>
#include <input.h> // 해당 프로젝트에 정의된 해더파일

struct WindowStuff 
{
	bool running = true;
	Input input;
};

WindowStuff windowStuff;

//this is the function that will process all of the windows' messages.
LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
	LRESULT rez = 0; // 윈도우 알림 메세지 값

	bool pressed = 0;

	switch (msg)
	{
		//if the window is closed we want to handle that case and signal that to our program
	case WM_CLOSE:
		windowStuff.running = false;
	break;

	// 키 입력 알림
	case WM_SYSKEYDOWN: // 키 누름
	case WM_KEYDOWN:
		pressed = 1;
	case WM_SYSKEYUP:
	case WM_KEYUP:
	{
		for (int i = 0; i < Button::BUTTONS_COUNT; i++)
		{
			if (wp == Button::buttonValues[i]) // wp : 해당 파라미터에서 키입력을 받음
			{
				processEventButton(windowStuff.input.keyBoard[i], pressed);
			}
		}

		// so altf4 works
		rez = DefWindowProc(wind, msg, wp, lp);
	}break;

	case WM_SETFOCUS: // 키보드 포커스 알림 (키보드 입력 알림)
		windowStuff.input.focused = true;
	break;

	case WM_KILLFOCUS: // 키보드 포커스 잃음
		windowStuff.input.focused = false;
	break;

	default:
		//there are many messages that we didn't treat so we want to call the default window callback for those...
		rez = DefWindowProc(wind, msg, wp, lp); // 그 외 defualt 알림 처리
	break;
	}

	return rez;
}

int main()
{
	WNDCLASS wc = { sizeof(WNDCLASS) };

	wc.hCursor = LoadCursor(0, IDC_ARROW);	// so we have a cursor for our window
	wc.hInstance = GetModuleHandle(0);		// program instance
	wc.lpszClassName = "EpicWindowClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;		// refresh window on resize
	wc.lpfnWndProc = windProc;				// pass our callback function

	if (!RegisterClass(&wc)) { return 0; };

	HWND wind = CreateWindowA(
		wc.lpszClassName,
		"We have a Window!",				//window title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//default window
		CW_USEDEFAULT,						//position x
		CW_USEDEFAULT,						//position y
		CW_USEDEFAULT,						//size x
		CW_USEDEFAULT,						//size y
		0, 0, GetModuleHandle(0), 0			//other uninteresting stuff
	);

	while (windowStuff.running)
	{
		MSG msg = {};
		while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0) //remove all mesages from queue
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (!windowStuff.input.focused)
		{
			resetInput(windowStuff.input);
		}

		// game code and other stuff

		if (windowStuff.input.keyBoard[Button::A].pressed)
		{
			std::cout << "Pressed!\n";
		}

		//std::cout << (int)windowStuff.input.keyBoard[Button::A].held << "\n";

		//std::cout << (int)windowStuff.input.focused << "\n";

		if (windowStuff.input.keyBoard[Button::A].released)
		{
			std::cout << "Released!\n";
		}

		processInputAfter(windowStuff.input);
	}

	return 0;
}

// 키 입력 스크립트 
// 고려해야할 오류 : 버튼을 계속 누를 때 (윈도우 환경중 입력을 벗어나도 지속적으로 입력하는 설정이 있음)
//				   버튼 땜을 영원히 알리지 않을 때 ( 경우 : 누른 상태로 창 포커스 벗어나기)