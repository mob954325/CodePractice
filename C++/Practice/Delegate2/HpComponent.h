#pragma once
#include "Player.h"

class HpComponent
{
public:
	void FindPlayer(Player& refPlayer)
	{
		player = &refPlayer;
	}

	void Start() 
	{ 
		/* 등록 : player.OnHpChnage += ChangeValue; */ 
		player->OnHpChange.Add(this, std::bind(&HpComponent::ChangeValue, this, std::placeholders::_1));
	}

	void ChangeValue(int value) 
	{ 
		std::cout << "before : " << hp << '\n';
		hp = value; 
		std::cout << "after : " << hp << '\n';
		
	}

private:
	Player* player;
	int hp = 10;
};