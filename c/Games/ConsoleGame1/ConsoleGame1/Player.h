#pragma once
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "BulletManager.h"
#include "GameManager.h"

#include <Windows.h>

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