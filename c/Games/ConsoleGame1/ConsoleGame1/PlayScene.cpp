#include "PlayScene.h"

#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLoop.h"
#include "Player.h"
#include "Bullet.h"

void changeScene2();

void PlayScene::Initialize()
{
	Player::PlayerInit();
}

void PlayScene::Update()
{
	Player::Move();
	Player::Shoot();

	Bullet::BulletUpdate();
}

void PlayScene::Render()
{
	ConsoleRenderer::ScreenDrawString(50, 0, "Play", BG_GREEN);

	Player::RenderPlayer();
	Player::RenderPlayerPosition();

	Bullet::BulletRender();

	changeScene2();
}

void changeScene2()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		Bullet::OnSceneEnd();
		GameLoop::SceneChangeToNext();
	}
}