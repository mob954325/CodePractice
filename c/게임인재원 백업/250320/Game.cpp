#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

#include <iostream>
#include <windows.h>

enum Scene SceneCurrent = Scene::MENU;
enum Scene SceneNext = Scene::MENU;

void CheckSceneChange();

void GameControl::Initialize()
{
	MenuScene::Initialize(); // �޴��ʱ�ȭ ����
}

void GameControl::Update()
{
	CheckSceneChange();

	// ������Ʈ
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

void GameControl::Render()
{
	ConsoleRenderer::ScreenClear();
	// �� ���
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
/// �� ��ȯ Ȯ�� �Լ�
/// </summary>
void CheckSceneChange()
{
	// �� ��ȯ
	if (SceneCurrent != SceneNext)
	{
		SceneCurrent = SceneNext;
		// ��ȯ �� �ʱ�ȭ
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

void GameControl::SceneChangeByName(Scene sceneName)
{
	SceneNext = sceneName;
}

void GameControl::SceneChangeToNext()
{
	SceneNext = (Scene)((SceneCurrent + 1) % Scene::SCENECOUNT);
}