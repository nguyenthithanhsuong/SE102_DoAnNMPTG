#include "Turret.h"

void CTurret::Render()
{
	LPANIMATION ani;
	switch (state)
	{
	case 0:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_IDLE);
		ani->Render(x, y);
		break;
	case 1:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_1H);
		ani->Render(x, y);
		break;
	case 2:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_2H);
		ani->Render(x, y);
		break;
	case 3:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_3H);
		ani->Render(x, y);
		break;
	case 4:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_4H);
		ani->Render(x, y);
		break;
	case 5:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_5H);
		ani->Render(x, y);
		break;
	case 6:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_6H);
		ani->Render(x, y);
		break;
	case 7:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_7H);
		ani->Render(x, y);
		break;
	case 8:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_8H);
		ani->Render(x, y);
		break;
	case 9:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_9H);
		ani->Render(x, y);
		break;
	case 10:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_10H);
		ani->Render(x, y);
		break;
	case 11:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_11H);
		ani->Render(x, y);
		break;
	case 12:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_LOOK_12H);
		ani->Render(x, y);
		break;
	case 13:
		ani = CAnimations::GetInstance()->Get(ID_ANI_TURRET_OPEN);
		ani->Render(x, y);
		break;
	}

}


void CTurret::Update(DWORD dt)
{
	float billx, billy;
	bill->GetPosition(billx, billy);

	float distanceThreshold = 150.0f; // Nguong khoang cach de xac dinh trang thai cua turret
	float angleThreshold = 3.14159265358979323846f / 8.0f; // Nguong goc de xac dinh huong cua bill (22.5 do)

	float deltaX = billx - x; // Khoang cach theo truc X giua bill va turret
	float deltaY = billy - y; // Khoang cach theo truc Y giua bill va turret

	float distance = sqrt(deltaX * deltaX + deltaY * deltaY); // Tinh khoang cach Euclidean

	// Kiem tra neu bill o qua xa vi tri cua turret
	if (distance >= distanceThreshold)
	{
		state = 0;
	}
	else
	{
		// Kiem tra neu bill o gan hon vi tri cua turret so voi nguong khoang cach
		if (distance >= 130.0f)
		{
			state = 13;
		}
		else
		{
			// Tinh toan goc giua turret va bill
			float angle = atan2(deltaY, deltaX);

			if (angle < 0)
				angle += 2 * 3.14159265358979323846f;

			// Kiem tra huong cua bill va cap nhat trang thai cua turret dua tren goc
			if (angle < 2 * angleThreshold && angle >= angleThreshold)
			{
				state = 2;
			}
			else if (angle < 3 * angleThreshold && angle >= 2 * angleThreshold)
			{
				state = 1;
			}
			else if (angle < 5 * angleThreshold && angle >= 3 * angleThreshold)
			{
				state = 12;
			}
			else if (angle < 6 * angleThreshold && angle >= 5 * angleThreshold)
			{
				state = 11;
			}
			else if (angle < 7 * angleThreshold && angle >= 6 * angleThreshold)
			{
				state = 10;
			}
			else if (angle < 9 * angleThreshold && angle >= 7 * angleThreshold)
			{
				state = 9;
			}
			else if (angle < 10 * angleThreshold && angle >= 9 * angleThreshold)
			{
				state = 8;
			}
			else if (angle < 11 * angleThreshold && angle >= 10 * angleThreshold)
			{
				state = 7;
			}
			else if (angle < 13 * angleThreshold && angle >= 11 * angleThreshold)
			{
				state = 6;
			}
			else if (angle < 14 * angleThreshold && angle >= 13 * angleThreshold)
			{
				state = 5;
			}
			else if (angle < 15 * angleThreshold && angle >= 14 * angleThreshold)
			{
				state = 4;
			}
			else if (angle < 17 * angleThreshold && angle >= 15 * angleThreshold)
			{
				state = 3;
			}
		}
	}


	isOnPlatform = false;

	CCollision::GetInstance()->Process(this, dt, Tree);
}


void CTurret::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - TURRET_WIDTH / 2;
	right = left + TURRET_WIDTH;
	bottom = y - TURRET_HEIGHT / 2;
	top = bottom + TURRET_HEIGHT;
}

void CTurret::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CTurret::OnCollisionWith(LPCOLLISIONEVENT e)
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
