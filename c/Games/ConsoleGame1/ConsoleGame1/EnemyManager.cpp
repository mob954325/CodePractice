#include "EnemyManager.h"

#include "BulletManager.h"
#include "DebugUtility.h"
#include "GameManager.h"

namespace EnemyManager
{
	Node*& EnemyList = GameManager::GetEnemyList();

	float enemyUpdateTimer = 0.0f;
	float maxEnemyUpdateTime = 0.1f;

	float spawnTimer = 0.0f;

	float enemyShootTimer = 0.0f;
	float maxEnemyShootTime = 0.3f;

	void EnemyManagerInitialize()
	{
		EnemyList = GameManager::GetEnemyList();
	}

	void EnemyUpdate()
	{
		enemyUpdateTimer += Time::GetDeltaTime();
		if (enemyUpdateTimer < maxEnemyUpdateTime) return;

		int enemyCount = NodeCount(EnemyList);
		for (int i = 0; i < enemyCount; i++)
		{
			Node* currEnemy = FindNode(EnemyList, i);

			// 체력이 없거나 출력하는 위치에 벗어나면 적 제거
			if ((currEnemy->data.coords.X == 0)
			|| (currEnemy->data.health <= 0))
			{
				DeleteNode(&currEnemy, &EnemyList);
				continue;
			}

			currEnemy->data.coords.X; // 임시
			//currEnemy->data.coords.Y++;
		}

		enemyUpdateTimer = 0.0f;
	}

	void EnemyShoot()
	{
		enemyShootTimer += Time::GetDeltaTime();

		if (enemyShootTimer < maxEnemyShootTime) return;

		int enemyCount = NodeCount(EnemyList);
		for (int i = 0; i < enemyCount; i++)
		{
			Node* currEnemy = FindNode(EnemyList, i);
			
			BulletManager::CreateBullet({ (short)(currEnemy->data.coords.X - 3),currEnemy->data.coords.Y }, -1, Tag::EnemyObject);
			__PrintDebugLog("Enemy Shoot\n");
		}

		enemyShootTimer = 0;
	}

	void EnemyRender()
	{
		int enemyCount = NodeCount(EnemyList);
		for (int i = 0; i < enemyCount; i++)
		{
			Node* currEnemy = FindNode(EnemyList, i);
			ConsoleRenderer::ScreenDrawChar(currEnemy->data.coords.X, currEnemy->data.coords.Y, 'E', FG_RED);
		}
	}

	// 적 스폰 ==================================================================================
	
	void SpawnEnemy()
	{
		byte spawnPositionX = rand() % ENEMY_SPAWN_AREA_WIDTH;
		byte spawnPositionY = rand() % ENEMY_SPAWN_AREA_HEIGHT;

		// TODO : 랜덤시드 변경 코드 넣기
		ScreenElement enemyData = SetScreenElementValue(1, { (byte)(spawnPositionX + MAXWIDTH), spawnPositionY }, -1, Tag::EnemyObject);
		AddNode(&EnemyList, enemyData);
	}

	void SpawnEnemyAtPosition(COORD spawnPosition)
	{
		ScreenElement enemyData = SetScreenElementValue(1, spawnPosition, -1, Tag::EnemyObject);
		AddNode(&EnemyList, enemyData);
	}


	void SetEnemySpanwer(float spawnDelay)
	{
		spawnTimer += Time::GetDeltaTime();
		if (spawnTimer < spawnDelay) return;

		SpawnEnemy();
		DebugLog("Enemy Spawned!!!\n");

		spawnTimer = 0.0f;
	}
}