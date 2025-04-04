#include "../../inc/Scenes/MenuScene.h"

namespace MenuScene
{
#pragma region Method
	void ImagesLoad();
	void AnimRender();
	void DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, Gdiplus::Graphics* graphics);	
	void CheckFileLoad(HWND hwnd, Gdiplus::Bitmap* bitmap);
#pragma endregion

#pragma region Field
	HWND g_hwnd;
	HDC g_FrontBufferDC;    // 앞면 DC
	HDC g_BackBufferDC;    // 뒷면 DC
	ULONG_PTR g_GdiPlusToken;

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::Graphics* g_pBackBufferGraphics;

	// 이미지
	Gdiplus::Bitmap* g_pImageBitmap_Turn = {};  //new Gdiplus::Bitmap(L"./Resource/run_turnaround_Sheet.png");
	Gdiplus::Bitmap* g_pImageBitmap_Idle = {};  //new Gdiplus::Bitmap(L"./Resource/idle_and_alter/Idle_Sheet.png");
	Gdiplus::Bitmap* g_pImageBitmap_Hit = {};   //new Gdiplus::Bitmap(L"./Resource/idle_and_alter/Hurt_Sheet.png");

	UINT turnBitmapHeight = 0; //g_pImageBitmap_Turn->GetHeight();
	UINT idleBitmapHeight = 0; //g_pImageBitmap_Idle->GetHeight();
	UINT hitBitmapHeight = 0;  //g_pImageBitmap_Hit->GetHeight();

	// Animation Values
	int animState = 0; // turn, idle, hit
	int animFrameWidth = 80;

	float animationTimer = 0.0f;
	float maxAnimationTime = 0.08f;
	int animFrame = 1;
#pragma endregion


	void Initialize(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
	{
		g_hwnd = hwnd;
		g_FrontBufferDC = frontBufferDC;
		g_BackBufferDC = backBufferDC;

		Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
		g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(g_BackBufferDC);

		ImagesLoad();
	}

	void Update()
	{
		animationTimer += Time::GetDeltaTime();
		if (animationTimer > maxAnimationTime)
		{
			animationTimer = 0.0f;
			animFrame++;
			animFrame %= 5;
		}

		if (Input::IsKeyPressed(VK_SPACE))
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
	}

	void Render()
	{
		AnimRender();
	}

	void Uninitialize()
	{
		// 비트맵 해제
		delete g_pImageBitmap_Turn;
		delete g_pImageBitmap_Idle;
		delete g_pImageBitmap_Hit;

		delete g_pBackBufferGraphics;
		Gdiplus::GdiplusShutdown(g_GdiPlusToken);
	}

	// 정의 =============================================================================================================================
	void ImagesLoad()
	{
		g_pImageBitmap_Turn = new Gdiplus::Bitmap(L"./Resource/run_turnaround_Sheet.png");
		g_pImageBitmap_Idle = new Gdiplus::Bitmap(L"./Resource/Idle_Sheet.png");
		g_pImageBitmap_Hit = new Gdiplus::Bitmap(L"./Resource/Hurt_Sheet.png");

		CheckFileLoad(g_hwnd, g_pImageBitmap_Turn);
		CheckFileLoad(g_hwnd, g_pImageBitmap_Idle);
		CheckFileLoad(g_hwnd, g_pImageBitmap_Hit);

		// 이미지 높이 얻기
		turnBitmapHeight = g_pImageBitmap_Turn->GetHeight();
		idleBitmapHeight = g_pImageBitmap_Idle->GetHeight();
		hitBitmapHeight = g_pImageBitmap_Hit->GetHeight();
	}

	void DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, Gdiplus::Graphics* graphics)
	{
		Gdiplus::Rect srcRect(srcX, srcY, srcWitdh, srcHeight); // 소스의 영역
		Gdiplus::Rect destRect(x, y, srcRect.Width, srcRect.Height); // 화면에 그릴 영역
		graphics->DrawImage(bitmap, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel); // 소스의 일부분만을 그린다. 
	}

	void CheckFileLoad(HWND hwnd, Gdiplus::Bitmap* bitmap)
	{
		if (bitmap->GetLastStatus() != Gdiplus::Ok)
		{
			MessageBox(hwnd, L"PNG 파일 로드 실패", L"오류", MB_ICONERROR);
			PostQuitMessage(0);
		}
	}

	void AnimRender()
	{
		switch (animState)
		{
		case 0:
			DrawImage(0, 0, g_pImageBitmap_Turn, animFrameWidth * animFrame, 0, 100, turnBitmapHeight, g_pBackBufferGraphics);
			break;
		case 1:
			DrawImage(0, 0, g_pImageBitmap_Idle, animFrameWidth * animFrame, 0, 100, idleBitmapHeight, g_pBackBufferGraphics);
			break;
		case 2:
			DrawImage(0, 0, g_pImageBitmap_Hit, animFrameWidth * animFrame, 0, 100, hitBitmapHeight, g_pBackBufferGraphics);
			break;
		default:
			break;
		}
	}
}