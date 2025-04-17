#pragma once
#include "../GDIEngineLib/Scene.h"

class MenuScene : public Scene
{
	void Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC) override;
	void PhysicsUpdate() override;
	void Update() override;
	void Render() override;
	void Exit() override { Clear(); };
};

