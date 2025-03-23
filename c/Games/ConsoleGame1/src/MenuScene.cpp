#include "MenuScene.h"

void MenuScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void MenuScene::Update()
{

}

int testPos = 50;
int maxTime = 1000;
int timer = 0;

void MenuScene::Render()
{
	if(testPos == 0)ConsoleRenderer::ScreenDrawChar(0, 20, 'a', FG_RED | BG_PINK);
	else ConsoleRenderer::ScreenDrawChar(0, 20, 'a', FG_RED);

	if (timer > maxTime)
	{
		timer = 0;
		testPos--;
	}
	ConsoleRenderer::ScreenDrawChar(testPos + 1, 20, ' ', BG_BLACK);
	ConsoleRenderer::ScreenDrawChar(testPos, 20, ' ', BG_PINK);
	char aa[10000];
	_itoa_s((int)testPos, aa, 10);
	ConsoleRenderer::ScreenDrawString(0, 2, aa, FG_RED);

	char curr[10000];
	_itoa_s((int)timer, curr, 10);
	ConsoleRenderer::ScreenDrawString(0, 0, curr, FG_RED);
	timer++;

	ConsoleRenderer::ScreenDrawString(0, 0, "아 또 한글 안되네 ", FG_RED);
}