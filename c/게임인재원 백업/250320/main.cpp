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
//	input, time ��� ������ ��ũ��Ʈ �����ϱ�
// 
// Game.cpp
//  �� ��ȯ�� �� �� �ְ� ����
// 
// ��� ��.cpp
//	���� Ŭ����, �ø����� Game.cpp�� �ű�� ���� ���븸 �����ϱ� 
//
// EndScene.cpp
//	�ð� ��� ������ �ش� ��ũ��Ʈ���� �ð� ����� ����� �����ϰ�
//	Game.cpp�� �ִ� ���� ���� ����