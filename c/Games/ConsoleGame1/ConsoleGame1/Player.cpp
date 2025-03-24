#include "ConsoleRenderer.h"
#include "Player.h"
#include "Input.h"
#include "Time.h"

namespace Player
{
	COORD playerCoord = { 0,0 };
	COORD nextCoord = { 0,0 };
	float timer = 0.0f;
	float maxInputTimer = 0.2f;


	int PlayerInit()
	{
		nextCoord = { 0,0 };
		playerCoord = { 0,0 };
		return 1;
	}

	void Move()
	{
		// InputDelay =========================
		timer += Time::GetDeltaTime();
		if (timer < maxInputTimer) return;

		// PlayerMove =========================
		nextCoord = playerCoord;
		if (Input::IsKeyDown('W'))
		{
			playerCoord.Y -= 1;
		}
		if (Input::IsKeyDown('S'))
		{
			playerCoord.Y += 1;
		}
		if (Input::IsKeyDown('A'))
		{
			playerCoord.X -= 1;
		}
		if (Input::IsKeyDown('D'))
		{
			playerCoord.X += 1;
		}

		timer = 0; // timer Reset

		if (IsVaildPosition(nextCoord) == 1)
		{
			playerCoord = nextCoord;
		}
	}

	void Shoot()
	{
		if (Input::IsKeyPressed('F'))
		{
			// 발사
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