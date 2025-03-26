#include "DataTypes.h"

ScreenElement SetScreenElementValue(int objSize, COORD Coords, float speed, Tag tag)
{
	ScreenElement obj;
	obj.size = objSize;
	obj.coords = Coords;
	obj.tag = tag;
	obj.speed = speed;

	return obj;
}
