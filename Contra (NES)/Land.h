#pragma once

#include "Animation.h"
#include "Animations.h"

#include "GameObject.h"

#include "ID.h"

class CLand : public CGameObject
{
protected:
	int state = 1;
	float vx = 0;
	float vy = 0;
public:
	int type = 0;
	CLand(float x, float y);
	void SetState(int state);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsCollidable()
	{
		return 0;
	};
	int IsDirectionColliable(float nx, float ny);
};


