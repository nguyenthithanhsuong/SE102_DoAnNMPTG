#include "Bullet.h"

CBullet::CBullet(float x, float y, int degree, bool isBillBullet) :CGameObject(x, y)
{
	originalx = x;
	originaly = y;
	this->x = x;
	this->y = y;
	this->degree = degree;
	this->isBillBullet = isBillBullet;
	float radians = degree * (3.14159265 / 180.0f);

	// Calculate vx and vy using trigonometric functions
	vx = cos(radians);
	vy = sin(radians);
	
	float speed = 5;
	vx = vx / speed;
	vy = vy / speed;
}

void CBullet::Render()
{
	LPANIMATION ani;
		ani = CAnimations::GetInstance()->Get(ID_ANI_BULLET);
	ani->Render(x, y);
}

void CBullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	float path = 200;
	if ((abs(x - originalx) > path) || (abs(y - originaly) > path))
		Delete();
}

void CBullet::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - 1;
	right = x + 1;
	bottom = y - 1;
	top = y + 1;
}

