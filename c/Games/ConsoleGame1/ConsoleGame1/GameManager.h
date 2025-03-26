#pragma once
#include "DataTypes.h"
#include "List.h"

namespace GameManager
{
	void GameManagerInitialize();
	void OnPlaySceneEnd();

	Node*& GetBulletList();
	Node*& GetEnemyList();
	//void ClearGameBufferState();
	//void UpdateGameBufferState(Node* head);
}