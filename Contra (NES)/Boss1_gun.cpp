#include "Boss1_gun.h"

void CBoss1Gun::Render()
{
	LPANIMATION ani;
	if (notded == true)
	{
		if (isGun1 && (turn == 0))
		{
			ani = CAnimations::GetInstance()->Get(ID_BOSS1_GUN1);
			ani->Render(x, y);
			turn = 1;
		}
		else
		{
			ani = CAnimations::GetInstance()->Get(ID_BOSS1_GUN2);
			ani->Render(BOSS1_GUN2_START_X, BOSS1_GUN2_START_Y);
			turn = 0;
		}
	}
}


void CBoss1Gun::Update(DWORD dt)
{
}


void CBoss1Gun::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - BOSS1_GUN1_WIDTH / 2;
	right = left + BOSS1_GUN1_WIDTH;
	bottom = y - BOSS1_GUN1_WIDTH / 2;
	top = bottom + BOSS1_GUN1_WIDTH;
}

void CBoss1Gun::OnNoCollision(DWORD dt)
{
}

void CBoss1Gun::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CBullet*>(e->obj))
		OnCollisionWithBullet(e);
}

void CBoss1Gun::OnCollisionWithBullet(LPCOLLISIONEVENT e)
{
	if (bullet->isBillBullet == true)
		hp -= 5;
	if (hp <= 0) notded = false;
}
