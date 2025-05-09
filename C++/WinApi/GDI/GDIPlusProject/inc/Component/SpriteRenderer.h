#pragma once

#include <stdio.h>
#include <windows.h>

#include "Manager/GDIPlusManager.h"

class SpriteRenderer
{
public:
	bool GetImage(const wchar_t* path);
	void DrawImage(Gdiplus::Graphics* graphics, int posX, int posY);
	void DeleteImage();
	void GetImageInfo(const wchar_t* infoName, const wchar_t* path);

	int currFrame;					// 현재 이미지 프레임 (GetImage에서 초기화)
	int imageFrameCount;			// 이미지 프레임 개수
	int imageWidth;					// 각 이미지 넓이
	int imageHeight;
protected:
	Gdiplus::Bitmap* imageBitMap;	// 이미지 비트맵
};

