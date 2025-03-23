#pragma once
#include "ConsoleRenderer.h"

enum Scene
{
	MENU = 0,
	PLAY,
	END
};

namespace GameLogic
{
	void Initialize();		// 실행 시 초기화
	void Update();			// 매 시간 업데이트할 함수
	void Render();			// 더블 버퍼링 내용 실행
}