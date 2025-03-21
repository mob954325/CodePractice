#include "ConsoleRenderer.h"
#include "GameLogic.h"

void GameLogic::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void GameLogic::Update()
{
}

void GameLogic::Render()
{
	ConsoleRenderer::ScreenClear();
	GameLogic::RenderProcess();
	ConsoleRenderer::ScreenFlipping();
}

void GameLogic::RenderProcess()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "잘있어라 세상아", FG_BLACK);
}