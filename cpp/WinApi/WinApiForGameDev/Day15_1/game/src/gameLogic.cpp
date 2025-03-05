#include <gameLogic.h>
#include <iostream>
#include <Windows.h>

struct GameData
{
	int fpsCounter = 0;
	float timer = 0;
};
static GameData data;

bool InitGamePlay() // 게임 초기화
{
	data = {};
	return true;
}

bool GamePlayFrame(float deltaTime, int w, int h, GamwWindowBuffer& gameWindowBuffer)
{
	// fps counter
	data.fpsCounter += 1;
	data.timer += deltaTime;

	if (data.timer > 1)
	{
		data.timer > 1;
		std::cout << "FPS : " << data.fpsCounter << "\n";
		data.fpsCounter = 0;
	}

	// clear screen
	gameWindowBuffer.clear();

	// draw rectangle
	for(int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			gameWindowBuffer.drawAtSafe(i, j, 0, 255, 255);
		}

	return true;
}

void CloseGameLogic()
{

}