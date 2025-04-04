#include "Renderer.h"

namespace Renderer
{
	void Initialize()
	{
		g_FrontBufferDC = GetDC(hwnd); //윈도우 클라이언트 영역의 DeviceContext얻기
		g_BackBufferDC = CreateCompatibleDC(g_FrontBufferDC); // 호환되는 DeviceContext 생성
		g_BackBufferBitmap = CreateCompatibleBitmap(g_FrontBufferDC, g_width, g_height); // 메모리 영역생성
		SelectObject(g_BackBufferDC, g_BackBufferBitmap); // MemDC의 메모리영역 지정

		// GDI+ 초기화
		ULONG_PTR g_GdiPlusToken;
		Gdiplus::GdiplusStartupInput gsi;
		Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
		Gdiplus::Graphics* g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(g_BackBufferDC);
	}

	void BeginDraw()
	{
	}

	void EndDraw()
	{
	}

	void Uninitialize()
	{
	}
}