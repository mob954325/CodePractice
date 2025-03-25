#pragma once
#include "DataTypes.h"
#include "List.h"

namespace GameManager
{
	void GameManagerInitialize();

	void ClearGameBufferState();
	void UpdateGameBufferState(Node* head);
}