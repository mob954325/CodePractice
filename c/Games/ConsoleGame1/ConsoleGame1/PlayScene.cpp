#include "PlayScene.h"

#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLoop.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "GameManager.h"

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

void PlayScene::CheckCollider()
{
	// 총알이 뭐랑 닿았는지 확인하기
	Node* bulletList = GameManager::GetBulldetList();
	Node* enemyList = GameManager::GetEnemyList();

	int bulletCount = NodeCount(bulletList);

	for (int i = 0; i < bulletCount; i++)
	{
		Node* currBullet = FindNode(bulletList, i);
		int enemyCount = NodeCount(enemyList);

		DebugLog("1\n");	
		for (int j = 0; j < enemyCount; j++)
		{
			DebugLog("2\n");
			Node* currEnemy = FindNode(enemyList, j);
			if ((currBullet->data.coords.X == currEnemy->data.coords.X)
				&& (currBullet->data.coords.Y == currEnemy->data.coords.Y))
			{
				// 총알이랑 위치 겹치는 적
				DebugLog("Enemy Hit\n");
				
				currBullet->data.health--;
				currEnemy->data.health--;
			}
		}
	}
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