#include "GameLogic.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"

enum Scene SceneCurrent = Scene::MENU;
enum Scene SceneNext = Scene::MENU;

void CheckSceneChange();

void GameLogic::Initialize()
{
	MenuScene::Initialize(); // 메뉴초기화 실행
	ConsoleRenderer::ScreenInit();
}

void GameLogic::Update()
{
	CheckSceneChange();

	// 업데이트
	switch (SceneCurrent)
	{
	case MENU:
		MenuScene::Update();
		break;
	case PLAY:
		PlayScene::Update();
		break;
	case END:
		EndScene::Update();
		break;
	}
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
		PlayScene::Render();
		break;
	case END:
		EndScene::Render();
		break;
	}

	ConsoleRenderer::ScreenFlipping();
}

// === Change Scene Functions

/// <summary>
/// 씬 전환 확인 함수
/// </summary>
void CheckSceneChange()
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
			PlayScene::Initialize();
			break;
		case END:
			EndScene::Initialize();
			break;
		default:
			break;
		}
	}
}

void GameLogic::SceneChangeByName(Scene sceneName)
{
	SceneNext = sceneName;
}

void GameLogic::SceneChangeToNext()
{
	SceneNext = (Scene)((SceneCurrent + 1) % Scene::SCENECOUNT);
}