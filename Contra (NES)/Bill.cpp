#include "Bill.h"

void CBill::Render()
{
    CAnimations* animations = CAnimations::GetInstance();
    int aniId = -1;
    int state = GetState();
    if (left && !right)
        switch (state)
        {
        case (BILL_STATE_IDLE):
            aniId = ID_ANI_BILL_IDLE_LEFT;
            break;
        case (BILL_STATE_WALK):
            aniId = ID_ANI_BILL_WALK_LEFT;
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
        case (BILL_STATE_WALK_LOOK_UP):
            aniId = ID_ANI_BILL_WALK_LOOK_UP_LEFT;
            break;
        case (BILL_STATE_WALK_LOOK_DOWN):
            aniId = ID_ANI_BILL_WALK_LOOK_DOWN_LEFT;
        }

    else if (!left && right)
        switch (state)
        {
        case BILL_STATE_IDLE:
            aniId = ID_ANI_BILL_IDLE_RIGHT;
            break;
        case BILL_STATE_WALK:
            aniId = ID_ANI_BILL_WALK_RIGHT;
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
        case BILL_STATE_WALK_LOOK_UP:
            aniId = ID_ANI_BILL_WALK_LOOK_UP_RIGHT;
            break;
        case BILL_STATE_WALK_LOOK_DOWN:
            aniId = ID_ANI_BILL_WALK_LOOK_DOWN_RIGHT;
            break;
        }


    animations->Get(aniId)->Render(x, y, z);
}

void CBill::SetState(int state)
{
    this->state = state;
}

void CBill::SetState(int keycode, int action)
{
    switch (keycode)
    {
    case DIK_S: // Jump
        switch (action)
        {
        case ON_KEY_DOWN:

            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_WALK_LOOK_DOWN) || GetState(BILL_STATE_WALK_LOOK_UP))
            {
                SetState(BILL_STATE_JUMP);
            }
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_JUMP))
            {
                SetState(BILL_STATE_RELEASE_JUMP);
            }
            break;
        case KEY_STATE:
            break;
        }
        break;

    case DIK_UP: // Look up
        switch (action)
        {
        case ON_KEY_DOWN:
            if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            {
                if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_UP))
                    SetState(BILL_STATE_WALK_LOOK_UP);
                else
                    SetState(BILL_STATE_LOOK_UP);
            }
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_LOOK_UP))
            {
                SetState(BILL_STATE_IDLE);
            }
            else if (GetState(BILL_STATE_WALK_LOOK_UP))
            {
                SetState(BILL_STATE_WALK);
            }
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            {
                if (GetState(BILL_STATE_WALK)||GetState(BILL_STATE_WALK_LOOK_UP))
                    SetState(BILL_STATE_WALK_LOOK_UP);
                else
                    SetState(BILL_STATE_LOOK_UP);
            }
            break;
        }
        break;

    case DIK_DOWN: // Sit
        switch (action)
        {
        case ON_KEY_DOWN:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            {
                if (GetState(BILL_STATE_WALK)|| GetState(BILL_STATE_WALK_LOOK_UP) ||GetState(BILL_STATE_WALK_LOOK_DOWN))
                    SetState(BILL_STATE_WALK_LOOK_DOWN);
                else
                    SetState(BILL_STATE_SIT);
            }
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_SIT))
                SetState(BILL_STATE_IDLE);
            else  if (GetState(BILL_STATE_WALK_LOOK_DOWN))
                SetState(BILL_STATE_WALK);
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            {
                if (GetState(BILL_STATE_WALK)|| GetState(BILL_STATE_WALK_LOOK_UP) || GetState(BILL_STATE_WALK_LOOK_DOWN))
                    SetState(BILL_STATE_WALK_LOOK_DOWN);
                else
                    SetState(BILL_STATE_SIT);
            }
        }
        break;

    case DIK_LEFT: // Go left
        switch (action)
        {
        case ON_KEY_DOWN:
            break;
        case ON_KEY_UP:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
                SetState(BILL_STATE_IDLE);
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
                SetState(BILL_STATE_WALK);
            left = true;
            right = false;
            break;
        }
        break;

    case DIK_RIGHT: // Go right
        switch (action)
        {
        case ON_KEY_DOWN:
            break;
        case ON_KEY_UP:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
                SetState(BILL_STATE_IDLE);
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
                SetState(BILL_STATE_WALK);
            left = false;
            right = true;
            break;
        }
        break;

    case DIK_X:
        // Beta
        break;
    }

    CGameObject::SetState(state);
}

void CBill::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y
    x += vx * dt;
    y += vy * dt;
    DebugOut(L"x = %f, y = %f\n", x, y);

    if (GetState(BILL_STATE_JUMP))
    {
        if (y == GROUND_Y)
        {
            vy = BILL_JUMP_SPEED_Y;
        }
        vy -= BILL_GRAVITY * dt;
    }
    else if (GetState(BILL_STATE_RELEASE_JUMP))
    {
        vy -= BILL_GRAVITY * dt;
    }
    else if (GetState(BILL_STATE_LOOK_UP) || GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_SIT))
    {
        vx = 0;
        vy = 0;
    }
    else if ((GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_DOWN) || GetState(BILL_STATE_WALK_LOOK_UP)))
    {
        if (left && !right)
        {
            vx = -BILL_WALK_SPEED;
            nx = -1;
        }
        else if (!left && right)
        {
            vx = BILL_WALK_SPEED;
            nx = 1;
        }
    }
    else if (GetState(BILL_STATE_IDLE))
    {
        vx = 0;
        vy = 0;
    }

    if (y < GROUND_Y)
    {
        vy = 0; y = GROUND_Y;
        SetState(BILL_STATE_IDLE);
    }

    if (vx > 0 && x > LEVEL_LENGTH - BILL_WIDTH) x = LEVEL_LENGTH - BILL_WIDTH;
    if (vx < 0 && x < 0 + BILL_WIDTH) x = 0 + BILL_WIDTH;

}


void CBill::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
    left = x - BILL_WIDTH / 2;
    right = left + BILL_WIDTH;
    bottom = y - BILL_HEIGHT / 2;
    top = y + BILL_HEIGHT;
}
