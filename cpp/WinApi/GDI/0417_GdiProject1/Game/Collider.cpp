#include "Collider.h"

Collider::Collider()
{
	bound = {};
}

Collider::~Collider()
{
}

void Collider::UpdateValue(GameObject* object)
{
	bound.left = object->transform->position.x;
	bound.right = object->transform->position.x + object->transform->width;

	bound.bottom = object->transform->position.y;
	bound.top = object->transform->position.y + object->transform->height;
}

bool Collider::IsOverlap(Collider* objectA, Collider* objectB)
{
	return objectA->bound.left < objectB->bound.right && objectA->bound.right > objectB->bound.left &&
		objectA->bound.bottom < objectB->bound.top && objectA->bound.top > objectB->bound.bottom;
}