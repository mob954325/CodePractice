#pragma once
#include <windows.h>

enum Tag
{
	None = 0,
	PlayerObject,
	EnemyObject,
};

struct Object
{
	Tag tag = Tag::None;
	// 오브젝트 크기
	int size = 0;
	// 오브젝트 크기만큼의 좌표값
	COORD coords;
};

Object SetObjectValue(int objSize, COORD Coords, Tag tag);