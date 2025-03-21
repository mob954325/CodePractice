#pragma once
#include "ConsoleRenderer.h"

class GameLogic
{
public:
	virtual void Initialize();		// 실행 시 초기화
	virtual void Update();			// 매 시간 업데이트할 함수
	void Render();					// 더블 버퍼링 내용 실행

protected:
	virtual void RenderProcess();	// 더블 버퍼링 중 filpping 전 실행할 내용
}; 