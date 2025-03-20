#pragma once
#define SCENECOUNT 3

enum Scene
{
	MENU = 0,
	PLAY,
	END
};

namespace GameControl
{
	void Initialize();
	void Update();
	void Render();

	void InputProcess();
}