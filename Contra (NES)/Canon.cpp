#include "Canon.h"

void CCanon::Render()
{
	LPANIMATION ani;
	switch (state)
	{
	case 0:
		if (IsOnScreen == false)
		{
			ani = CAnimations::GetInstance()->Get(ID_ANI_CANON_APPEAR);
			ani->Render(x, y);
			state = 1;
			IsOnScreen = true;
		}
		break;
	case 1:
		ani = CAnimations::GetInstance()->Get(ID_ANI_CANON_LOOK_LEFT);
		ani->Render(x, y);
		break;
	case 2:
		ani = CAnimations::GetInstance()->Get(ID_ANI_CANON_LOOK_UPLEFT);
		ani->Render(x, y);
		break;
	case 3:
		ani = CAnimations::GetInstance()->Get(ID_ANI_CANON_LOOK_UP);
		ani->Render(x, y);
		break;
	case 4:
		if (IsOnScreen == true)
		{
			ani = CAnimations::GetInstance()->Get(ID_ANI_CANON_GONE);
			ani->Render(x, y);
			state = 1;
			IsOnScreen = false;
		}
		break;
	}
}


void CCanon::Update(DWORD dt)
{
	float billx, billy;
	bill->GetPosition(billx, billy);

	float distanceThreshold = 150.0f; // Nguong khoang cach de xac dinh trang thai cua turret
	float angleThreshold = 3.14159265358979323846f / 8.0f; // Nguong goc de xac dinh huong cua bill (22.5 do)

	float deltaX = billx - x; // Khoang cach theo truc X giua bill va turret
	float deltaY = billy - y; // Khoang cach theo truc Y giua bill va turret

	float distance = sqrt(deltaX * deltaX + deltaY * deltaY); // Tinh khoang cach Euclidean

	// Kiem tra neu bill o qua xa vi tri cua turret
	if (distance <= distanceThreshold)
	{
		if (IsOnScreen == true)
		{
			// Tinh toan goc giua turret va bill
			float angle = atan2(deltaY, deltaX);

			if (angle < 0)
				angle += 2 * 3.14159265358979323846f;

			// Kiem tra huong cua bill va cap nhat trang thai cua turret dua tren goc
			else if (angle < 6 * angleThreshold && angle >= 3 * angleThreshold)
			{
				state = 3;
			}
			else if (angle < 7 * angleThreshold && angle >= 6 * angleThreshold)
			{
				state = 2;
			}
			else
			{
				state = 1;
			}
		}
		else
		{
			state = 0;
		}
	}
	else
	{
		state = 4;
	}


	isOnPlatform = false;

	CCollision::GetInstance()->Process(this, dt, Tree);
}


void CCanon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - CANON_WIDTH / 2;
	right = left + CANON_WIDTH;
	bottom = y - CANON_HEIGHT / 2;
	top = bottom + CANON_HEIGHT;
}

void CCanon::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CCanon::OnCollisionWith(LPCOLLISIONEVENT e)
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

void CCanon::OnCollisionWithBullet(LPCOLLISIONEVENT e)
{
	if (bullet->isBillBullet == true)
		hp -= 5;
	if (hp <= 0) state = 4;
}
