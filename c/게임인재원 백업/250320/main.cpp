#include "Game.h"

int main()
{
	GameControl::Initialize();

	while (1)
	{
		GameControl::InputProcess();
		GameControl::Update();
		GameControl::Render();
	}
}