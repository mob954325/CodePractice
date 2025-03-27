#define _DEBUG
#include "DebugUtility.h"

#include "Windows.h"
#include "Time.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLoop.h"

//#pragma execution_character_set( "utf-8" )

int wmain() 
{
	system("chcp 65001");

	ENABLE_LEAK_CHECK();
	ConsoleRenderer::ScreenInit();
	Time::InitTime();
	GameLoop::Initialize();

	while (!Input::IsKeyPressed(VK_HOME))
	{
		Time::UpdateTime();
		Input::Update();
		GameLoop::Update();
		GameLoop::Render();

		__CheckFPS();
	};
	
	ConsoleRenderer::ScreenRelease();

	DUMP_LEAKS();
}