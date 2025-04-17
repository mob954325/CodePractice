#include "Enemy.h"
#include "../GDIEngineLib/GameTime.h"
#include "../GDIEngineLib/Input.h"
#include "random"

Enemy::~Enemy()
{
	
}

void Enemy::Initialize()
{
	spriteRenderer = AddComponent<SpriteRenderer>();
	collider = AddComponent<Collider>();	

	spriteRenderer->GetImage(L"./Resource/Enemy/Idle-Sheet.png");
	spriteRenderer->GetImageInfo(L"Idle", L"./Resource/Enemy/animSize.csv");

	animationGameTimer = 0.0f;
	maxAnimationGameTime = 0.1f;

	//transform->position.x = rand() % 700;
	//transform->position.y = rand() % 700;
	transform->position.x = 500;
	transform->position.y = 500;
	transform->width = 50;
	transform->height = 50;

	collider->bound = { 0, (LONG)transform->height, (LONG)transform->width, 0 };
}

void Enemy::Update()
{
	animationGameTimer += g_GameTime.GetDeltaTime();
	if (animationGameTimer > maxAnimationGameTime)
	{
		animationGameTimer = 0.0;
		
		spriteRenderer->currFrame++;
		spriteRenderer->currFrame %= spriteRenderer->imageFrameCount;
	}

	collider->UpdateValue(this);
}
 
void Enemy::Render()
{
	if (graphics != nullptr)
	{
		spriteRenderer->DrawImage(graphics, transform->position.x, transform->position.y);
	}
}

void Enemy::OnColliderOverlap(GameObject* other)
{
}

void Enemy::OnColliderExit(GameObject* other)
{
}