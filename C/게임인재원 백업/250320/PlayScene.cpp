#include "PlayScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Game.h"

#include <iostream>

void PlayScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void PlayScene::Update()
{
	if (Input::IsKeyReleased(VK_SPACE)) GameControl::SceneChangeToNext();
}

void PlayScene::Render()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "«√∑π¿Ã", FG_PINK_DARK);
}