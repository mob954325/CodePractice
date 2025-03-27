#include "Collider.h"

namespace Collider
{
	/// <summary>
	/// 원 범위 충돌 체크 함수
	/// </summary>
	/// <returns>충돌하면 1, 충돌하지 않았으면 0 반환</returns>
	int CheckCircleArea(ScreenElement obj1, ScreenElement obj2);

	/// <summary>
	/// 타원 범위 충돌 체크 함수
	/// </summary>
	/// <returns>충돌하면 1, 충돌하지 않았으면 0 반환</returns>
	int CheckEllipaseArea(ScreenElement obj1, ScreenElement obj2);

	void CheckCollider()
	{
		// 총알이 뭐랑 닿았는지 확인하기
		Node* bulletList = GameManager::GetBulletList();
		Node* enemyList = GameManager::GetEnemyList();
		ScreenElement* player = GameManager::GetPlayerInfo();

		int bulletCount = NodeCount(bulletList);

		for (int i = 0; i < bulletCount; i++)
		{
			Node* currBullet = FindNode(bulletList, i);
			int enemyCount = NodeCount(enemyList);

			if (currBullet->data.tag == Tag::PlayerObject)
			{
				for (int j = 0; j < enemyCount; j++)
				{
					Node* currEnemy = FindNode(enemyList, j);

					// 크기가 {0,0} = 한 칸만 차지하고 있으면
					if (currEnemy->data.scale.x == 0 || currEnemy->data.scale.y == 0)
					{
						if (CheckCircleArea(currBullet->data, currEnemy->data) == 1)
						{
							currBullet->data.health--;
							currEnemy->data.health--;
						}
					}
					else // 나머지
					{
						if (CheckEllipaseArea(currBullet->data, currEnemy->data) == 1)
						{
							currBullet->data.health--;
							currEnemy->data.health--;
						}
					}
				}
			}
			else if (currBullet->data.tag == Tag::EnemyObject)
			{
				// 크기가 {0,0} = 한 칸만 차지하고 있으면
				if (player->scale.x == 0 || player->scale.y == 0)
				{
					if (CheckCircleArea(currBullet->data, *player) == 1)
					{
						player->health--;
						PlayScreenUI::ActivePlayerHitEffect();
						currBullet->data.health--;
					}
				}
				else // 나머지
				{
					if (CheckEllipaseArea(currBullet->data, *player) == 1)
					{
						player->health--;
						PlayScreenUI::ActivePlayerHitEffect();
						currBullet->data.health--;
					}
				}
			}
		}
	}

	int CheckCircleArea(ScreenElement obj1, ScreenElement obj2)
	{
		int radiusSumX = obj1.scale.x + obj2.scale.y;
		int radiusSumY = obj1.scale.x + obj2.scale.y;

		int dx = (int)obj1.position.x - (int)obj2.position.x;
		int dy = (int)obj1.position.y - (int)obj2.position.y;

		int distanceSqur = dx * dx + dy * dy;

		return distanceSqur <= radiusSumX * radiusSumX ? 1 : 0;
	}

	int CheckEllipaseArea(ScreenElement obj1, ScreenElement obj2)
	{
		int radiusSumX = obj1.scale.x + obj2.scale.y;
		int radiusSumY = obj1.scale.x + obj2.scale.y;

		if (radiusSumX == 0 || radiusSumY == 0) return 0; // 0으로 나눌 수 없음

		int dx = (int)obj1.position.x - (int)obj2.position.x;
		int dy = (int)obj1.position.y - (int)obj2.position.y;
		// 타원 크기 적용
		float dxNorm = dx / radiusSumX;
		float dyNorm = dy / radiusSumY;

		int distanceSqur = dxNorm * dxNorm + dyNorm * dyNorm;

		return	distanceSqur < 1.0f ? 1 : 0;
	}

}// checkCollider
