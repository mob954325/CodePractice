#include "DataTypes.h"

ScreenElement SetScreenElementValue(Vector2 objSize, Vector2 vec, float speed, Tag tag)
{
	ScreenElement obj;
	obj.scale = objSize;
	obj.position = { vec.x, vec.y };
	obj.tag = tag;
	obj.speed = speed;

	return obj;
}

ScreenElement SetScreenElementValue(Vector2 objSize, int maxHealth, Vector2 vec, float speed, Tag tag)
{
	ScreenElement obj;
	obj.scale = objSize;
	obj.health = maxHealth;
	obj.position = { vec.x, vec.y };
	obj.tag = tag;
	obj.speed = speed;

	return obj;
}

int GetScreenPositionByRatio(int type, float value)
{
	if (type == 0) // 가로
	{
		return (int)(MAXWIDTH * value);
	}
	else if (type == 1) // 세로
	{
		return (int)(MAXHEIGHT * value);
	}

	return 0; // 잘못된 파라미터 값
}
