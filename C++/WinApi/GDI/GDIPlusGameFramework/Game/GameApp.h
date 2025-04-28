#pragma once
#include "../GDIEngineLib/WinApp.h"

class GameApp :
	public WinApp
{
public:
	GameApp() = default;
	~GameApp() = default;

	virtual void Initialize() override;
	virtual void Shutdown() override;

};