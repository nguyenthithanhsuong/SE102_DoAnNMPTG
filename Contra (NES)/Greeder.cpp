#include "Greeder.h"

void CGreeder::Render()
{
	LPANIMATION ani;
	if (state == true)
		ani = CAnimations::GetInstance()->Get(ID_ANI_GREEDER_RUN_RIGHT);
	else
		ani = CAnimations::GetInstance()->Get(ID_ANI_GREEDER_RUN_LEFT);
	ani->Render(x, y);
}


void CGreeder::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y

	vy -= GAME_GRAVITY * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();

	if (x <= GREEDER_WIDTH || x >= LEVEL_LENGTH - GREEDER_WIDTH) {

		vx = -vx;

		if (x <= 50)
		{
			x = 50;
		}
		else if (x >= LEVEL_LENGTH - GREEDER_WIDTH)
		{
			x = (float)(LEVEL_LENGTH - GREEDER_WIDTH);
		}
	}
	if (vx > 0)
		state = true;
	else
		state = false;
	isOnPlatform = false;

	CCollision::GetInstance()->Process(this, dt, Tree);
}


void CGreeder::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - GREEDER_WIDTH / 2;
	right = left + GREEDER_WIDTH;
	bottom = y - GREEDER_HEIGHT / 2;
	top = bottom + GREEDER_HEIGHT;
}

void CGreeder::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CGreeder::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else
		if (e->nx != 0 && e->obj->IsBlocking())
		{
			vx = -vx;
		}
}
