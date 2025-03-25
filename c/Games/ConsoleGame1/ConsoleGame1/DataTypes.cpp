#include "DataTypes.h"

Object SetObjectValue(int objSize, COORD Coords, Tag tag)
{
	Object obj;
	obj.size = objSize;
	obj.coords = Coords;
	obj.tag = tag;

	return obj;
}
