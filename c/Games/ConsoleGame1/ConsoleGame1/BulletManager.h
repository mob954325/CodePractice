#pragma once
#include "ConsoleRenderer.h"
#include "List.h"
#include "Time.h"
#include "DataTypes.h"
#include "Vector.h"

namespace BulletManager
{
	void BulletManagerInitialize();
	void CreateBullet(Vector2 spawnPos, float speed, Tag tag);
	void BulletUpdate();
	void BulletRender();
}