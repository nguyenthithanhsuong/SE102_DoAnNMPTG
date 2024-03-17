#include "Bill.h"
#include "Tilemap.h"
#include "ID.h"


void CBill::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	int state = GetState();
	if(left&&!right)
		switch (state)
		{
		case (BILL_STATE_IDLE):
			aniId = ID_ANI_BILL_IDLE_LEFT;
			break;
		case (BILL_STATE_WALK):
			aniId = ID_ANI_BILL_WALKING_LEFT;
			break;
		case (BILL_STATE_JUMP):
			aniId = ID_ANI_BILL_JUMP_LEFT;
			break;
		case (BILL_STATE_RELEASE_JUMP):
			aniId = ID_ANI_BILL_JUMP_LEFT;
			break;
		case (BILL_STATE_SIT):
			aniId = ID_ANI_BILL_SIT_LEFT;
			break;
		case (BILL_STATE_LOOK_UP):
			aniId = ID_ANI_BILL_LOOK_UP_LEFT;
			break;
		}

	else if(!left&&right)
		switch (state)
		{
		case BILL_STATE_IDLE:
			aniId = ID_ANI_BILL_IDLE_RIGHT;
			break;
		case BILL_STATE_WALK:
			aniId = ID_ANI_BILL_WALKING_RIGHT;
			break;
		case BILL_STATE_JUMP:
			aniId = ID_ANI_BILL_JUMP_RIGHT;
			break;
		case BILL_STATE_RELEASE_JUMP:
			aniId = ID_ANI_BILL_JUMP_RIGHT;
			break;
		case BILL_STATE_SIT:
			aniId = ID_ANI_BILL_SIT_RIGHT;
			break;
		case BILL_STATE_LOOK_UP:
			aniId = ID_ANI_BILL_LOOK_UP_RIGHT;
			break;
		}


	animations->Get(aniId)->Render(x, y);
}
