#include "PlayScene.h"

#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLoop.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "Collider.h"

#include "DebugUtility.h"

// 임시 사용 함수
void changeScene2();
void SetInGameTime();

void PlayScene::Initialize()
{
	GameManager::GameManagerInitialize();
	EnemyManager::EnemyManagerInitialize();
	BulletManager::BulletManagerInitialize();

	Player::PlayerInit();

	// 임시 적 스폰
	EnemyManager::SpawnEnemyAtPosition({20,5}); 
}

void PlayScene::Update()
{
	//EnemyManager::SetEnemySpanwer(0.4f);
	BulletManager::BulletUpdate();

	EnemyManager::EnemyUpdate();
	EnemyManager::EnemyShoot();

	Player::Move();
	Player::Shoot();

	changeScene2();
}

void PlayScene::Render()
{
	BulletManager::BulletRender();

	EnemyManager::EnemyRender();

	Player::RenderPlayerPosition();
	Player::RenderPlayer();

	ConsoleRenderer::ScreenDrawString(50, 0, "Play", BG_GREEN);
	SetInGameTime();
}

void changeScene2()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		GameManager::OnPlaySceneEnd();
		GameLoop::SceneChangeToNext();
	}
}

// 임시 시간 랜더링
void SetInGameTime()
{
	int elapsedTime = Time::GetTotalTime();
	int min = elapsedTime / 60;
	int sec = elapsedTime % 60;

	char minBuffer[5];
	char secBuffer[3];
	_itoa_s(min, minBuffer, 10);
	_itoa_s(sec, secBuffer, 10);

	ConsoleRenderer::ScreenDrawString(50, 2, minBuffer, FG_BLUE);
	ConsoleRenderer::ScreenDrawString(53, 2, " : ", FG_BLUE);
	ConsoleRenderer::ScreenDrawString(56, 2, secBuffer, FG_BLUE);
}