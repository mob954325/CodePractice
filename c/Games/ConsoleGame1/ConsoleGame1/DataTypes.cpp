#include "DataTypes.h"

ScreenElement SetScreenElementValue(int objSize, COORD Coords, Tag tag)
{
	ScreenElement obj;
	obj.size = objSize;
	obj.coords = Coords;
	obj.tag = tag;

	return obj;
}