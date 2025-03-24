#include "Game.h"
#include "Time.h"
#include "Input.h"

int main()
{
	GameControl::Initialize();
	Time::InitTime();
	while (1)
	{
		Input::Update();
		Time::UpdateTime();
		GameControl::Update();
		GameControl::Render();
	}
}


// TODO:
// main.cpp
//	input, time 모듈 적용후 스크립트 수정하기
// 
// Game.cpp
//  씬 전환만 할 수 있게 변경
// 
// 모든 씬.cpp
//	버퍼 클리어, 플립핑을 Game.cpp에 옮기고 랜더 내용만 정의하기 
//
// EndScene.cpp
//	시간 계산 내용을 해당 스크립트에서 시간 모듈을 사용해 정의하고
//	Game.cpp에 있는 정의 내용 제거