﻿#include "Enemy.h"
#include "../GDIEngineLib/GameTime.h"
#include "../GDIEngineLib/Input.h"

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

	transform->width = 28;
	transform->height = 28;

	collider->bound = { 0, (LONG)transform->height, (LONG)transform->width, 0 };
	collider->UpdateValue(this);
}

void Enemy::Update()
{
	if (shouldBeDeleted) return;

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
	if (shouldBeDeleted) return;

	if (graphics != nullptr)
	{
		spriteRenderer->DrawImage(graphics, (int)transform->position.x, (int)transform->position.y);
	}
}

void Enemy::OnColliderOverlap(GameObject* other)
{
	if (shouldBeDeleted) return;
}

void Enemy::OnColliderExit(GameObject* other)
{
	if (shouldBeDeleted) return;
}