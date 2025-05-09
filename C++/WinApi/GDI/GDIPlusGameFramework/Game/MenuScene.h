﻿#pragma once
#include "framework.h"
#include "../GDIEngineLib/Scene.h"

class MenuScene : public Scene
{
public:
	void Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC) override;
	void PhysicsUpdate() override;
	void Update() override;
	void Render() override;
	void Exit() override { Clear(); Gdiplus::GdiplusShutdown(gdiPlusToken); };

protected:
	HWND hwnd;
	HDC FrontBufferDC;    // 앞면 DC
	HDC BackBufferDC;    // 뒷면 DC

	ULONG_PTR gdiPlusToken = 0;
	Gdiplus::GdiplusStartupInput gsi = {};
	Gdiplus::Graphics* graphics = {};
};

