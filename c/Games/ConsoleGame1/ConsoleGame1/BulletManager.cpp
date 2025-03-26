#include "BulletManager.h"

#include "GameManager.h"
#include "DebugUtility.h"

namespace BulletManager
{
	Node*& BulletList = GameManager::GetBulletList();

	float bulletUpdateTimer = 0.0f;
	float maxBulletUpdateTime = 0.08f;
	

	void BulletManagerInitialize()
	{
		BulletList = GameManager::GetBulletList();
	}

	void CreateBullet(COORD spawnPos, float speed, Tag tag)
	{
		ScreenElement bulletData = SetScreenElementValue(1, { (byte)(spawnPos.X + 1), spawnPos.Y }, speed, tag);
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

			// 출력하는 위치에 벗어나면 총알 제거
			if ((currBullet->data.coords.X == 20)
			|| (currBullet->data.coords.X == 0)
			|| (currBullet->data.health <= 0))
			{
				DebugLog("bullet delete");
				DeleteNode(&currBullet, &BulletList);
				continue;
			}
			currBullet->data.coords.X += (SHORT)currBullet->data.speed;
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