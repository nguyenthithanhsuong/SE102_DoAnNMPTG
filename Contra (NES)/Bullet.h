#pragma once

#include "Animation.h"
#include "Animations.h"

#include "GameObject.h"

#include "ID.h"

class CBullet : public CGameObject
{
protected:
	int state = 1;
	float vx = 0;
	float vy = 0;
	int degree;
	bool isBillBullet;
	float originalx;
	float originaly;
public:
	int type = 0;
	CBullet(float x, float y, int degree, bool isBillBullet);
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsCollidable() { return 0; };
	int IsDirectionColliable(float nx, float ny) { return 0; }
};


