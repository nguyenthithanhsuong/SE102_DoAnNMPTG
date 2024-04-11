#include "Lance.h"


void CLance::Render()
{
    CAnimations* animations = CAnimations::GetInstance();
    int aniId = -1;
    int state = GetState();
    if (left && !right)
        switch (state)
        {
        case (LANCE_STATE_IDLE):
            aniId = ID_ANI_LANCE_IDLE_LEFT;
            break;
        case (LANCE_STATE_WALK):
            aniId = ID_ANI_LANCE_WALK_LEFT;
            break;
        case (LANCE_STATE_JUMP):
            aniId = ID_ANI_LANCE_JUMP_LEFT;
            break;
        case (LANCE_STATE_RELEASE_JUMP):
            aniId = ID_ANI_LANCE_JUMP_LEFT;
            break;
        case (LANCE_STATE_SIT):
            aniId = ID_ANI_LANCE_SIT_LEFT;
            break;
        case (LANCE_STATE_LOOK_UP):
            aniId = ID_ANI_LANCE_LOOK_UP_LEFT;
            break;
        case (LANCE_STATE_WALK_LOOK_UP):
            aniId = ID_ANI_LANCE_WALK_LOOK_UP_LEFT;
            break;
        case (LANCE_STATE_WALK_LOOK_DOWN):
            aniId = ID_ANI_LANCE_WALK_LOOK_DOWN_LEFT;
        }

    else if (!left && right)
        switch (state)
        {
        case LANCE_STATE_IDLE:
            aniId = ID_ANI_LANCE_IDLE_RIGHT;
            break;
        case LANCE_STATE_WALK:
            aniId = ID_ANI_LANCE_WALK_RIGHT;
            break;
        case LANCE_STATE_JUMP:
            aniId = ID_ANI_LANCE_JUMP_RIGHT;
            break;
        case LANCE_STATE_RELEASE_JUMP:
            aniId = ID_ANI_LANCE_JUMP_RIGHT;
            break;
        case LANCE_STATE_SIT:
            aniId = ID_ANI_LANCE_SIT_RIGHT;
            break;
        case LANCE_STATE_LOOK_UP:
            aniId = ID_ANI_LANCE_LOOK_UP_RIGHT;
            break;
        case LANCE_STATE_WALK_LOOK_UP:
            aniId = ID_ANI_LANCE_WALK_LOOK_UP_RIGHT;
            break;
        case LANCE_STATE_WALK_LOOK_DOWN:
            aniId = ID_ANI_LANCE_WALK_LOOK_DOWN_RIGHT;
            break;
        }


    animations->Get(aniId)->Render(x, y, z);
}

void CLance::SetState(int state)
{
    this->state = state;
}

void CLance::SetState(int keycode, int action)
{
    switch (keycode)
    {
    case DIK_LSHIFT: // Jump
        switch (action)
        {
        case ON_KEY_DOWN:

            if (GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_IDLE))
            {
                SetState(LANCE_STATE_JUMP);
            }
            break;
        case ON_KEY_UP:
            if (GetState(LANCE_STATE_JUMP))
            {
                SetState(LANCE_STATE_RELEASE_JUMP);
            }
            break;
        case KEY_STATE:
            break;
        }
        break;

    case DIK_W: // Look up
        switch (action)
        {
        case ON_KEY_DOWN:
            if (!GetState(LANCE_STATE_SIT) && !GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
            {
                if (GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_WALK_LOOK_UP))
                    SetState(LANCE_STATE_WALK_LOOK_UP);
                else
                    SetState(LANCE_STATE_LOOK_UP);
            }
            break;
        case ON_KEY_UP:
            if (GetState(LANCE_STATE_LOOK_UP))
            {
                SetState(LANCE_STATE_IDLE);
            }
            else if (GetState(LANCE_STATE_WALK_LOOK_UP))
            {
                SetState(LANCE_STATE_WALK);
            }
            break;
        case KEY_STATE:
            if (!GetState(LANCE_STATE_SIT) && !GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
            {
                if (GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_WALK_LOOK_UP))
                    SetState(LANCE_STATE_WALK_LOOK_UP);
                else
                    SetState(LANCE_STATE_LOOK_UP);
            }
            break;
        }
        break;

    case DIK_S: // Sit
        switch (action)
        {
        case ON_KEY_DOWN:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
            {
                if (GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_WALK_LOOK_UP) || GetState(LANCE_STATE_WALK_LOOK_DOWN))
                    SetState(LANCE_STATE_WALK_LOOK_DOWN);
                else
                    SetState(LANCE_STATE_SIT);
            }
            break;
        case ON_KEY_UP:
            if (GetState(LANCE_STATE_SIT))
                SetState(LANCE_STATE_IDLE);
            else  if (GetState(LANCE_STATE_WALK_LOOK_DOWN))
                SetState(LANCE_STATE_WALK);
            break;
        case KEY_STATE:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
            {
                if (GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_WALK_LOOK_UP) || GetState(LANCE_STATE_WALK_LOOK_DOWN))
                    SetState(LANCE_STATE_WALK_LOOK_DOWN);
                else
                    SetState(LANCE_STATE_SIT);
            }
        }
        break;

    case DIK_A: // Go left
        switch (action)
        {
        case ON_KEY_DOWN:
            break;
        case ON_KEY_UP:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
                SetState(LANCE_STATE_IDLE);
            break;
        case KEY_STATE:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
                SetState(LANCE_STATE_WALK);
            left = true;
            right = false;
            break;
        }
        break;

    case DIK_D: // Go right
        switch (action)
        {
        case ON_KEY_DOWN:
            break;
        case ON_KEY_UP:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
                SetState(LANCE_STATE_IDLE);
            break;
        case KEY_STATE:
            if (!GetState(LANCE_STATE_JUMP) && !GetState(LANCE_STATE_RELEASE_JUMP))
                SetState(LANCE_STATE_WALK);
            left = false;
            right = true;
            break;
        }
        break;
    }

    CGameObject::SetState(state);
}

void CLance::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y
    x += vx * dt;
    y += vy * dt;
    DebugOut(L"Lance: x = %f, y = %f\n", x, y);

    if (GetState(LANCE_STATE_JUMP))
    {
        if (y == GROUND_Y)
        {
            vy = LANCE_JUMP_SPEED_Y;
        }
        vy -= LANCE_GRAVITY * dt;
    }
    else if (GetState(LANCE_STATE_RELEASE_JUMP))
    {
        vy -= LANCE_GRAVITY * dt;
    }
    else if (GetState(LANCE_STATE_LOOK_UP) || GetState(LANCE_STATE_IDLE) || GetState(LANCE_STATE_SIT))
    {
        vx = 0;
        vy = 0;
    }
    else if ((GetState(LANCE_STATE_WALK) || GetState(LANCE_STATE_WALK_LOOK_DOWN) || GetState(LANCE_STATE_WALK_LOOK_UP)))
    {
        if (left && !right)
        {
            vx = -LANCE_WALK_SPEED;
            nx = -1;
        }
        else if (!left && right)
        {
            vx = LANCE_WALK_SPEED;
            nx = 1;
        }
    }
    else if (GetState(LANCE_STATE_IDLE))
    {
        vx = 0;
        vy = 0;
    }

    if (y < GROUND_Y)
    {
        vy = 0; y = GROUND_Y;
        SetState(LANCE_STATE_IDLE);
    }

    if (vx > 0 && x > LEVEL_LENGTH - LANCE_WIDTH) x = LEVEL_LENGTH - LANCE_WIDTH;
    if (vx < 0 && x < 0 + LANCE_WIDTH) x = 0 + LANCE_WIDTH;

    float cx, cy;
    GetPosition(cx, cy);
    cx -= SCREEN_WIDTH / 2;
    cy = 0;
    if (cx < 0) cx = 0;
    if (cx > LEVEL_LENGTH - SCREEN_WIDTH) cx = LEVEL_LENGTH - SCREEN_WIDTH;
}


void CLance::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
    left = x - LANCE_WIDTH / 2;
    right = left + LANCE_WIDTH;
    bottom = y - LANCE_HEIGHT / 2;
    top = y + LANCE_HEIGHT;
}
