#pragma once
#include "resource.h"

#include <windows.h>
#include <stdio.h>
#include "./inc/Scenes/MenuScene.h"

// Libraries ====================================
#include "./inc/Time.h"
#pragma comment(lib, "./lib/Time.lib")

#include "./inc/Renderer.h"
#pragma comment(lib, "./lib/Renderer.lib")

#include "./inc/Input.h"
#pragma comment(lib, "./lib/Input.lib")

enum Scene
{
	MENU = 0,
	PLAY,
	END,
	SCENECOUNT
};