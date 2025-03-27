#include "PlayScene.h"

// 임시 사용 함수
void changeScene2();

void PlayScene::Initialize()
{
	GameManager::GameManagerInitialize();
	EnemyManager::EnemyManagerInitialize();
	BulletManager::BulletManagerInitialize();
	PlayScreenUI::PlayScreenUIInitialize();

	Player::PlayerInit();

	// 임시 적 스폰
	//EnemyManager::SpawnEnemyAtPosition({20,5}); 
}

void PlayScene::Update()
{
	EnemyManager::SetEnemySpanwer(1.2f);
	BulletManager::BulletUpdate();

	EnemyManager::EnemyUpdate();

	Player::PlayerUpdate();

	changeScene2();
}

void PlayScene::Render()
{
	BulletManager::BulletRender();
	EnemyManager::EnemyRender();
	Player::RenderPlayer();

	PlayScreenUI::RenderUI();
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

}