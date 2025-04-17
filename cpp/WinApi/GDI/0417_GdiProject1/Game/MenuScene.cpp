#include "framework.h"
#include "MenuScene.h"
#include "../GDIEngineLib/Input.h"
#include "../GDIEngineLib/SceneManager.h"

void MenuScene::Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
{
	this->hwnd = hwnd;
	this->FrontBufferDC = frontBufferDC;	// 앞면 DC
	this->BackBufferDC = backBufferDC;	// 뒷면 DC

	Gdiplus::GdiplusStartup(&s_GdiPlusToken, &s_gsi, nullptr);
	this->graphics = Gdiplus::Graphics::FromHDC(BackBufferDC); // null 반환
}

void MenuScene::PhysicsUpdate()
{
}

void MenuScene::Update()
{
	if (g_Input.IsKeyPressed('A')) g_SceneManager.ChangeScene(1);
}

void MenuScene::Render()
{
}
