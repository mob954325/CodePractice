#include "MenuScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLogic.h"

void changeScene();

void MenuScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void MenuScene::Update()
{
	changeScene();
}

void MenuScene::Render()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "MainMenu", FG_PINK_DARK);
}

void changeScene()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		GameLogic::SceneChangeToNext();
	}
}
 