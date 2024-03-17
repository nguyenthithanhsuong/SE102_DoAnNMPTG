#pragma once
#include "Land.h"

CLand::CLand(float x, float y) :CGameObject(x, y)
{
};

void CLand::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}
void CLand::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - LAND_WIDTH / 2;
	t = y - LAND_WIDTH / 2;
	r = l + LAND_WIDTH;
	b = t + LAND_WIDTH;
}

void CLand::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (state)
	{
	case(0):
		animations->Get(ID_ANI_LAND_0)->Render(x, y);
		break;
	case(1):
		animations->Get(ID_ANI_LAND_1)->Render(x, y);
		break;
	case(2):
		animations->Get(ID_ANI_LAND_2)->Render(x, y);
		break;
	case(3):
		animations->Get(ID_ANI_LAND_3)->Render(x, y);
		break;
	case(4):
		animations->Get(ID_ANI_LAND_4)->Render(x, y);
		break;
	case(5):
		animations->Get(ID_ANI_LAND_5)->Render(x, y);
		break;
	}
}

void CLand::SetState(int state)
{
	this->state = state;
}
