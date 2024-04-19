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

#define BILL_UNTOUCHABLE_TIME 2500

extern QNode* Tree;
class Loader;

class CBill : public CGameObject
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
	bool isBill = true;
	bool isSwimming = false;
	CBill(float x, float y, bool isBill) : CGameObject(x, y)
	{
		IsDynamic = true;
		state = BILL_STATE_RELEASE_JUMP;
		left = false;
		right = true;
		isOnPlatform = false;

		untouchable = 0;
		untouchable_start = -1;
		this->isBill = isBill;
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

	void LeftKey(int action);
	void RightKey(int action);
	void UpKey(int action);
	void DownKey(int action);
	void JumpKey(int action);
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