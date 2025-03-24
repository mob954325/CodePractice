#pragma once
#include <Windows.h>

#define MAXWIDTH 256
#define MAXHEIGHT 256

namespace Player
{
	int PlayerInit();

	void Move();
	void Shoot();

	void RenderPlayer();

	void RenderPlayerPosition();

	// 존재할 수 있는 공간이면 1 아니면 2;
	int IsVaildPosition(COORD pos);
}