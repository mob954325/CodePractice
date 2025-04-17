#pragma once
#include "framework.h"
#include "../GDIEngineLib/Scene.h"

class EndScene : public Scene
{
	void Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC) override;
	void PhysicsUpdate() override;
	void Update() override;
	void Render() override;
	void Exit() override { Clear(); };
};


