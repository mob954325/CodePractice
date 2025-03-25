#include "GameManager.h"

#include "DebugUtility.h"

namespace GameManager
{
	// 여기에 리스트 관리
	ObjectNode* BulletList = NULL;
	ObjectNode* EnemyList = NULL;

	Tag gameBufferState[MAXHEIGHT][MAXWIDTH];

	void GameManagerInitialize()
	{
		// 초기화
	}

	void OnPlaySceneEnd()
	{
		FreeAllNode(BulletList);
		FreeAllNode(EnemyList);
	}

	Node*& GetBulldetList()
	{
		return BulletList;
	}
	Node*& GetEnemyList()
	{
		return EnemyList;
	}
}