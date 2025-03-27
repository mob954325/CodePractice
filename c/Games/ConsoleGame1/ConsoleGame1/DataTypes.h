#pragma once
#include "Vector.h"
#include <windows.h>

#define ENEMY_SPAWN_AREA_WIDTH 5
#define ENEMY_SPAWN_AREA_HEIGHT 21

#define MAXWIDTH 100
#define MAXHEIGHT 24

// TODO : UI를 위한 margin 값 설정하기

enum Tag
{
	None = 0,
	PlayerObject,
	EnemyObject,
};

struct ScreenElement
{
	// 오브젝트 태그
	Tag tag = Tag::None;
	// 오브젝트 크기
	Vector2 scale;
	// 오브젝트 크기만큼의 좌표값
	Vector2 position; 
	// 오브젝트 스피드
	float speed = 0;
	// 체력
	int health = 1;
};

ScreenElement SetScreenElementValue(Vector2 scale, Vector2 vec, float speed, Tag tag);
ScreenElement SetScreenElementValue(Vector2 scale, int maxHealth, Vector2 vec, float speed, Tag tag);
