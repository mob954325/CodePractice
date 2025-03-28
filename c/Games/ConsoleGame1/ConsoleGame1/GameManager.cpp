#include "GameManager.h"

#include "DebugUtility.h"

namespace GameManager
{
	// 여기에 리스트 관리
	ObjectNode* BulletList = NULL;	// 총알 리스트
	ObjectNode* EnemyList = NULL;	// 적 리스트
	ScreenElement playerElement = SetScreenElementValue({2,0}, 20, { MAXWIDTH / 2, MAXHEIGHT / 2 }, 10, Tag::PlayerObject); // 플레이어 정보

	GameState gameState; // 현재 게임 상태
	int playScore = 0;

	void GameManagerInitialize()
	{
		// 초기화
		gameState = GameState::BeforeStart();
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
		if (pos.x - scale.x / 2 < 0 //
		|| pos.x + scale.x / 2 > MAXWIDTH
		|| pos.y - scale.y / 2 < 0 //
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

	GameState GetGameState()
	{
		return gameState;
	}

	void SetGameState(GameState state)
	{
		gameState = state;
	}

	void CehckVectory()
	{
		gameState = GameState::PlayEnd;

		//ConsoleRenderer::ScreenDrawString(posX, posY, "Space Shooting", FG_GREEN);

	}
}