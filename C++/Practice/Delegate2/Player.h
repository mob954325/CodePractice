#pragma once
#include "Action.h"

class Player
{
private:
	int hp = 0;
	int maxHp = 10;

public:
	// 생성 : Action<int> OnHpChange;
	Action<int> OnHpChange;

	void OnStart()
	{
		hp = maxHp;
	}

	void OnHit(int damage)
	{
		hp -= damage;
		// 델리게이트 호출 : OnHit.Invoke(hp);
		OnHpChange.Invoke(hp);
	}
};

