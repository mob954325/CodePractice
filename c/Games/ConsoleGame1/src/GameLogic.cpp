#include "ConsoleRenderer.h"
#include "GameLogic.h"

#include <locale.h>

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
	ConsoleRenderer::ScreenDrawString(0, 2, "aaa", FG_RED);
	ConsoleRenderer::ScreenDrawWString(0, 0, L"�ΰ��� �����ϴ°� �����ΰ� ?", FG_RED);
	ConsoleRenderer::ScreenDrawWString(0, 0, L"�����ٶ󸶹ٻ������ī������asdfasdfsadfasdf?", FG_RED);
}