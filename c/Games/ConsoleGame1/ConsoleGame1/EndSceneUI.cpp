#include "EndSceneUI.h"

namespace EndSceneUI
{
	float inputBlockTimer = 0;
	float maxInputBlockTime = 3;

	void RenderUI()
	{
		inputBlockTimer += Time::GetDeltaTime();

		ShowTotalScore();
		CheckSpaceToMenu();
	}

	void ShowTotalScore()
	{
		int totalScore = GameManager::GetCurrentPlayScore();
		int scoreTextPosX= GetScreenPositionByRatio(0, 0.5);
		int scoreTextPosY = GetScreenPositionByRatio(1, 0.4);
		char scoreBuffer[100];
		
		_itoa_s(totalScore, scoreBuffer, 10);

		ConsoleRenderer::ScreenDrawString(scoreTextPosX - 15, scoreTextPosY + 1, "Score : ", FG_GRAY);
		ConsoleRenderer::ScreenDrawString(scoreTextPosX, scoreTextPosY + 1, scoreBuffer, FG_GRAY);
	}

	void CheckSpaceToMenu()
	{
		if (inputBlockTimer < maxInputBlockTime) return;

		int helpTextPosX = GetScreenPositionByRatio(0, 0.45);
		int helpTextPosY = GetScreenPositionByRatio(1, 0.8);
		ConsoleRenderer::ScreenDrawString(helpTextPosX, helpTextPosY, L"스페이스 눌러서 메뉴로 돌아가기", FG_GREEN);

		if (Input::IsKeyPressed(VK_SPACE))
		{
			GameLoop::SceneChangeToNext();
		}
	}
}