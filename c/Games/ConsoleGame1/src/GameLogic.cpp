#include "GameLogic.h"
#include "MenuScene.h"

enum Scene SceneCurrent = Scene::MENU;
enum Scene SceneNext = Scene::MENU;

void GameLogic::Initialize()
{
	ConsoleRenderer::ScreenInit();
}

void GameLogic::Update()
{
	// 씬 전환
	if (SceneCurrent != SceneNext)
	{
		SceneCurrent = SceneNext;
		// 전환 시 초기화
		switch (SceneCurrent)
		{
		case MENU:
			MenuScene::Initialize();
			break;
		case PLAY:
			//PlayScene::Initialize();
			break;
		case END:
			//EndScene::Initialize();
			break;
		default:
			break;
		}
	}

	switch (SceneCurrent)
	{
	case MENU:
		MenuScene::Update();
		break;
	case PLAY:
		//PlayScene::Update();
		break;
	case END:
		//EndScene::Update();
		break;
	}

	// 업데이트
}

void GameLogic::Render()
{
	ConsoleRenderer::ScreenClear();
	// 씬 출력
	switch (SceneCurrent)
	{
	case MENU:
		MenuScene::Render();
		break;
	case PLAY:
		//PlayScene::Render();
		break;
	case END:
		//EndScene::Render();
		break;
	}
	ConsoleRenderer::ScreenFlipping();
}