#pragma once
#include <wtypes.h>
#include <windows.h>
#include <stdio.h>

namespace Renderer
{
	void Initialize(HWND hwnd, HDC frontBufferDC, HDC gackBufferDC, int width, int height);
	void BeginDraw();
	void EndDraw();
	void Uninitialize();
}