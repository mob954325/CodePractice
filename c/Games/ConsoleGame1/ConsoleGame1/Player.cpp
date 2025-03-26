#include "Player.h"

#include "DebugUtility.h"

namespace Player
{
	// Player
	struct ScreenElement* playerInfo;
	COORD nextCoord = { 0,0 };

	float inputTimer = 0.0f;
	float maxInputTime = 0.08f;

	int PlayerInit()
	{
		playerInfo = GameManager::GetPlayerInfo();
		nextCoord = { 2,2 };

		return 1;
	}

	void Move()
	{
		inputTimer += Time::GetDeltaTime();

		if (inputTimer < maxInputTime) return;

		nextCoord = playerInfo->coords;
		if (Input::IsKeyDown('W'))
		{
			nextCoord.Y -= playerInfo->speed;
			//__PrintDebugLog("Up\n");
		}
		if (Input::IsKeyDown('S'))
		{
			nextCoord.Y += playerInfo->speed;
			//__PrintDebugLog("Down\n");
		}
		if (Input::IsKeyDown('A'))
		{
			nextCoord.X -= playerInfo->speed;
			//__PrintDebugLog("Back\n");
		}
		if (Input::IsKeyDown('D'))
		{
			nextCoord.X += playerInfo->speed;
			//__PrintDebugLog("Front\n");
		}

		if (IsVaildPosition(nextCoord) == 1)
		{
			playerInfo->coords = nextCoord;
		}

		inputTimer = 0; // timer Reset
	}

	void Shoot()
	{
		if (Input::IsKeyPressed('F'))
		{
			BulletManager::CreateBullet(playerInfo->coords, 1, Tag::PlayerObject);
			__PrintDebugLog("Shoot\n");
		}
	}

	void RenderPlayer()
	{
		ConsoleRenderer::ScreenDrawChar(playerInfo->coords.X, playerInfo->coords.Y, 'P', FG_GREEN);
	}

	void RenderPlayerPosition()
	{
		char xChar[10];
		char yChar[10];

		_itoa_s(playerInfo->coords.X, xChar, 10);
		_itoa_s(playerInfo->coords.Y, yChar, 10);

		ConsoleRenderer::ScreenDrawString(30, 0, xChar, FG_GREEN);
		ConsoleRenderer::ScreenDrawString(30, 2, yChar, FG_GREEN);
	}

	int IsVaildPosition(COORD pos)
	{
		if (pos.X < 0 || pos.X > MAXWIDTH || pos.Y < 0 || pos.Y > MAXHEIGHT) return 0;

		return 1;
	}
}