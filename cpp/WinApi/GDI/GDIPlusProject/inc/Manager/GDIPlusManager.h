#pragma once
#include <stdio.h>
#include <windows.h>

#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")

class GDIPlusManager
{
public:
	static void Initialize();
	static void ShutDown();

private:
	ULONG_PTR g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	bool initialized;
};

