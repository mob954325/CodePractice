#pragma once

enum Scene
{
	MENU = 0,
	PLAY,
	END,
	SCENECOUNT
};

namespace GameControl
{
	void Initialize();
	void Update();
	void Render();

	void SceneChangeByName(Scene sceneName);
	void SceneChangeToNext();
}