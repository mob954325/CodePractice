#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLogic.h"

void changeScene3();

void EndScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void EndScene::Update()
{

}

void EndScene::Render()
{
	ConsoleRenderer::ScreenDrawString(0, 0, "End", FG_PINK_DARK);
	changeScene3();
}

void changeScene3()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		GameLogic::SceneChangeToNext();
	}
}