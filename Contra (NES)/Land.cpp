#pragma once
#include "Land.h"

CLand::CLand(float x, float y) :CGameObject(x, y)
{
};

void CLand::SetState(int state)
{
	this->state = state;
}

void CLand::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	/*
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
	*/
	animations->Get(ID_ANI_STAGE_1_0 + state)->Render(x, y);
}

void CLand::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == 44 || state == 51 || state == 52 || state == 53 ||
		state == 54 || state == 55 || state == 56 || state == 67 ||
		state == 90 || state == 91) //halfblocks
	{
		l = x - MAP_TILE_WIDTH / 2;
		b = y - MAP_TILE_WIDTH / 2 - MAP_TILE_WIDTH / 2;
		r = l + MAP_TILE_WIDTH;
		t = b + MAP_TILE_WIDTH;
	}
	else if (state == 73 || state == 76) //full block
	{
		l = x - MAP_TILE_WIDTH / 2;
		b = y - MAP_TILE_WIDTH / 2;
		r = l + MAP_TILE_WIDTH;
		t = b + MAP_TILE_WIDTH;
	}
	else
	{
		l = x - MAP_TILE_WIDTH / 2;
		b = y - MAP_TILE_WIDTH / 2;
		r = l + MAP_TILE_WIDTH;
		t = b + MAP_TILE_WIDTH;
	}
}

int CLand::IsDirectionColliable(float nx, float ny)
{
	if (state == 44 || state == 51 || state == 52 || state == 53 ||
		state == 54 || state == 55 || state == 56 || state == 67 ||
		state == 90 || state == 91 || state == 73 || state == 76)
	{
		if (nx == 0 && ny == -1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}


