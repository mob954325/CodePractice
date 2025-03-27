#pragma once
#include "ConsoleRenderer.h"
#include "DataTypes.h"
#include "List.h"
#include "Time.h"
#include "Vector.h"

#include <random>

namespace EnemyManager
{
	void EnemyManagerInitialize();
	void EnemyUpdate();
	void EnemyRender();

	void SpawnEnemyAtRandomPosition();
	void SpawnEnemyAtPosition(Vector2 spawnPosition);
	void SetEnemySpanwer(float spawnDelay);
}