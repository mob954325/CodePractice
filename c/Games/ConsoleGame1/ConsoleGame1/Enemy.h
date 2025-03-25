#pragma once
#include "ConsoleRenderer.h"
#include "DataTypes.h"
#include "List.h"
#include "Time.h"

#include <random>

namespace Enemy
{
	void EnemyUpdate();
	void EnemyRender();
	void OnSceneEnd();

	void SpawnEnemy();
	void SpawnEnemyAtPosition(COORD spawnPosition);
	void SetEnemySpanwer(float spawnDelay);
}