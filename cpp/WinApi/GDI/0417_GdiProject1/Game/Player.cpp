#include "Player.h"
#include "../GDIEngineLib/GameTime.h"
#include "../GDIEngineLib/Input.h"

Player::~Player()
{
	spriteRenderer[0]->DeleteImage();
	printf("Player 소멸자 호출"); // 임시
}

void Player::Initialize()
{
	// 스프라이트 데이터 생성
	spriteRenderer[0] = AddComponent<SpriteRenderer>();

	// 그외 컴포넌트 생성
	collider = AddComponent<Collider>();

	spriteRenderer[0]->GetImage(L"./Resource/Player/Idle-Sheet.png");
	spriteRenderer[0]->GetImageInfo(L"Idle", L"./Resource/Player/animSize.csv");

	animationGameTimer = 0.0f;
	maxAnimationGameTime = 0.1f;

	speed = 350.0f;

	// 안내 로그
	printf("플레이어 상태 변경 : 스페이스바\n");
	printf("플레이어 움직임 : 화살표 방향키\n");
}

void Player::Update()
{

	animationGameTimer += g_GameTime.GetDeltaTime();
	if (animationGameTimer > maxAnimationGameTime)
	{
		animationGameTimer = 0.0f;

		spriteRenderer[playerState]->currFrame++;
		spriteRenderer[playerState]->currFrame %= spriteRenderer[playerState]->imageFrameCount;
	}

	if (g_Input.IsKeyPressed(VK_SPACE))
	{
		playerState++;
		playerState %= 3;

		switch (playerState)
		{
		case 0:
			printf("플레이어 대기\n");
			break;
		default:
			break;
		}

	}

	moveDirection = Vector2(0.0f, 0.0f);

	if (g_Input.IsKeyDown(VK_DOWN))
	{
		moveDirection = Vector2(moveDirection.x, 1.0f);
	}
	if (g_Input.IsKeyDown(VK_UP))
	{
		moveDirection = Vector2(moveDirection.x, -1.0f);
	}
	if (g_Input.IsKeyDown(VK_LEFT))
	{
		moveDirection = Vector2(-1.0f, moveDirection.y);
	}

	if (g_Input.IsKeyDown(VK_RIGHT))
	{
		moveDirection = Vector2(1.0f, moveDirection.y);
	}

	transform->Translate(moveDirection.x * speed * g_GameTime.GetDeltaTime(), moveDirection.y);
	collider->UpdateValue(this);
}

void Player::Render()
{
	if (graphics != nullptr)
	{
		spriteRenderer[playerState]->DrawImage(graphics, (int)transform->position.x, (int)transform->position.y);
	}
}

// Event ----------------------------------------------------------------------------------------------------------------

void Player::OnColliderOverlap(GameObject* other)
{
	// 충돌 내용
}

void Player::OnColliderExit(GameObject* other)
{
}