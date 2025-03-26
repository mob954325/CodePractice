#pragma once
#include "ConsoleRenderer.h"
#include "List.h"
#include "Time.h"
#include "DataTypes.h"

namespace BulletManager
{
	void BulletManagerInitialize();
	void CreateBullet(COORD spawnPos, float speed, Tag tag);
	void BulletUpdate();
	void BulletRender();
}