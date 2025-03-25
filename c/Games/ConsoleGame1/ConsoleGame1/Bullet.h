#pragma once
#include "ConsoleRenderer.h"
#include "List.h"
#include "Time.h"
#include "DataTypes.h"

// 총알 생성
// 총알 랜더링
// 총알 위치 업데이트
namespace Bullet
{
	void CreateBullet(COORD spawnPos, Tag tag);
	void BulletUpdate();
	void BulletRender();
	void OnSceneEnd();
}