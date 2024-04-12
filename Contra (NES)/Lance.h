#pragma once
#include <string>

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "GameObject.h"
#include "ID.h"
#include "Greeder.h"
#include "Land.h"
#include "BinaryTree.h"

#define LANCE_UNTOUCHABLE_TIME 2500

extern QNode* Tree;
class Loader;

class CLance : public CGameObject
{
public:
	int ObjectID = 1;
	int state;
	bool left;
	bool right;
	int untouchable;
	ULONGLONG untouchable_start;
	BOOLEAN isOnPlatform;
	bool Collision = false;
	CLance(float x, float y) : CGameObject(x, y)
	{
		IsDynamic = true;
		state = LANCE_STATE_RELEASE_JUMP;
		left = false;
		right = true;
		isOnPlatform = false;

		untouchable = 0;
		untouchable_start = -1;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void SetState(int keycode, int action);
	void SetState(int state); //set specific states
	bool GetState(int state2)
	{
		if (GetState() == state2)
			return true;
		else
			return false;
	}
	int GetState() { return state; }
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'

	//Collision:
	virtual int IsCollidable() { return 1; };
	int IsBlocking()
	{
		return 0;
	}


	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void OnCollisionWithGreeder(LPCOLLISIONEVENT e);

	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }
};
