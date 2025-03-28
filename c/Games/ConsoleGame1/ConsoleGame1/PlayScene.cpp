#include "PlayScene.h"

void TestVictory();

void PlayScene::Initialize()
{
	GameManager::GameManagerInitialize();
	EnemyManager::EnemyManagerInitialize();
	BulletManager::BulletManagerInitialize();
	PlayScreenUI::PlayScreenUIInitialize();
	Time::InitTime();

	Player::PlayerInit();

	GameManager::SetGameState(GameState::Playing);
	// 임시 적 스폰
	//EnemyManager::SpawnEnemyAtPosition({20,5}); 
}

void PlayScene::Update()
{
	if (GameManager::CheckIsPlayerDead() == 0) // 플레이어 사망확인
	{
		GameManager::SetGameResultState(GameResultState::Lose);
		GameManager::SetGameState(GameState::PlayEnd);
	}
	if (GameManager::GetGameState() == GameState::PlayEnd) return;

	EnemyManager::SetEnemySpanwer(1.2f);
	BulletManager::BulletUpdate();

	EnemyManager::EnemyUpdate();

	Player::PlayerUpdate();
	TestVictory();
}

void PlayScene::Render()
{
	if (GameManager::GetGameState() == GameState::PlayEnd)
	{
		GameManager::ShowGameResult();
		//return;
	}

	BulletManager::BulletRender();
	EnemyManager::EnemyRender();
	Player::RenderPlayer();

	PlayScreenUI::RenderUI();
}

void TestVictory()
{
	if (Input::IsKeyPressed(VK_SPACE))
	{
		GameManager::SetGameState(GameState::PlayEnd);
	}
}