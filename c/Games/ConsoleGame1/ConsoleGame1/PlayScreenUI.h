#pragma once
#include "ConsoleRenderer.h"
#include "GameManager.h"
#include "DataTypes.h"
#include "Time.h"

namespace PlayScreenUI
{
	void PlayScreenUIInitialize();
	void RenderUI();
	void RanderGameFrame();
	void RenderPlayerHp();
	void RenderPlayTime();
	void RanderScore();
}