#include "MenuScene.h"
#include "ConsoleRenderer.h"

void MenuScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void MenuScene::Update()
{
}

void MenuScene::Render()
{
	ConsoleRenderer::ScreenClear();
	ConsoleRenderer::ScreenDrawString(0, 0, "메인메뉴", FG_PINK_DARK);
	ConsoleRenderer::ScreenFlipping();
}
 