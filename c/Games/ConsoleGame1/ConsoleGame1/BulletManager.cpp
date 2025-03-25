#include "BulletManager.h"

#include "GameManager.h"

namespace BulletManager
{
	Node*& BulletList = GameManager::GetBulldetList();

	float bulletUpdateTimer = 0.0f;
	float maxBulletUpdateTime = 0.04f;
	

	void BulletManagerInitialize()
	{
		BulletList = GameManager::GetBulldetList();
	}

	void CreateBullet(COORD spawnPos, Tag tag)
	{
		ScreenElement bulletData = SetScreenElementValue(1, { (byte)(spawnPos.X + 1),  spawnPos.Y }, tag);
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
			if ((currBullet->data.coords.X == MAXWIDTH)
			|| (currBullet->data.health <= 0))
			{
				DeleteNode(&BulletList, i);
				continue;
			}
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
			ConsoleRenderer::ScreenDrawChar(currBullet->data.coords.X, currBullet->data.coords.Y, 'o', FG_YELLOW);
		}
	}
}