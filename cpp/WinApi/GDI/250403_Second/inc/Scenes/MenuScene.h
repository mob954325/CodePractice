#pragma once
#include "../../WinMain.h"

#include <stdio.h>
#include <windows.h>
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")

namespace MenuScene
{
	void Initialize(HWND hwnd, HDC frontBufferDC, HDC backBufferDC);
	void Update();
	void Render();
	void Uninitialize();
}