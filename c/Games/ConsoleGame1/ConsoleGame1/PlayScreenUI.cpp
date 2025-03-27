#include "PlayScreenUI.h"

namespace PlayScreenUI
{
	ScreenElement* playerInfo;	

	void PlayScreenUIInitialize()
	{
		playerInfo = GameManager::GetPlayerInfo();
	}

	void RenderUI()
	{
		RanderGameFrame(); //-> 프레임 드랍 심함
		RenderPlayerHp();
		RenderPlayTime();
		RanderScore();
	}

	void RanderGameFrame()
	{
		for (int y = 0; y <= MAXHEIGHT; y++)
		{
			// 위, 아래
			if (y == 0 || y == MAXHEIGHT)
			{
				for (int x = 0; x <= MAXWIDTH; x++)
				{
					ConsoleRenderer::ScreenDrawChar(x, y, '#', FG_WHITE);
				}
			}
			// 중간
			else
			{
				ConsoleRenderer::ScreenDrawChar(0, y, '#', FG_WHITE);
				ConsoleRenderer::ScreenDrawChar(MAXWIDTH, y, '#', FG_WHITE);
			}
		}
	}

	void RenderPlayerHp()
	{
		int gap = 5;

		// 체력 숫자
		int currHealth = playerInfo->health;
		char hChar[10];
		_itoa_s(currHealth, hChar, 10);
		ConsoleRenderer::ScreenDrawString(0 , MAXHEIGHT + gap, hChar, FG_GREEN); 

		// 체력 그림
		for (int i = 0; i < currHealth; i++)
		{
			ConsoleRenderer::ScreenDrawChar(i + gap , MAXHEIGHT + gap, 'I', FG_BLUE_DARK);
		}
	}

	void RenderPlayTime()
	{
		int positionX = 0;

		int elapsedTime = Time::GetTotalTime();
		int min = elapsedTime / 60;
		int sec = elapsedTime % 60;

		char minBuffer[5];
		char secBuffer[3];
		_itoa_s(min, minBuffer, 10);
		_itoa_s(sec, secBuffer, 10);

		ConsoleRenderer::ScreenDrawString(positionX, MAXHEIGHT + 3, minBuffer, FG_BLUE);
		ConsoleRenderer::ScreenDrawString(positionX + 2, MAXHEIGHT + 3, " : ", FG_BLUE);
		ConsoleRenderer::ScreenDrawString(positionX + 4, MAXHEIGHT + 3, secBuffer, FG_BLUE);
	}

	void RanderScore()
	{
	}
}