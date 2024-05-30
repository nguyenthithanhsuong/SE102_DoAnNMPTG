#include "Shooter.h"

void CShooter::Render()
{
	LPANIMATION ani;
	switch (state)
	{
	case 1:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_LEFT_UP);
		ani->Render(x, y);
		break;
	case 2:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_LEFT);
		ani->Render(x, y);
		break;
	case 3:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_LEFT_DOWN);
		ani->Render(x, y);
		break;
	case 4:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_RIGHT_UP);
		ani->Render(x, y);
		break;
	case 5:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_RIGHT);
		ani->Render(x, y);
		break;
	case 6:
		ani = CAnimations::GetInstance()->Get(ID_ANI_SHOOTER_LOOK_RIGHT_DOWN);
		ani->Render(x, y);
		break;
	}

}


void CShooter::Update(DWORD dt)
{
	vy -= GAME_GRAVITY * dt;

	float billx, billy;
	bill->GetPosition(billx, billy);

	if (billy > (y + 20.0f))
	{
		if (billx < x)
			state = 1;
		else
			state = 4;
	}
	else
	{
		if (billy < (y - 20.0f))
		{
			if (billx < x)
				state = 3;
			else
				state = 6;
		}
		else
		{
			if (billx < x)
				state = 2;
			else
				state = 5;
		}
	}
	isOnPlatform = false;

	CCollision::GetInstance()->Process(this, dt, Tree);
}


void CShooter::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - SHOOTER_WIDTH / 2;
	right = left + SHOOTER_WIDTH;
	bottom = y - SHOOTER_HEIGHT / 2;
	top = bottom + SHOOTER_HEIGHT;
}

void CShooter::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CShooter::OnCollisionWith(LPCOLLISIONEVENT e)
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
	if (dynamic_cast<CBullet*>(e->obj))
		OnCollisionWithBullet(e);
}

void CShooter::OnCollisionWithBullet(LPCOLLISIONEVENT e)
{
	if (bullet->isBillBullet == true)
		hp -= 5;
	if (hp <= 0) state = 6;
}