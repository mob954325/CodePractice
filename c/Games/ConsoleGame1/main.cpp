#include "GameLogic.h"

int main()
{
	GameLogic gl;
	gl.Initialize();
	while (1)
	{
		gl.Update();
		gl.Render();
	}
}