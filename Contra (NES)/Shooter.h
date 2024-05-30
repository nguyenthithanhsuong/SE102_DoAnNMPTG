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
extern CBullet* bullet;

class CShooter : public CGameObject
{
	bool Collision = true;
	int hp = 20;
	int state = 2;
	/*
		1: up left
		2: left
		3: down left
		4: up right
		5: right
		6: down right
	*/
	bool isOnPlatform = false;
public:
	CShooter(float x, float y) : CGameObject(x, y)
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
	void OnCollisionWithBullet(LPCOLLISIONEVENT e);
};