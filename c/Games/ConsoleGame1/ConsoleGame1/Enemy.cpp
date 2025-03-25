#include "Enemy.h"
#include "DebugUtility.h"
#include "GameManager.h"

namespace Enemy
{
	ObjectNode* EnemyList = NULL;

	float enemyUpdateTimer = 0.0f;
	float maxEnemyUpdateTime = 0.1f;
	float spawnTimer = 0.0f;

	void EnemyUpdate()
	{
		enemyUpdateTimer += Time::GetDeltaTime();
		if (enemyUpdateTimer < maxEnemyUpdateTime)return;

		int enemyCount = NodeCount(EnemyList);
		for (int i = 0; i < enemyCount; i++)
		{
			Node* currEnemy = FindNode(EnemyList, i);

			if (currEnemy->data.coords.X == 0) DeleteNode(&EnemyList, i);
			else // 이동
			{
				currEnemy->data.coords.X;
				//currEnemy->data.coords.Y++;
			}
		}

		GameManager::UpdateGameBufferState(EnemyList);
		enemyUpdateTimer = 0.0f;
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

	void OnSceneEnd()
	{
		FreeAllNode(EnemyList);
	}

	// 적 스폰 ==================================================================================
	
	void SpawnEnemy()
	{
		byte spawnPositionX = rand() % ENEMY_SPAWN_AREA_WIDTH;
		byte spawnPositionY = rand() % ENEMY_SPAWN_AREA_HEIGHT;

		// TODO : 랜덤시드 변경 코드 넣기
		Object enemyData = SetObjectValue(1, { (byte)(spawnPositionX + MAXWIDTH), spawnPositionY }, Tag::EnemyObject);
		AddNode(&EnemyList, enemyData);
	}

	void SpawnEnemyAtPosition(COORD spawnPosition)
	{
		Object enemyData = SetObjectValue(1, spawnPosition, Tag::EnemyObject);
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