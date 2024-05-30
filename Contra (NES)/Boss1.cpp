#include "Boss1.h"

void CBoss1::Render()
{
	LPANIMATION ani;
	if (notded == true)
	{
		ani = CAnimations::GetInstance()->Get(ID_BOSS1);
		ani->Render(x, y);
		ani = CAnimations::GetInstance()->Get(ID_BOSS1_BADGE);
		ani->Render(BOSS1_BADGE_START_X, BOSS1_BADGE_START_Y);
	}
}


void CBoss1::Update(DWORD dt)
{
}


void CBoss1::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - BOSS1_WIDTH / 2;
	right = left + BOSS1_WIDTH;
	bottom = y - BOSS1_HEIGHT / 2;
	top = bottom + BOSS1_HEIGHT;
}

void CBoss1::OnNoCollision(DWORD dt)
{
}

void CBoss1::OnCollisionWith(LPCOLLISIONEVENT e)
{

	if (dynamic_cast<CBullet*>(e->obj))
		OnCollisionWithBullet(e);
}

void CBoss1::OnCollisionWithBullet(LPCOLLISIONEVENT e)
{
	if (bullet->isBillBullet == true)
		hp -= 5;
	if (hp <= 0) notded = false;
}
