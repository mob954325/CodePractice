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
