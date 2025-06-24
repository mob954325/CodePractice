#include <iostream>
#include <vector>
#include <functional>
#include "Player.h"
#include "HpComponent.h"
#include "Action.h"

using namespace std;

int main()
{
	Player* player = new Player();
	player->OnStart();
	HpComponent* hpComp = new HpComponent();
	hpComp->FindPlayer(*player);
	hpComp->Start();

	player->OnHit(2);
	hpComp->Show();
}