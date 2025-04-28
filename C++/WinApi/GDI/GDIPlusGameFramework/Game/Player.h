#pragma once
#include "framework.h"
#include "../GDIEngineLib/GameObject.h"
#include "SpriteRenderer.h"
#include "Collider.h"

class Player : public GameObject
{
public:
	Player(Gdiplus::Graphics* g) : graphics(g) { Initialize(); }
	~Player();
	void Initialize() override;
	void Update() override;
	void Render() override;

	// Event
	void OnColliderOverlap(GameObject* other) override;
	void OnColliderExit(GameObject* other) override;

protected:
	Gdiplus::Graphics* graphics = {};
	SpriteRenderer* spriteRenderer[1];
	Collider* collider = {};
	Vector2 moveDirection = {};

	// state
	int playerState = 0; //
	float speed;		 // 플레이어 이동 속도

	// time
	float animationGameTimer;
	float maxAnimationGameTime;
};

