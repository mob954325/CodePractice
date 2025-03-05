#include <gameLogic.h>
#include <gameWindowBuffer.h>
#include <Windows.h>
#include <chrono>

struct WindowStuff {
	bool running = true;

	BITMAPINFO bitmapInfo = {};
	GamwWindowBuffer gameWindowBuffer = {};
};

WindowStuff windowStuff;

LRESULT WindProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
	LRESULT res = 0;

	switch (msg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT paint;
		HDC DeviceContext = BeginPaint(wind, &paint); // deviceContext 핸들 생성
		HDC hdc = GetDC(wind); // deviceContext 핸들 찾기

		// 지정된 사각형에 색 데이터를 복사
		StretchDIBits(hdc,
			0, 0, windowStuff.gameWindowBuffer.w, windowStuff.gameWindowBuffer.h,
			0, 0, windowStuff.gameWindowBuffer.w, windowStuff.gameWindowBuffer.h,
			windowStuff.gameWindowBuffer.memory,
			&windowStuff.bitmapInfo,
			DIB_RGB_COLORS,
			SRCCOPY);

		ReleaseDC(wind, hdc);	// hdc 해제
		EndPaint(wind, &paint);	// BeginPaint가 검색한 deviceContext 해제
	}
	break;
	default:
		res = DefWindowProc(wind, msg, wp, lp);
	break;
	}

	return res;
}

int main()
{
	WNDCLASS wc = { sizeof(WNDCLASS) };

	wc.hCursor = LoadCursor(0, IDC_ARROW);	//so we have a cursor for our window
	wc.hInstance = GetModuleHandle(0);		//program instance
	wc.lpszClassName = "EpicWindowClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;		//refresh window on resize
	wc.lpfnWndProc = WindProc;				//pass our callback function

	if (!RegisterClass(&wc)) { return 0; };

	HWND wind = CreateWindowA(
		wc.lpszClassName,
		"Test Draw!!!",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		0, 0, GetModuleHandle(0), 0 // ..
	);

	resetWindowBuffer(&windowStuff.gameWindowBuffer, &windowStuff.bitmapInfo, wind);

	if (!InitGamePlay()) return 1;

	auto stop = std::chrono::high_resolution_clock::now(); //??

	while (windowStuff.running)
	{
#pragma region deltaTime
		auto start = std::chrono::high_resolution_clock::now();
		
		float deltaTime = (std::chrono::duration_cast<std::chrono::milliseconds>(start - stop)).count() / 1000000.0f;
		stop = std::chrono::high_resolution_clock::now();

		//we don't want delta time to drop too low, like let's say under 5 fps. you can set this to whatever you want
//or remove it but I recomand keeping it
		float augmentedDeltaTime = deltaTime;
		if (augmentedDeltaTime > 1.f / 5) { augmentedDeltaTime = 1.f / 5; }
#pragma endregion

#pragma region get message
		MSG msg = {};
		while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0) // remove all message from queue
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg); // call our window callback
		}
#pragma endregion

		RECT rect = {};
		GetWindowRect(wind, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		if (!GamePlayFrame(augmentedDeltaTime, width, height, windowStuff.gameWindowBuffer)) // 
		{
			windowStuff.running = false;
		}

#pragma region draw
		SendMessage(wind, WM_PAINT, 0, 0); // 창의 일부 그리도록 요청 메세지 모내기
#pragma endregion

		int a = 0;
	}

	CloseGameLogic();

	return 0;
}