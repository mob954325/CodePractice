#pragma once
#include "DataTypes.h"
#include "List.h"

#define SCORE_SCALE 100

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

	/// <summary>
	/// 오브젝트 크기만큼 점수를 반환하는 함수
	/// </summary>
	/// <returns>크기 * SCORE_SCALE</returns>
	int GetScoreBySize(ScreenElement obj);

	/// <summary>
	/// 현재 스코어 받기
	/// </summary>
	/// <returns>현재 누적된 스코어</returns>
	int GetCurrentPlayScore();

	/// <summary>
	/// 스코어 추가하기
	/// </summary>
	/// <param name="value">추가할 스코어 값</param>
	void AddPlayScore(int value);

	// 게임 매니저 게임 상태 값을 가져오는 함수
	GameState GetGameState();

	// 게임 상태 설정 함수
	void SetGameState(GameState state);

	void CehckVectory();
}