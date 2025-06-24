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
		id1 = player->OnHpChange.Add(std::bind(&HpComponent::ChangeValue, this, std::placeholders::_1));
		id2 = player->OnHpChange.Add(std::bind(&HpComponent::ChangeValue2, this, std::placeholders::_1));

		player->OnHpChange.RemoveByID(id2);

		// id2 = player->OnHpChange += std::bind(&HpComponent::ChangeValue2, this, std::placeholders::_1);
		// id2 = player->OnHpChange += [](int _) { std::cout << "Call lambda expresstion functoin by action class \n"; };
		// player->OnHpChange = std::bind(&HpComponent::EqualOperatorEvent, this);


		//player->OnHpChange += ChangeValue;
	}

	void ChangeValue(int value) 
	{ 
		std::cout << "hp before : " << hp << '\n';
		hp = value; 
		std::cout << "hp after : " << hp << '\n';
		
	}

	void ChangeValue2(int value)
	{
		std::cout << "mp before : " << mp << '\n';
		mp = value;
		std::cout << "mp after : " << mp << '\n';
	}

	void EqualOperatorEvent()
	{
		std::cout << "Call EqualOperatorEvent\n";
	}

	void Show()
	{
		std::cout << id1 << ", " << id2 << '\n';
	}

private:
	Player* player;
	int hp = 10;
	int mp = 111;

	ListenerID id1 = 0;
	ListenerID id2 = 0;
};