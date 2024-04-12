#pragma once
#include <string>
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "ID.h"
#include "KeyEventHandler.h"
class Title;

class CTitle : public CGameObject
{
	float vx;
	bool status = false;
	int choice = 1;
public:
	bool LANCE_ADDED = false;
	int scene = 0;
	int confirm;
	CTitle(float x, float y, float vx) : CGameObject(x, y)
	{
		status = 0;
		this->vx = vx;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void SetState(int keycode, int state);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};