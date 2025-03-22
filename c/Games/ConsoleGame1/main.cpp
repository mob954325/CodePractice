#include "GameLogic.h"
#include <stdio.h>

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