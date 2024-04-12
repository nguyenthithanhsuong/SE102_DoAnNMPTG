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
	CLand(float x, float y);
	void SetState(int state);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsCollidable()
	{
		if (state == 44 || state == 51 || state == 52 || state == 53 ||
			state == 54 || state == 55 || state == 56 || state == 67 ||
			state == 90 || state == 91 || state == 73 || state == 76)
			return 1;
		else
			return 0;
		//return 1;
	};
	int IsDirectionColliable(float nx, float ny);
};


