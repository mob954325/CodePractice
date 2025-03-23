//#define _CRTDBG_MAP_ALLOC
#include "GameLogic.h"
#include "Input.h"

#include <stdio.h>
#include <crtdbg.h>

int main()
{
	// 종료시 메모리릭 정보 자동 출력 설정
#ifdef _CRTDBG_MAP_ALLOC
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	GameLogic::Initialize();

	while (1)
	{
		Input::Update();
		GameLogic::Update();
		GameLogic::Render();
	}

#ifdef _CRTDBG_MAP_ALLOC
	_CrtDumpMemoryLeaks();  // 호출 시 메모리 릭 정보 출력 
#endif
}