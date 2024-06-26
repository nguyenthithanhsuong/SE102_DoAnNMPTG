#pragma once
#include <string>

#include "Animation.h"
#include "Animations.h"

#include "GameObject.h"
#include "ID.h"
#include "BinaryTree.h"
#include "Land.h"
#include "Bill.h"
#include "Bullet.h"


extern QNode* Tree;
class Loader;
extern CBullet* bullet;

class CGreeder : public CGameObject
{
	bool Collision = true;
	bool state = true;
	bool notded = true;
	int hp = 20;
	bool isOnPlatform = false;
public:
	CGreeder(float x, float y, float vx, int hp) : CGameObject(x, y)
	{
		IsDynamic = true;
		this->hp = hp;
		this->vx = vx; this->vy = 0;
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