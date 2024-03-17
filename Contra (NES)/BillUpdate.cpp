#include "Bill.h"
#include "Tilemap.h"
#include "ID.h"
#include "Loader.h"

void CBill::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y
	x += vx * dt;
	y += vy * dt;

	if (GetState(BILL_STATE_JUMP))
	{
		if (y == GROUND_Y)
		{
			vy = BILL_JUMP_SPEED_Y;
		}
		vy -= BILL_GRAVITY * dt;
	}
	else if (GetState(BILL_STATE_RELEASE_JUMP))
	{
		vy -= BILL_GRAVITY * dt;
	}
	else if (GetState(BILL_STATE_LOOK_UP)||GetState(BILL_STATE_IDLE)||GetState(BILL_STATE_SIT))
	{
		vx = 0;
		vy = 0;
	}
	else if (GetState(BILL_STATE_WALK))
	{
		if(left&&!right)
		{
			vx = -BILL_WALKING_SPEED;
			nx = -1;
		}
		else if (!left && right)
		{
			vx = BILL_WALKING_SPEED;
			nx = 1;
		}
	}
	else if (GetState(BILL_STATE_IDLE))
	{
		vx = 0;
		vy = 0;
	}

	if (y < GROUND_Y)
	{
		vy = 0; y = GROUND_Y;
		SetState(BILL_STATE_IDLE);
	}

	if (vx > 0 && x > LEVEL_LENGTH - BILL_WIDTH) x = LEVEL_LENGTH - BILL_WIDTH;
	if (vx < 0 && x < 0 + BILL_WIDTH) x = 0 + BILL_WIDTH;
}


void CBill::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
