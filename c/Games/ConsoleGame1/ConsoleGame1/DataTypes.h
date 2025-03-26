#pragma once
#include <windows.h>

#define ENEMY_SPAWN_AREA_WIDTH 5
#define ENEMY_SPAWN_AREA_HEIGHT 21

#define MAXWIDTH 128
#define MAXHEIGHT 32

enum Tag
{
	None = 0,
	PlayerObject,
	EnemyObject,
};

struct ScreenElement
{
	Tag tag = Tag::None;
	// 오브젝트 크기
	int size = 3;
	// 오브젝트 크기만큼의 좌표값
	COORD coords; // TODO : 실수값을 가지는 벡터로 바꾸기
	// 체력
	int health = 1;
};

ScreenElement SetScreenElementValue(int objSize, COORD Coords, Tag tag);
