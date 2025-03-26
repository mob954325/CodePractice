#include "Player.h"

#include "DebugUtility.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "BulletManager.h"

namespace Player
{
	// Player
	COORD playerCoord = { 0,0 };
	COORD nextCoord = { 0,0 };

	float inputTimer = 0.0f;
	float maxInputTime = 0.08f;

	int PlayerInit()
	{
		nextCoord = { 2,2 };
		playerCoord = { 2,2 };

		return 1;
	}

	void Move()
	{
		inputTimer += Time::GetDeltaTime();

		if (inputTimer < maxInputTime) return;

		nextCoord = playerCoord;
		if (Input::IsKeyDown('W'))
		{
			nextCoord.Y -= 1;
			//__PrintDebugLog("Up\n");
		}
		if (Input::IsKeyDown('S'))
		{
			nextCoord.Y += 1;
			//__PrintDebugLog("Down\n");
		}
		if (Input::IsKeyDown('A'))
		{
			nextCoord.X -= 1;
			//__PrintDebugLog("Back\n");
		}
		if (Input::IsKeyDown('D'))
		{
			nextCoord.X += 1;
			//__PrintDebugLog("Front\n");
		}

		if (IsVaildPosition(nextCoord) == 1)
		{
			playerCoord = nextCoord;
		}

		inputTimer = 0; // timer Reset
	}

	void Shoot()
	{
		if (Input::IsKeyPressed('F'))
		{
			BulletManager::CreateBullet(playerCoord, 1, Tag::PlayerObject);
			__PrintDebugLog("Shoot\n");
		}
	}

	void RenderPlayer()
	{
		ConsoleRenderer::ScreenDrawChar(playerCoord.X, playerCoord.Y, 'P', FG_GREEN);
	}

	void RenderPlayerPosition()
	{
		char xChar[10];
		char yChar[10];

		_itoa_s(playerCoord.X, xChar, 10);
		_itoa_s(playerCoord.Y, yChar, 10);

		ConsoleRenderer::ScreenDrawString(30, 0, xChar, FG_GREEN);
		ConsoleRenderer::ScreenDrawString(30, 2, yChar, FG_GREEN);
	}

	int IsVaildPosition(COORD pos)
	{
		if (pos.X < 0 || pos.X > MAXWIDTH || pos.Y < 0 || pos.Y > MAXHEIGHT) return 0;

		return 1;
	}
}