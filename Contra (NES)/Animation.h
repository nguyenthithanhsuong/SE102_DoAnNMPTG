#pragma once

#include <Windows.h>
#include <unordered_map>

#include "Sprites.h"
#include "AnimationFrame.h"


using namespace std;

class CAnimation
{
	ULONGLONG lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;
public:
	CAnimation(int defaultTime) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; } //create
	void Add(int spriteId, DWORD time = 0); //add a frame to animation
	void Render(float x, float y); //Draw to screen
};

typedef CAnimation* LPANIMATION;