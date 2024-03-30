#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "ID.h"

class CLand : public CGameObject
{
protected:
	int state = 1;
public:
	CLand(float x, float y);
	void SetState(int state);
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};


