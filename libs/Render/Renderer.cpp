#include "framework.h"
#include "Renderer.h"

namespace Renderer
{
	HWND g_hwnd = {};
	HBITMAP g_BackBufferBitmap = {};
	HDC g_FrontBufferDC = {};
	HDC g_BackBufferDC = {};

	int g_width = 0;
	int g_height = 0;

	void Initialize(HWND hwnd, int width, int height)
	{
		g_width = width;
		g_height = height;

		g_FrontBufferDC = GetDC(hwnd); //윈도우 클라이언트 영역의 DeviceContext얻기
		g_BackBufferDC = CreateCompatibleDC(g_FrontBufferDC); // 호환되는 DeviceContext 생성
		g_BackBufferBitmap = CreateCompatibleBitmap(g_FrontBufferDC, g_width, g_height); // 메모리 영역생성
		SelectObject(g_BackBufferDC, g_BackBufferBitmap); // MemDC의 메모리영역 지정
	}

	void BeginDraw()
	{
		PatBlt(g_BackBufferDC, 0, 0, g_width, g_height, BLACKNESS);
	}

	void EndDraw()
	{
		BitBlt(g_FrontBufferDC, 0, 0, g_width, g_height, g_BackBufferDC, 0, 0, SRCCOPY);
	}

	void Uninitialize()
	{
		DeleteObject(g_BackBufferBitmap);
		DeleteDC(g_BackBufferDC);
	}

	HDC GetFrontBuffer()
	{
		return g_FrontBufferDC;
	}

	HDC GetBackBuffer()
	{
		return g_BackBufferDC;
	}
}