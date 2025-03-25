#pragma once
#include <Windows.h>

#define MAXWIDTH 128
#define MAXHEIGHT 32

namespace Player
{
	int PlayerInit();

	void Move();
	void Shoot();
	void ShootRender(); // TODO : 나중에 소스파일 따로 추가

	void RenderPlayer();

	void RenderPlayerPosition();

	// 존재할 수 있는 공간이면 1 아니면 2;
	int IsVaildPosition(COORD pos);
}