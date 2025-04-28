#include <gameWindowBuffer.h>

void resetWindowBuffer(GameWindowBuffer* gameWindowBuffer, BITMAPINFO* bitmapInfo, HWND wind)
{
	RECT rect = {};
	GetClientRect(wind, &rect);			// ������â���� â���� ��ġ��
	gameWindowBuffer->h = rect.bottom;	// ����
	gameWindowBuffer->w = rect.right;	// ����

	if (gameWindowBuffer->memory)
	{
		VirtualFree(gameWindowBuffer->memory, 0, MEM_RELEASE);
	}

	gameWindowBuffer->memory =
		(unsigned char*)VirtualAlloc(0, 4 * gameWindowBuffer->w * gameWindowBuffer->h,
			MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);		// ����Ʈ �� ����
	bitmapInfo->bmiHeader.biWidth = gameWindowBuffer->w;	// �ʺ�
	bitmapInfo->bmiHeader.biHeight = -gameWindowBuffer->h;	// ����
	bitmapInfo->bmiHeader.biPlanes = 1;						// ��� ��? -> �� ���� 1�� �����ؾ��Ѵ�
	bitmapInfo->bmiHeader.biBitCount = 32;					// ��� ����Ʈ ����
	bitmapInfo->bmiHeader.biCompression = BI_RGB;			// �ȼ��� ��Ʈ��
}
