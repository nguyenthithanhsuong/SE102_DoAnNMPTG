#pragma once
#include <string>
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "ID.h"
#include "KeyEventHandler.h"
class Loader;

class CGreeder : public CGameObject
{
	float vx;
	bool state = true;
public:
	CGreeder(float x, float y, float vx) : CGameObject(x, y)
	{
		this->vx = vx;
	}
	void Update(DWORD dt); //update frames
	void Render(); //draw to screen
	void GetBoundingBox(float& left, float& top, float& right, float& bottom); //get 'box'
};