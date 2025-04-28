#pragma once
#include <input.h>
#include <gameWindowBuffer.h>

bool initGame();

bool updateGamePerFrame(float deltaTime, int w, int h, Input& input, GameWindowBuffer& gameWindowBuffer);

void exitGame();