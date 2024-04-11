#include "Title.h"

void CTitle::Render()
{
	LPANIMATION ani;
	if (status == false)
	{
		ani = CAnimations::GetInstance()->Get(ID_ANI_TITLE_RUN_RIGHT);
		ani->Render(x, y, z);
	}
	else
	{
		ani = CAnimations::GetInstance()->Get(ID_ANI_TITLE_RUN_RIGHT);
		ani->Render(x, y, z);
		ani = CAnimations::GetInstance()->Get(ID_MENU1);
		ani->Render(MENU1_START_X, MENU1_START_Y, z);
		ani = CAnimations::GetInstance()->Get(ID_MENU2);
		ani->Render(MENU2_START_X, MENU2_START_Y, z);
		ani = CAnimations::GetInstance()->Get(ID_BADGE);
		if (choice == 1)
		{
			ani->Render(BADGE_START_X, BADGE_START_Y, z);
		}
		else
		{
			ani->Render(BADGE_SECOND_X, BADGE_SECOND_Y, z);
		}
	}
}

void CTitle::SetState(int keycode, int state)
{
	switch (keycode)
	{
	case DIK_RETURN:
		if (status == true)
		{
			if (choice == 1)
			{
				confirm = 1;
				DebugOut(L"Player num: 1");
			}
			else
			{
				confirm = 2;
				DebugOut(L"Player num: 2");
			}
			scene = 1;
		}
		break;
	case DIK_SPACE:
		if (status == true)
		{
			switch (state)
			{
			case ON_KEY_DOWN:
				if (choice == 1)
					choice = 2;
				else
					choice = 1;
				break;
			}
		}
		break;
	}

}


void CTitle::Update(DWORD dt)
{
	x -= vx * dt;
	DebugOut(L"Title: x = %f, y = %f\n", x, y);

	if (x <= SCREEN_WIDTH - TITLE_WIDTH - 20)
	{
		x = SCREEN_WIDTH - TITLE_WIDTH - 20;
		vx = 0;
		status = true;
	}
}