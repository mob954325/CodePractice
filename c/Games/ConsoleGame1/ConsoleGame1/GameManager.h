#pragma once
#include "DataTypes.h"
#include "List.h"

enum GameState
{
	BeforeStart = 0,
	Playing,
	PlayEnd,
};

namespace GameManager
{
	void GameManagerInitialize();
	void OnPlaySceneEnd();

	Node*& GetBulletList();
	Node*& GetEnemyList();
	ScreenElement* GetPlayerInfo();

	/// <summary>
	/// 해당 위치가 유효한 위치인지 확인
	/// </summary>
	/// <param name="pos">버퍼 위치</param>
	/// <returns>유효하지 않으면 0, 유효하면 1</returns>
	int CheckVaildPosition(Vector2 pos);

	/// <summary>
	/// 해당 위치가 유효한지 크기와 함께 확인하는 함수
	/// </summary>
	/// <param name="pos">버퍼 위치</param>
	/// <param name="scale">버퍼 크기</param>
	/// <returns>유효하지 않으면 0, 유효하면 1</returns>
	int CheckVaildPosition(Vector2 pos, Vector2 scale);
}