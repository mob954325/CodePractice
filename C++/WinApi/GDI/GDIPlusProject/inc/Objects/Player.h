#pragma once
#include "Component/GameObject.h"
#include "Component/SpriteRenderer.h"

#include "Input.h"
#pragma comment(lib, "./lib/Input.lib")

#include "../../inc/GameTime.h"
#pragma comment(lib, "./lib/GameTime.lib")

class Player : GameObject
{
public:
	void Initialize();
	void Update();
	void Render(Gdiplus::Graphics* graphics);
	void Uninitialize();
protected:
	SpriteRenderer spriteRenderer[3];
	int playerState = 0; // idle, turn, hurt

	// time
	float animationGameTimer;
	float maxAnimationGameTime;
};

