#pragma once
#include "PlayScene.h"
#include <iostream>
#include "ConsoleRenderer.h"

void PlayScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void PlayScene::Update()
{
}

void PlayScene::Render()
{
	ConsoleRenderer::ScreenClear();
	ConsoleRenderer::ScreenDrawString(0, 0, "«√∑π¿Ã", FG_PINK_DARK);
	ConsoleRenderer::ScreenFlipping();
}