#pragma once
#include "EndScene.h"
#include <iostream>
#include "ConsoleRenderer.h"

void EndScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void EndScene::Update()
{

}

void EndScene::Render()
{
	ConsoleRenderer::ScreenClear();
	ConsoleRenderer::ScreenDrawString(0, 0, "³¡", FG_PINK_DARK);
	ConsoleRenderer::ScreenFlipping();
}