#pragma once
#include "framework.h"
#include "../GDIEngineLib/Scene.h"

class MenuScene : public Scene
{
public:
	void Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC) override;
	void PhysicsUpdate() override;
	void Update() override;
	void Render() override;
	void Exit() override { Clear(); Gdiplus::GdiplusShutdown(s_GdiPlusToken); };

protected:
	HWND hwnd;
	HDC FrontBufferDC;    // 앞면 DC
	HDC BackBufferDC;    // 뒷면 DC

	ULONG_PTR s_GdiPlusToken = 0;
	Gdiplus::GdiplusStartupInput s_gsi = {};
	Gdiplus::Graphics* graphics = {};
};

