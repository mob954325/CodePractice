//#define _CRTDBG_MAP_ALLOC

#include "Windows.h"
#include "Time.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameLogic.h"

int main()
{
	// 종료시 메모리릭 정보 자동 출력 설정
#ifdef _CRTDBG_MAP_ALLOC
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	ConsoleRenderer::ScreenInit();
	Time::InitTime();
	GameLogic::Initialize();

	while (1)
	{
		Time::UpdateTime();
		Input::Update();
		GameLogic::Update();
		GameLogic::Render();
	};

	ConsoleRenderer::ScreenRelease();

#ifdef _CRTDBG_MAP_ALLOC
	_CrtDumpMemoryLeaks();  // 호출 시 메모리 릭 정보 출력 
#endif
}