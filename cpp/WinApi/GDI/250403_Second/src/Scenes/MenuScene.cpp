#include "../../inc/Scenes/MenuScene.h"

namespace MenuScene
{
#pragma region Method
	void ImagesLoad();
	void ImagesInfoLoad();
	void AnimRender();
	void DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, Gdiplus::Graphics* graphics);	
	void CheckFileLoad(HWND hwnd, Gdiplus::Bitmap* bitmap);
#pragma endregion

#pragma region Field
	HWND g_hwnd;
	HDC g_FrontBufferDC;    // 앞면 DC
	HDC g_BackBufferDC;    // 뒷면 DC

	Gdiplus::Graphics* g_pBackBufferGraphics;

	// 이미지
	Gdiplus::Bitmap* g_pImageBitmap_Turn = {}; 
	Gdiplus::Bitmap* g_pImageBitmap_Idle = {}; 
	Gdiplus::Bitmap* g_pImageBitmap_Hit = {};

	UINT turnBitmapHeight = 0; 
	UINT idleBitmapHeight = 0; 
	UINT hitBitmapHeight = 0;  

	// Animation Values
	int animState = 0; // turn, idle, hit
	int* imageWidth;  // 각 스프라이트 한 칸의 크기
	int* imageFrameCount;  // 각 스프라이트 칸 개수

	float animationGameTimer = 0.0f;
	float maxAnimationGameTime = 0.08f;
	int* animFrame;
	int imageCount = 0;
#pragma endregion


	void Initialize(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
	{
		g_hwnd = hwnd;
		g_FrontBufferDC = frontBufferDC;
		g_BackBufferDC = backBufferDC;

		g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(g_BackBufferDC);

		ImagesLoad();
	}

	void Update()
	{
		animationGameTimer += GameTime::GetDeltaTime();
		if (animationGameTimer > maxAnimationGameTime)
		{
			animationGameTimer = 0.0f;
			for (int i = 0; i < imageCount; i++)
			{
				animFrame[i]++;
				animFrame[i] %= imageFrameCount[i];
			}
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

		free(imageWidth);
		free(imageFrameCount);
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

		// 스프라이트 정보 저장
		ImagesInfoLoad();
	}

	void ImagesInfoLoad()
	{
		FILE* file = {};
		_wfopen_s(&file, L"./Resource/animSize.csv", L"r");
		wchar_t buffer[1024];
		wchar_t* nextbuffer;
		wchar_t* bufferToken;
		wchar_t seps[] = L",\t\n";

		memset(buffer, 0, 1024);

		int* tempWidth = (int*)malloc(1024 * sizeof(int));
		int* tempCount = (int*)malloc(1024 * sizeof(int));
		int tempSize = 0;

		if (file)
		{
			if (fgetws(buffer, 1024, file))
			{
				// BOM 무시
				if ((unsigned char)buffer[0] == 0xEF &&
					(unsigned char)buffer[1] == 0xBB &&
					(unsigned char)buffer[2] == 0xBF)
				{
					memmove(buffer, buffer + 3, (wcslen(buffer + 3) + 1) * sizeof(wchar_t));
				}

				// 데이터 저장
				do
				{
					bufferToken = wcstok_s(buffer, seps, &nextbuffer);
					for (int i = 0; i < 2; i++)
					{
						bufferToken = wcstok_s(NULL, seps, &nextbuffer);
						if (i == 0)
						{
							tempWidth[tempSize] = _wtoi(bufferToken);
						}
						else if (i == 1)
						{
							tempCount[tempSize] = _wtoi(bufferToken);
						}
					}
					tempSize++;

				} while (fgetws(buffer, 1024, file));

				imageFrameCount = (int*)malloc(tempSize * sizeof(int));
				imageWidth = (int*)malloc(tempSize * sizeof(int));
				for (int i = 0; i < tempSize; i++)
				{
					imageFrameCount[i] = tempCount[i];
					imageWidth[i] = tempWidth[i];
				}

				animFrame = (int*)calloc(tempSize, sizeof(int));
				imageCount = tempSize;

				free(tempCount);
				free(tempWidth);
			} // if getws
		}
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
			DrawImage(0, 0, g_pImageBitmap_Turn, imageWidth[0] * animFrame[0], 0, 100, turnBitmapHeight, g_pBackBufferGraphics);
			break;
		case 1:
			DrawImage(0, 0, g_pImageBitmap_Idle, imageWidth[1] * animFrame[1], 0, 90, idleBitmapHeight, g_pBackBufferGraphics);
			break;
		case 2:
			DrawImage(0, 0, g_pImageBitmap_Hit, imageWidth[2] * animFrame[2], 0, 90, hitBitmapHeight, g_pBackBufferGraphics);
			break;
		default:
			break;
		}
	}
}