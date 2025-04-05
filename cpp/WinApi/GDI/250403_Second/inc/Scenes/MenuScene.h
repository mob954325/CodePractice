#pragma once
#include <stdio.h>
#include <windows.h>

#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")

#include "../../inc/Time.h"
#pragma comment(lib, "./lib/Time.lib")

#include "../../inc/Input.h"
#pragma comment(lib, "./lib/Input.lib")

namespace MenuScene
{
	void Initialize(HWND hwnd, HDC frontBufferDC, HDC backBufferDC);
	void Update();
	void Render();
	void Uninitialize();
}