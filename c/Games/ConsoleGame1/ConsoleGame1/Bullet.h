#pragma once
#include "ConsoleRenderer.h"
#include "List.h"
#include "Time.h"
#include "DataTypes.h"

namespace Bullet
{
	void CreateBullet(COORD spawnPos, Tag tag);
	void BulletUpdate();
	void BulletRender();
	void OnSceneEnd();
}