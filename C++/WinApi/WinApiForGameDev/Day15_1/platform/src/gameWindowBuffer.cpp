#include <gameWindowBuffer.h>

void resetWindowBuffer(GamwWindowBuffer* gameWindowBuffer, BITMAPINFO* bitmapInfo, HWND wind)
{
	RECT rect = {};
	GetClientRect(wind, &rect); // 창 rect값 가져오기
	gameWindowBuffer->h = rect.bottom;
	gameWindowBuffer->w = rect.right;

	if (gameWindowBuffer->memory)
	{
		VirtualFree(gameWindowBuffer->memory, 0, MEM_RELEASE);
	}
	
	gameWindowBuffer->memory =
		(unsigned char*)VirtualAlloc(0, 4 * gameWindowBuffer->w * gameWindowBuffer->h,
			MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	// https://learn.microsoft.com/ko-kr/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
	bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);		// 바이트 수 지정
	bitmapInfo->bmiHeader.biWidth = gameWindowBuffer->w;
	bitmapInfo->bmiHeader.biHeight = -gameWindowBuffer->h; // 왼쪽 상단 원점인 하양식 DIB
	bitmapInfo->bmiHeader.biPlanes = 1;
	bitmapInfo->bmiHeader.biBitCount = 32;
	bitmapInfo->bmiHeader.biCompression = BI_RGB;
}