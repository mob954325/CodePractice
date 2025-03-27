#include "Player.h"

#include "DebugUtility.h"

namespace Player
{
	// 멤버 함수
	void Move();
	void Shoot();
	void RenderPlayerPosition();

	// Player
	struct ScreenElement* playerInfo;
	enum PlayerState state;
	Vector2 nextVec = { 0,0 };

	float shotTimer = 0;
	float maxShotTimer = PLAYER_SHOTDELAY;

	int PlayerInit()
	{
		playerInfo = GameManager::GetPlayerInfo();
		state = PlayerState::NonImmune;
		nextVec = { 2,2 }; // 임시

		return 1;
	}

	void PlayerUpdate()
	{
		if (playerInfo->health <= 0)
		{
			DebugLog("Player Dead\n");
			ChangePlayerImmnueState(0);
		}

		Move();
		Shoot();
	}

	void Move()
	{
		nextVec = playerInfo->position;
		if (Input::IsKeyDown('W'))
		{
			nextVec.y -= playerInfo->speed * Time::GetDeltaTime();
			//__PrintDebugLog("Up\n");
		}
		if (Input::IsKeyDown('S'))
		{
			nextVec.y += playerInfo->speed * Time::GetDeltaTime();
			//__PrintDebugLog("Down\n");
		}
		if (Input::IsKeyDown('A'))
		{
			nextVec.x -= playerInfo->speed * Time::GetDeltaTime();
			//__PrintDebugLog("Back\n");
		}
		if (Input::IsKeyDown('D'))
		{
			nextVec.x += playerInfo->speed * Time::GetDeltaTime();
			//__PrintDebugLog("Front\n");
		}

		if (GameManager::CheckVaildPosition(nextVec, playerInfo->scale) == 1)
		{
			playerInfo->position = nextVec;
		}
	}

	void Shoot()
	{
		shotTimer += Time::GetDeltaTime();
		if (shotTimer < maxShotTimer) return;

		if (Input::IsKeyDown('F'))
		{
			BulletManager::CreateBullet(playerInfo->position, 20, Tag::PlayerObject);
			__PrintDebugLog("Shoot\n");
		}

		shotTimer = 0;
	}

	void RenderPlayer()
	{
		for (int i = 0; i <= playerInfo->scale.y; i++)
		{
			for (int j = 0; j <= playerInfo->scale.x; j++)
			{
				// 좌측 상단부터 랜더링하기
				int currX = (int)playerInfo->position.x - playerInfo->scale.x / 2 + j;
				int currY = (int)playerInfo->position.y - playerInfo->scale.y / 2 + i;
				if (currX == (int)playerInfo->position.x && currY == (int)playerInfo->position.y)
				{
					ConsoleRenderer::ScreenDrawChar(currX, currY, 'P', FG_RED);
				}
				else
				{
					ConsoleRenderer::ScreenDrawChar(currX, currY, '#', FG_GREEN);
				}
			}
		}

		RenderPlayerPosition();
	}

	void RenderPlayerPosition()
	{
		char xChar[10];
		char yChar[10];

		_itoa_s((int)playerInfo->position.x, xChar, 10);
		_itoa_s((int)playerInfo->position.y, yChar, 10);

		ConsoleRenderer::ScreenDrawString(30, 1, xChar, FG_GREEN);
		ConsoleRenderer::ScreenDrawString(30, 2, yChar, FG_GREEN);
	}

	int CheckPlayerImmune()
	{
		return state == PlayerState::Immune ? 1 : 0;
	}

	void ChangePlayerImmnueState(int value)
	{
		if (value < 0 || value > 1) return; //유효하지 않는 숫자
		state = (PlayerState)value;
	}
}