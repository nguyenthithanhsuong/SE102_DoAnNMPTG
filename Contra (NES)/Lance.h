#pragma once
#include <string>
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "ID.h"
#include "KeyEventHandler.h"
class Loader;

class CLance : public CGameObject
{
	int state;
	bool left;
	bool right;
public:
	CLance(float x, float y) : CGameObject(x, y)
	{
		state = LANCE_STATE_RELEASE_JUMP;
		left = false;
		right = true;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void SetState(int state); //set specific states
	void SetState(int keycode, int action);
	bool GetState(int state2)
	{
		if (GetState() == state2)
			return true;
		else
			return false;
	}
	int GetState() { return state; }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
};