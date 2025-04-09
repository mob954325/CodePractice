#include "base.h"
#include "component1.h"
#include "component2.h"
#include "Object.h"
#include "Player.h"

int main()
{
	Player* player = new Player();
	component1* a = new component1();
	component2* b = new component2();

	component1* dd = nullptr;

	player->AddComponent<component1>(new component1());
}