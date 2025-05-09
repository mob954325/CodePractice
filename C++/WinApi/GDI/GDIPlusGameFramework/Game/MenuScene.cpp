﻿#include "framework.h"
#include "MenuScene.h"
#include "../GDIEngineLib/Input.h"
#include "../GDIEngineLib/SceneManager.h"

#include "TextManager.h"

void MenuScene::Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
{
	this->hwnd = hwnd;
	this->FrontBufferDC = frontBufferDC;	// 앞면 DC
	this->BackBufferDC = backBufferDC;	// 뒷면 DC

	Gdiplus::GdiplusStartup(&gdiPlusToken, &gsi, nullptr);
	this->graphics = Gdiplus::Graphics::FromHDC(BackBufferDC); // null 반환

	g_TextManager.Initialize(this->graphics);
}

void MenuScene::PhysicsUpdate()
{
}

void MenuScene::Update(){

	if (g_Input.IsKeyPressed(VK_SPACE)) g_SceneManager.ChangeScene(1);
}

void MenuScene::Render()
{
	g_TextManager.DrawTextByViewport(L"[ Space Bar ] - Start", 0.5f, 0.7f);
}
