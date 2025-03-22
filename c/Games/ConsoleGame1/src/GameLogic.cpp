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
	ConsoleRenderer::ScreenDrawWString(0, 0, L"인간을 구성하는건 무엇인가 ?", FG_RED);
	ConsoleRenderer::ScreenDrawWString(0, 0, L"가나다라마바사아자차카나파하asdfasdfsadfasdf?", FG_RED);
}