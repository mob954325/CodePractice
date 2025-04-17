#include "GameApp.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "../GDIEngineLib/SceneManager.h"

void GameApp::Initialize()
{
	__super::Initialize();

	//g_SceneManager.CreateScene<MenuScene>();
	g_SceneManager.CreateScene<PlayScene>();
	//g_SceneManager.CreateScene<EndScene>();

	g_SceneManager.ChangeScene(0); // menu
	//g_SceneManager.ChangeScene(1); // Play
}

void GameApp::Shutdown()
{
	__super::Shutdown();
}