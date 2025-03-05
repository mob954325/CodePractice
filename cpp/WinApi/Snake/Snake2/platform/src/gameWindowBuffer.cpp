#include <gameWindowBuffer.h>

void resetWindowBuffer(GameWindowBuffer* gameWindowBuffer, BITMAPINFO* bitmapInfo, HWND wind)
{
	RECT rect = {};
	GetClientRect(wind, &rect);			// 윈도우창에서 창기준 위치값
	gameWindowBuffer->h = rect.bottom;	// 세로
	gameWindowBuffer->w = rect.right;	// 가로

	if (gameWindowBuffer->memory)
	{
		VirtualFree(gameWindowBuffer->memory, 0, MEM_RELEASE);
	}

	gameWindowBuffer->memory =
		(unsigned char*)VirtualAlloc(0, 4 * gameWindowBuffer->w * gameWindowBuffer->h,
			MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);		// 바이트 수 지정
	bitmapInfo->bmiHeader.biWidth = gameWindowBuffer->w;	// 너비
	bitmapInfo->bmiHeader.biHeight = -gameWindowBuffer->h;	// 높이
	bitmapInfo->bmiHeader.biPlanes = 1;						// 평면 수? -> 이 값은 1로 지정해야한다
	bitmapInfo->bmiHeader.biBitCount = 32;					// 대상 바이트 평면수
	bitmapInfo->bmiHeader.biCompression = BI_RGB;			// 픽셀당 비트수
}
