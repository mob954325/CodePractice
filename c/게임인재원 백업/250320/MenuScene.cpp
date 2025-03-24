#include "MenuScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Game.h"

void MenuScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void MenuScene::Update()
{
	if (Input::IsKeyReleased(VK_SPACE)) GameControl::SceneChangeToNext();
}

void MenuScene::Render()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "���θ޴�", FG_PINK_DARK);
}