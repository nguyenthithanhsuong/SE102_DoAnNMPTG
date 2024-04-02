#include "Greeder.h"

void CGreeder::Render()
{
    LPANIMATION ani;
	if (state==true)
		ani = CAnimations::GetInstance()->Get(ID_ANI_GREEDER_RUN_RIGHT);
	else
		ani = CAnimations::GetInstance()->Get(ID_ANI_GREEDER_RUN_LEFT);
    ani->Render(x, y);
}


void CGreeder::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y
    x -= vx * dt;
    DebugOut(L"Enemy: x = %f, y = %f\n", x);
	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - GREEDER_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - GREEDER_WIDTH)
		{
			x = (float)(BackBufferWidth - GREEDER_WIDTH);
		}
	}
	if (vx > 0)
		state = false;
	else
		state = true;
}


void CGreeder::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
    left = x - GREEDER_WIDTH / 2;
    right = left + GREEDER_WIDTH;
    bottom = y - GREEDER_HEIGHT / 2; 
    top = y + GREEDER_HEIGHT;
}
