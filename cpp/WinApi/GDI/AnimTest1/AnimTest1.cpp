#include <windows.h>
#include <stdio.h>
#include "Time.h"

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

int animState = 0; // idle, x, x; , 3개까지만
int animFrameWidth = 80;

void DrawImageOnScreen(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, Gdiplus::Graphics* graphics)
{
	// setimage attributes

	// Initialize the color matrix.
	// Notice the value 0.8 in row 4, column 4.
	Gdiplus::ColorMatrix colorMatrix = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							   0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
							   0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
							   0.0f, 0.0f, 0.0f, 0.2f, 0.0f,
							   0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	// Create an ImageAttributes object and set its color matrix.
	Gdiplus::ImageAttributes imageAtt;
	imageAtt.SetColorMatrix(&colorMatrix, Gdiplus::ColorMatrixFlagsDefault,
		Gdiplus::ColorAdjustTypeBitmap);

	// draw
	Gdiplus::Rect srcRect(srcX, srcY, srcWitdh, srcHeight); // 소스의 영역
	Gdiplus::Rect destRect(x, y, srcRect.Width, srcRect.Height); // 화면에 그릴 영역

	graphics->DrawImage(bitmap, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel, &imageAtt);
}

void CheckFileLoad(HWND hwnd, Gdiplus::Bitmap* bitmap)
{
	if (bitmap->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(hwnd, L"PNG 파일 로드 실패", L"오류", MB_ICONERROR);
		PostQuitMessage(0);
	}
}

// WindowApi, Console

LPCTSTR g_title = TEXT("Sprite Test");
LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");

int g_width = 1024;
int g_height = 768;

HWND g_hWnd;
HDC g_FrontBufferDC;    // 앞면 DC
HDC g_BackBufferDC;    // 뒷면 DC
HBITMAP g_BackBufferBitmap;

// 콘솔 초기화
void InitConsole()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"윈도우 메시지 콘솔 로그");
	printf("콘솔 로그 시작...\n\n");
}

void UninitConsole()
{
	// 표준 출력 스트림 닫기
	fclose(stdout);
	// 콘솔 해제
	FreeConsole();
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
		{
			animState++;
			animState %= 3;

			switch (animState)
			{
			case 0:
				printf("플레이어 회전\n");
				break;
			case 1:
				printf("플레이어 대기\n");
				break;
			case 2:
				printf("플레이어 피격\n");
				break;
			default:
				break;
			}
		}
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // 콘솔 출력 초기화
	Time::InitTime();

	// 폴더 경로 콘솔 출력
	char szPath[MAX_PATH] = { 0, };
	GetCurrentDirectoryA(MAX_PATH, szPath);
	printf("Current Directory : %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = g_szClassName;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// 기본 커서 모양
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// 기본 아이콘 모양
	RegisterClass(&wc);

	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

	//생성
	HWND hwnd = CreateWindow(
		g_szClassName,
		g_title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	////////Renderer::Initialize
	g_FrontBufferDC = GetDC(hwnd); //윈도우 클라이언트 영역의 DeviceContext얻기
	g_BackBufferDC = CreateCompatibleDC(g_FrontBufferDC); // 호환되는 DeviceContext 생성
	g_BackBufferBitmap = CreateCompatibleBitmap(g_FrontBufferDC, g_width, g_height); // 메모리 영역생성
	SelectObject(g_BackBufferDC, g_BackBufferBitmap); // MemDC의 메모리영역 지정

	// GDI+ 초기화
	ULONG_PTR g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
	Gdiplus::Graphics* g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(g_BackBufferDC);

	// 이미지 로드
	Gdiplus::Bitmap* g_pImageBitMap_Elf = new Gdiplus::Bitmap(L"./Resource/elf32.png");
	Gdiplus::Bitmap* g_pImageBitmap_Turn = new Gdiplus::Bitmap(L"./Resource/run_turnaround_Sheet.png");
	Gdiplus::Bitmap* g_pImageBitmap_Idle = new Gdiplus::Bitmap(L"./Resource/idle_and_alter/Idle_Sheet.png");
	Gdiplus::Bitmap* g_pImageBitmap_Hit = new Gdiplus::Bitmap(L"./Resource/idle_and_alter/Hurt_Sheet.png");

	//UINT width = g_pImageBitmap->GetWidth();
	UINT elfHeight = g_pImageBitMap_Elf->GetHeight();
	UINT elfWidth = g_pImageBitMap_Elf->GetWidth();

	UINT turnBitmapHeight = g_pImageBitmap_Turn->GetHeight();
	UINT idleBitmapHeight = g_pImageBitmap_Idle->GetHeight();
	UINT hitBitmapHeight = g_pImageBitmap_Hit->GetHeight();

	CheckFileLoad(hwnd, g_pImageBitmap_Turn);
	CheckFileLoad(hwnd, g_pImageBitmap_Idle);
	CheckFileLoad(hwnd, g_pImageBitmap_Hit);

	float animationTimer = 0.0f;
	float maxAnimationTime = 0.08f;
	int animFrame = 1;

	MSG msg = {};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Time::UpdateTime(); // 시간 업데이트
		animationTimer += Time::GetDeltaTime();

		// Renderer::BeginDraw()
		PatBlt(g_BackBufferDC, 0, 0, g_width, g_height, BLACKNESS);

		// Render()
		DrawImageOnScreen(0, 50, g_pImageBitMap_Elf, 0, 0, elfWidth, elfHeight, g_pBackBufferGraphics);

		switch (animState)
		{
		case 0:
			DrawImageOnScreen(0, 0, g_pImageBitmap_Turn, animFrameWidth * animFrame, 0, 100, turnBitmapHeight, g_pBackBufferGraphics);
			break;
		case 1:
			DrawImageOnScreen(0, 0, g_pImageBitmap_Idle, animFrameWidth * animFrame, 0, 100, idleBitmapHeight, g_pBackBufferGraphics);
			break;
		case 2:
			DrawImageOnScreen(0, 0, g_pImageBitmap_Hit, animFrameWidth * animFrame, 0, 100, hitBitmapHeight, g_pBackBufferGraphics);
			break;
		default:
			break;
		}
		if (animationTimer > maxAnimationTime)
		{
			animationTimer = 0.0f;
			animFrame++;
			animFrame %= 5;
		}

		// Rederer::EndDraw()
		BitBlt(g_FrontBufferDC, 0, 0, g_width, g_height, g_BackBufferDC, 0, 0, SRCCOPY); // ?
	}

	// Renderer::Uninitialize

	// 비트맵 해제
	delete g_pImageBitmap_Turn;
	delete g_pImageBitmap_Idle;
	delete g_pImageBitmap_Hit;

	delete g_pBackBufferGraphics;
	Gdiplus::GdiplusShutdown(g_GdiPlusToken);

	DeleteObject(g_BackBufferBitmap);
	DeleteDC(g_BackBufferDC);
	ReleaseDC(hwnd, g_FrontBufferDC);
	//////////////////////////////////////////////////////////////////////////

	UninitConsole();  // 콘솔 출력 해제
	return (int)msg.wParam;
}