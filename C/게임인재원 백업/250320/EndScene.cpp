#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Game.h"
#include "Time.h"

#include <iostream>

void EndGame();

void EndScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void EndScene::Update()
{
	if(Input::IsKeyReleased(VK_SPACE)) GameControl::SceneChangeToNext();
	EndGame();
}

void EndScene::Render()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "끝", FG_PINK_DARK);
}

/// <summary>
/// 5초 시간 지나면 씬을 메뉴로 변경하는 함수
/// </summary>
void EndGame()
{
	if (Time::GetElapsedTime() > 5.0f)
	{
		GameControl::SceneChangeByName(Scene::MENU);
		//GameControl::SceneChangeToNext();
	}
}