#pragma once
#include <string>

#include "Animation.h"
#include "Animations.h"

#include "GameObject.h"
#include "ID.h"
#include "BinaryTree.h"
#include "Land.h"
#include "Bill.h"



extern QNode* Tree;
class Loader;

class CGreeder : public CGameObject
{
	bool Collision = true;
	bool state = true;
	bool isOnPlatform = false;
public:
	CGreeder(float x, float y, float vx) : CGameObject(x, y)
	{
		IsDynamic = true;
		this->vx = vx; this->vy = 0;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
};