#pragma once
#include <string>

#include "Animation.h"
#include "Animations.h"

#include "GameObject.h"
#include "ID.h"
#include "BinaryTree.h"
#include "Land.h"
#include "Bill.h"
#include "Boss1_gun.h"

extern QNode* Tree;
extern CBoss1Gun* bossgun1;
extern CBoss1Gun* bossgun2;
class Loader;
extern CBullet* bullet;

class CBoss1 : public CGameObject
{
	bool Collision = true;
	bool notded = true;
	int hp = 100;
	bool isOnPlatform = false;
public:
	CBoss1(float x, float y) : CGameObject(x, y)
	{
		IsDynamic = true;
		this->vx = 0; this->vy = 0;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithBullet(LPCOLLISIONEVENT e);
};