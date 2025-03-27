#include "GameManager.h"

#include "DebugUtility.h"

namespace GameManager
{
	// 여기에 리스트 관리
	ObjectNode* BulletList = NULL;
	ObjectNode* EnemyList = NULL;
	ScreenElement playerElement = SetScreenElementValue({2,0}, 20, { MAXWIDTH / 2, MAXHEIGHT / 2 }, 10, Tag::PlayerObject);

	Tag gameBufferState[MAXHEIGHT][MAXWIDTH];

	int playScore = 0;

	void GameManagerInitialize()
	{
		// 초기화
		playScore = 0;
	}

	void OnPlaySceneEnd()
	{
		FreeAllNode(&BulletList);
		FreeAllNode(&EnemyList);
	}

	Node*& GetBulletList()
	{
		return BulletList;
	}

	Node*& GetEnemyList()
	{
		return EnemyList;
	}

	ScreenElement* GetPlayerInfo()
	{
		return &playerElement;
	}

	int CheckVaildPosition(Vector2 pos)
	{
		if (pos.x < 0 || pos.x > MAXWIDTH || pos.y < 0 || pos.y > MAXHEIGHT) return 0;

		return 1;
	}

	int CheckVaildPosition(Vector2 pos, Vector2 scale)
	{
		if (pos.x - scale.x / 2 <= 1 //
		|| pos.x + scale.x / 2 > MAXWIDTH
		|| pos.y - scale.y / 2 < 1 //
		|| pos.y + scale.y / 2 > MAXHEIGHT) return 0;

		return 1;
	}

	int GetScoreBySize(ScreenElement obj)
	{
		return obj.scale.x * SCORE_SCALE + obj.scale.y * SCORE_SCALE;
	}

	int GetCurrentPlayScore()
	{
		return playScore;
	}

	void AddPlayScore(int value)
	{
		playScore += value;
	}
}