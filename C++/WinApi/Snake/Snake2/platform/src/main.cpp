#include <iostream>
#include <Windows.h>
#include <input.h>
#include <gameLogic.h>
#include <chrono>
#include <gameWindowBuffer.h>
#include <snake.h>

struct WindowStuff 
{
	bool isRunning = true;
	Input input;

	BITMAPINFO bitmapInfo = {};
	GameWindowBuffer gameWindowBuffer = {};

	Board board = {};
};

WindowStuff windowStuff;

LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
	LRESULT rez = 0;

	bool pressed = 0;

	switch (msg)
	{
		case WM_SIZE:
			resetWindowBuffer(&windowStuff.gameWindowBuffer, &windowStuff.bitmapInfo, wind);
		break;

		// window close
		case WM_CLOSE:
			windowStuff.isRunning = false;
		break;

		// Input
		case WM_SYSKEYDOWN:
		case WM_KEYDOWN:
		pressed = 1;
		case WM_SYSKEYUP:
		case WM_KEYUP:
		{
			for (int i = 0; i < Button::BUTTONS_COUNT; i++)
			{
				if (wp == Button::buttonValues[i])
				{
					pressEventButton(windowStuff.input.keyBoard[i], pressed);

					SnakeCell* head = windowStuff.board.snakeCells[0];
					// check wasd
					if (windowStuff.input.keyBoard[Button::W].pressed)
					{
						//moveSnake(windowStuff.board, { head->coord.X, (short)(head->coord.Y - 1) });
						head->dir = SnakeCell::Direction::Up;
					}
					if (windowStuff.input.keyBoard[Button::A].pressed)
					{
						//moveSnake(windowStuff.board, { (short)(head->coord.X - 1), head->coord.Y });
						head->dir = SnakeCell::Direction::Left;
					}
					if (windowStuff.input.keyBoard[Button::S].pressed)
					{
						//moveSnake(windowStuff.board, { head->coord.X,(short)(head->coord.Y + 1) });
						head->dir = SnakeCell::Direction::Down;
					}
					if (windowStuff.input.keyBoard[Button::D].pressed)
					{
						//moveSnake(windowStuff.board, { (short)(head->coord.X + 1), head->coord.Y });
						head->dir = SnakeCell::Direction::Right;
					}
				}
			}
		}
		
		rez = DefWindowProc(wind, msg, wp, lp);
		break;

		// focus
		case WM_SETFOCUS:
			windowStuff.input.focused = true;
		break;
		case WM_KILLFOCUS:
			windowStuff.input.focused = false;
		break;

		// draw
		case WM_PAINT:
		{
			PAINTSTRUCT Paint;
			HDC DeviceContext = BeginPaint(wind, &Paint);

			HDC hdc = GetDC(wind);

			StretchDIBits(hdc,
				0, 0, windowStuff.gameWindowBuffer.w, windowStuff.gameWindowBuffer.h,
				0, 0, windowStuff.gameWindowBuffer.w, windowStuff.gameWindowBuffer.h,
				windowStuff.gameWindowBuffer.memory,
				&windowStuff.bitmapInfo,
				DIB_RGB_COLORS,
				SRCCOPY
			);

			ReleaseDC(wind, hdc);

			EndPaint(wind, &Paint);
		}
		break;

		default:
			rez = DefWindowProc(wind, msg, wp, lp);
		break;
	}

	return rez;
}

float timer = 0;
float maxTimer = 1;
int main()
{
#pragma region create window stuff
	WNDCLASS wc = { sizeof(WNDCLASS) };

	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hInstance = GetModuleHandle(0);
	wc.lpszClassName = "WindowClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;		//refresh window on resize
	wc.lpfnWndProc = windProc;

	if (!RegisterClass(&wc)) { return 0; };

	HWND wind = CreateWindowA(
		wc.lpszClassName,
		"Snake",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//default window
		CW_USEDEFAULT,						//position x
		CW_USEDEFAULT,						//position y
		CW_USEDEFAULT,						//size x
		CW_USEDEFAULT,						//size y
		0, 0, GetModuleHandle(0), 0			//other uninteresting stuff
	);

	//we create the window buffer
	resetWindowBuffer(&windowStuff.gameWindowBuffer, &windowStuff.bitmapInfo, wind);
#pragma endregion
#pragma region create board

	if (!initBoard(windowStuff.board, 10, 10, 50, { 10/2, 10/2 })) { return 1; };
	drawBoard(windowStuff.board, windowStuff.gameWindowBuffer);

#pragma endregion

	if (!initGame()) { return 1; };

	auto stop = std::chrono::high_resolution_clock::now();

	while (windowStuff.isRunning)
	{
#pragma region deltaTime

		auto start = std::chrono::high_resolution_clock::now();

		float deltaTime = (std::chrono::duration_cast<std::chrono::microseconds>(start - stop)).count() / 1000000.0f;
		stop = std::chrono::high_resolution_clock::now();

		//we don't want delta time to drop too low, like let's say under 5 fps. you can set this to whatever you want
		//or remove it but I recomand keeping it
		float augmentedDeltaTime = deltaTime;
		if (augmentedDeltaTime > 1.f / 5) { augmentedDeltaTime = 1.f / 5; }

#pragma endregion

#pragma region get message
		MSG msg = {};
		while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0) // remove all messages from queue
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);	// call our window callback
		}
#pragma endregion

		RECT rect = {};
		GetWindowRect(wind, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		if (!updateGamePerFrame(augmentedDeltaTime, width, height, windowStuff.input, windowStuff.gameWindowBuffer))
		{
			windowStuff.isRunning = false;
		}
		else
		{
			if (timer > maxTimer)
			{
				moveSnake(windowStuff.board);
				timer = 0;
			}
			drawSnake(windowStuff.board, windowStuff.gameWindowBuffer);
			drawBoard(windowStuff.board, windowStuff.gameWindowBuffer);
		}

		inputAfter(windowStuff.input);

		timer += augmentedDeltaTime;

#pragma region draw
		SendMessage(wind, WM_PAINT, 0, 0); // 그리기 요청
#pragma endregion

	} // while end

	exitGame();

	return 0;
}