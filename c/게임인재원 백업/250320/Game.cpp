#pragma once
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

#include <iostream>
#include <windows.h>

enum Scene SceneCurrent = Scene::MENU;
enum Scene SceneNext = Scene::MENU;

LARGE_INTEGER freq, curr, prev;
float deltaTime = 0, timeElapsed = 0;

int isKeyPressed = 0;

void EndingFinish();

void GameControl::Initialize()
{
	QueryPerformanceFrequency(&freq);	// 초당 tick수 가져오기
	prev = freq;	

	MenuScene::Initialize(); // 메뉴초기화 실행
}

void GameControl::Update()
{
	QueryPerformanceCounter(&curr);
	deltaTime = static_cast<float>(curr.QuadPart - prev.QuadPart) / freq.QuadPart;
	timeElapsed += deltaTime;
	prev = curr;

	// 씬 전환
	if (SceneCurrent != SceneNext)
	{
		SceneCurrent = SceneNext;
		timeElapsed = 0.0f;
		// 전환 시 초기화
		switch (SceneCurrent)
		{
		case MENU:
			MenuScene::Initialize();
			break;
		case PLAY:
			PlayScene::Initialize();
			break;
		case END:
			EndScene::Initialize();
			break;
		default:
			break;
		}
	}

	if (SceneCurrent == Scene::END)
	{
		EndingFinish();
	}
}

void GameControl::InputProcess()
{
	if (isKeyPressed == 0 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		SceneNext = (Scene)((SceneCurrent + 1) % SCENECOUNT);
		isKeyPressed = 1;
	}
	else if(!GetAsyncKeyState(VK_SPACE))
	{
		isKeyPressed = 0;
	}
}

void GameControl::Render()
{
	// 씬 출력
	switch (SceneCurrent)
	{
	case MENU:
		MenuScene::Update();
		MenuScene::Render();
		break;
	case PLAY:
		PlayScene::Update();
		PlayScene::Render();
		break;
	case END:
		EndScene::Update();
		EndScene::Render();
		break;
	}
}

void EndingFinish()
{
	if (timeElapsed > 5.0f)
	{
		SceneNext = Scene::MENU;
	}
}

// add
// 엔딩 10초후 메인메뉴