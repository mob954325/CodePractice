#include "PlayScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLogic.h"
#include "Player.h"

void changeScene2();

void PlayScene::Initialize()
{
	ConsoleRenderer::ScreenInit();
	Player::PlayerInit();
}

void PlayScene::Update()
{
	Player::Move();
	Player::Shoot();
}

void PlayScene::Render()
{
	ConsoleRenderer::ScreenDrawString(50, 0, "Play", BG_GREEN);
	Player::RenderPlayer();
	Player::RenderPlayerPosition();
	changeScene2();
}

void changeScene2()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		GameLogic::SceneChangeToNext();
	}
}