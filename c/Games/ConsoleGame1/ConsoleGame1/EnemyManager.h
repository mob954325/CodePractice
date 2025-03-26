#pragma once
#include "ConsoleRenderer.h"
#include "DataTypes.h"
#include "List.h"
#include "Time.h"

#include <random>

namespace EnemyManager
{
	void EnemyManagerInitialize();
	void EnemyUpdate();
	void EnemyShoot();
	void EnemyRender();

	void SpawnEnemy();
	void SpawnEnemyAtPosition(COORD spawnPosition);
	void SetEnemySpanwer(float spawnDelay);
}