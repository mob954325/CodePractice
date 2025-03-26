#include "Collider.h"

namespace Collider
{
	void CheckCollider()
	{
		// 총알이 뭐랑 닿았는지 확인하기
		Node* bulletList = GameManager::GetBulldetList();
		Node* enemyList = GameManager::GetEnemyList();

		int bulletCount = NodeCount(bulletList);

		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(bulletList, i);
			int enemyCount = NodeCount(enemyList);

			for (int j = 0; j < enemyCount; j++)
			{
				Node* currEnemy = FindNode(enemyList, j);
				if ((currBullet->data.coords.X == currEnemy->data.coords.X)
					&& (currBullet->data.coords.Y == currEnemy->data.coords.Y))
				{
					// 총알이랑 위치 겹치는 적
					DebugLog("Enemy Hit\n");

					currBullet->data.health--;
					currEnemy->data.health--;

					// TODO : 사이즈 키우고 원 체크로 바꾸기
					// 1. 두 원의 반지름의 합이 두 원의 원점 사이의 거리보다 크면 충돌
				}
			}
		}
	}
}