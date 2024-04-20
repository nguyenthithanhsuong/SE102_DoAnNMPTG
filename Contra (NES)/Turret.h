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
extern CBill* bill;

class CTurret : public CGameObject
{
	bool Collision = true;
	int state = 0;
	/*
		0: idle
		1: 1h
		2: 2h
		3: 3h
		4: 4h
		5: 5h
		6: 6h
		7: 7h
		8: 8h
		9: 9h
		10: 10h
		11: 11h
		12: 12h
		13: Open
	*/
	bool isOnPlatform = false;
public:
	CTurret(float x, float y) : CGameObject(x, y)
	{
		IsDynamic = true;
		this->vx = 0; this->vy = 0;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
};