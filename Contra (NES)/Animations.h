#pragma once

#include "Animation.h"
#include "Sprite.h"

class CAnimations
{
	static CAnimations* __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani); //add frame to animation
	LPANIMATION Get(int id); //get id
	void Clear();

	static CAnimations* GetInstance();
};