#pragma once
#include "Land.h"

CLand::CLand(float x, float y) :CGameObject(x, y)
{
};


void CLand::SetState(int state)
{
	this->state = state;

	if (state == 75 || state == 79 || state == 80 || state == 81 ||
		state == 82 || state == 83 || state == 84 || state == 85 ||
		state == 86 || state == 87 || state == 88 || state == 89)
		type = 3; //swim block

	else if (state == 44 || state == 51 || state == 52 || state == 53 ||
		state == 54 || state == 55 || state == 56 || state == 67 ||
		state == 90 || state == 91)
		type = 2; //halfblock land

	else if (state == 73 || state == 76)
		type = 1; //full block

	else
		type = 0;
}

void CLand::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	animations->Get(ID_ANI_STAGE_1_0 + state)->Render(x, y);
}

void CLand::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (type==2) //halfblocks land
	{
		l = x - MAP_TILE_WIDTH / 2;
		b = y - MAP_TILE_WIDTH / 2 - MAP_TILE_WIDTH / 2;
		r = l + MAP_TILE_WIDTH;
		t = b + MAP_TILE_WIDTH;
	}
	else if (type==3) //swim land
	{
		l = x - MAP_TILE_WIDTH / 2;
		b = y - MAP_TILE_WIDTH / 2 - MAP_TILE_WIDTH / 2;
		r = l + MAP_TILE_WIDTH;
		t = b + MAP_TILE_WIDTH;
	}
	else if (type==1) //full block
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
	if (type!=0)
	{
		if (nx == 0 && ny == -1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}


