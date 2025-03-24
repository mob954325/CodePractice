#include "DebugUtility.h"
#include "ConsoleRenderer.h"
#include "Player.h"
#include "Input.h"
#include "Time.h"

namespace Player
{
	COORD playerCoord = { 0,0 };
	COORD nextCoord = { 0,0 };
	Node* BulletList = NULL;

	float timer = 0.0f;
	float maxInputTimer = 0.08f;

	COORD testCoord = { 0,0 };

	int PlayerInit()
	{
		nextCoord = { 2,2 };
		playerCoord = { 2,2 };

		return 1;
	}

	void Move()
	{
		timer += Time::GetDeltaTime();

		if (timer < maxInputTimer) return;
		testCoord.X++; // test

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
			Data spawnCoord;
			spawnCoord.COORD = playerCoord;
			spawnCoord.COORD.X++;

			BulletList = AddNode(BulletList, spawnCoord);
			ConsoleRenderer::ScreenDrawChar(spawnCoord.COORD.X, spawnCoord.COORD.Y, ' ', BG_RED);

			__PrintDebugLog("Shoot\n");
		}
	}
	
	void ShootRender()
	{
		Node* currNode = BulletList;

		if (testCoord.X	 < 20)
		{
			ConsoleRenderer::ScreenDrawChar(testCoord.X, 5, 'o', FG_BLUE);
		}

		//int cnt = 0;
		//while (currNode != NULL)
		//{
		//	COORD* currPos = &currNode->data.COORD;
		//	currPos->X++;
		//	
		//	ConsoleRenderer::ScreenDrawChar(currPos->X, currPos->Y, 'a', BG_RED);

		//	currNode = currNode->next;
		//	cnt++;
		//}
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