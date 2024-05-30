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
extern CBullet* bullet;


class CBoss1Gun : public CGameObject
{
	bool Collision = true;
	bool notded = true;
	bool isGun1 = true;
	int turn = 0;
	int hp = 50;
	bool isOnPlatform = false;
public:
	CBoss1Gun(float x, float y, bool isGun1) : CGameObject(x, y)
	{
		IsDynamic = true;
		this->isGun1 = isGun1;
		this->vx = 0; this->vy = 0;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithBullet(LPCOLLISIONEVENT e);
};

