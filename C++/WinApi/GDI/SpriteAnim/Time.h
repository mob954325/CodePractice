#pragma once
#include <iostream>
#include <windows.h>

namespace Time
{
	void InitTime();
	void UpdateTime();

	float GetDeltaTime();
	float GetElapsedTime();
}