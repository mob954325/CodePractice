#include "Bullet.h"

namespace Bullet
{
	// Bullet
	ObjectNode* BulletList = NULL;

	float bulletUpdateTimer = 0.0f;
	float maxBulletUpdateTime = 0.1f;
	

	void CreateBullet(COORD spawnPos, Tag tag)
	{
		Object bulletData = SetObjectValue(1, { (byte)(spawnPos.X + 1),  spawnPos.Y }, tag);
		AddNode(&BulletList, bulletData);
	}

	void BulletUpdate()
	{
		bulletUpdateTimer += Time::GetDeltaTime();
		if (bulletUpdateTimer < maxBulletUpdateTime) return;

		int bulletCount = NodeCount(BulletList);
		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(BulletList, i);
			currBullet->data.coords.X++;
		}

		bulletUpdateTimer = 0.0f;
	}

	void BulletRender()
	{
		int bulletCount = NodeCount(BulletList);
		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(BulletList, i);
			ConsoleRenderer::ScreenDrawChar(currBullet->data.coords.X, currBullet->data.coords.Y, 'o', FG_RED);
		}
	}

	void OnSceneEnd()
	{
		FreeAllNode(BulletList);
	}
}