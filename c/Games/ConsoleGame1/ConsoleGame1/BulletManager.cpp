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

	void CreateBullet(Vector2 spawnPos, float speed, Tag tag)
	{
		ScreenElement bulletData = SetScreenElementValue({0, 0}, { (spawnPos.x + 1), spawnPos.y }, speed, tag);
		AddNode(&BulletList, bulletData);
	}

	void BulletUpdate()
	{
		int bulletCount = NodeCount(BulletList);
		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(BulletList, i);
			if (!currBullet) return;

			// 출력하는 위치에 벗어나면 총알 제거
			if ((currBullet->data.position.x >= MAXWIDTH)
			|| (currBullet->data.position.x <= 0)
			|| (currBullet->data.health <= 0))
			{
				DeleteNode(&currBullet, &BulletList);
				continue;
			}
			currBullet->data.position.x += (currBullet->data.speed * Time::GetDeltaTime());
		}
	}

	void BulletRender()
	{
		int bulletCount = NodeCount(BulletList);
		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(BulletList, i);
			ConsoleRenderer::ScreenDrawChar((int)currBullet->data.position.x, (int)currBullet->data.position.y, 'o', FG_YELLOW);
		}
	}
}