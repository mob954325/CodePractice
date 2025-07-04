#pragma once
#include <iostream>
#include "Datas.h"

class AnimationClipLoader
{
public:
	static void LoadAnimationClip(const std::string& filePath, AnimationClip& clip, const SpriteSheet& spriteSheet);
};

class AnimationControllerLoader
{
private:
public:
	static void LoadAnimatorController(const std::string& filePath, AnimatorController& ac);
};