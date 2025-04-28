#include <gameLogic.h>
#include <iostream>
#include <windows.h>

struct GameData
{
	int fpsCounter = 0;
	float timer = 0;
};
static GameData data;
bool initGame()
{
	data = {};
	return true;
}

bool updateGamePerFrame(float deltaTime, 
	int w, int h, Input &input, GameWindowBuffer &gameWindowBuffer)
{
	//fps counter
	//Sleep(1);
	data.fpsCounter += 1;
	data.timer += deltaTime;
	if (data.timer > 1)
	{
		data.timer -= 1;
		std::cout << "FPS: " << data.fpsCounter << '\n';
		data.fpsCounter = 0;
	}

	//clear screen
	gameWindowBuffer.clear();

	return true;
}


void exitGame()
{

}