#pragma once

#include <Windows.h>
#include <d3dx10.h>
#include <vector>

#include "Animation.h"
#include "Animations.h"
#include "Sprites.h"
#include "debug.h"
#include "Textures.h"
#include "Game.h"
#include "Sprites.h"

using namespace std;

#define ID_TEX_BBOX -100
extern CCamera* Camera;

class CGameObject;
typedef CGameObject* LPGAMEOBJECT;

class CGameObject
{
protected:

	int ObjectID = 0;
	float x; 
	float y;
	float z=0.5;

	float vx; //velocity x
	float vy; //velocity y

	int nx;	 

	int state;		

	bool isDeleted;
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	void GetSpeed(float& vx, float& vy) { vx = this->vx; vy = this->vy; }

	int GetState() { return this->state; }
	virtual void Delete() { isDeleted = true; }
	bool IsDeleted() { return isDeleted; }

	void RenderBoundingBox();

	CGameObject();
	CGameObject(float x, float y):CGameObject() { this->x = x; this->y = y; }

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Update(DWORD dt) {};
	virtual void Render() = 0;
	void SetState(int state) { this->state = state; }

	~CGameObject();

	static bool IsDeleted(const LPGAMEOBJECT& o) { return o->isDeleted; }
};

typedef CGameObject* LPGAMEOBJECT;