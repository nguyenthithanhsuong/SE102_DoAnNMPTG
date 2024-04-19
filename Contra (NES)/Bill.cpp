#include "Bill.h"

void CBill::Render()
{
    float x2 = x;
    float y2 = y;
    float offset = 25;
    CAnimations* animations = CAnimations::GetInstance();
    int aniId = -1;
    int state = GetState();
    if (isBill)
    {
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
                break;
            case (BILL_STATE_SWIM_IDLE):
                aniId = ID_ANI_BILL_SWIM_LEFT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_WALK):
                aniId = ID_ANI_BILL_SWIM_LEFT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_SIT):
                aniId = ID_ANI_BILL_SWIM_UNDER;
                y2 -= offset;
                break;
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
            case (BILL_STATE_SWIM_IDLE):
                aniId = ID_ANI_BILL_SWIM_RIGHT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_WALK):
                aniId = ID_ANI_BILL_SWIM_RIGHT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_SIT):
                aniId = ID_ANI_BILL_SWIM_UNDER;
                y2 -= offset;
                break;
            }
    }
    else
    {
        if (left && !right)
            switch (state)
            {
            case (BILL_STATE_IDLE):
                aniId = ID_ANI_LANCE_IDLE_LEFT;
                break;
            case (BILL_STATE_WALK):
                aniId = ID_ANI_LANCE_WALK_LEFT;
                break;
            case (BILL_STATE_JUMP):
                aniId = ID_ANI_LANCE_JUMP_LEFT;
                break;
            case (BILL_STATE_RELEASE_JUMP):
                aniId = ID_ANI_LANCE_JUMP_LEFT;
                break;
            case (BILL_STATE_SIT):
                aniId = ID_ANI_LANCE_SIT_LEFT;
                break;
            case (BILL_STATE_LOOK_UP):
                aniId = ID_ANI_LANCE_LOOK_UP_LEFT;
                break;
            case (BILL_STATE_WALK_LOOK_UP):
                aniId = ID_ANI_LANCE_WALK_LOOK_UP_LEFT;
                break;
            case (BILL_STATE_WALK_LOOK_DOWN):
                aniId = ID_ANI_LANCE_WALK_LOOK_DOWN_LEFT;
            }

        else if (!left && right)
            switch (state)
            {
            case BILL_STATE_IDLE:
                aniId = ID_ANI_LANCE_IDLE_RIGHT;
                break;
            case BILL_STATE_WALK:
                aniId = ID_ANI_LANCE_WALK_RIGHT;
                break;
            case BILL_STATE_JUMP:
                aniId = ID_ANI_LANCE_JUMP_RIGHT;
                break;
            case BILL_STATE_RELEASE_JUMP:
                aniId = ID_ANI_LANCE_JUMP_RIGHT;
                break;
            case BILL_STATE_SIT:
                aniId = ID_ANI_LANCE_SIT_RIGHT;
                break;
            case BILL_STATE_LOOK_UP:
                aniId = ID_ANI_LANCE_LOOK_UP_RIGHT;
                break;
            case BILL_STATE_WALK_LOOK_UP:
                aniId = ID_ANI_LANCE_WALK_LOOK_UP_RIGHT;
                break;
            case BILL_STATE_WALK_LOOK_DOWN:
                aniId = ID_ANI_LANCE_WALK_LOOK_DOWN_RIGHT;
                break;
            }
    }

    animations->Get(aniId)->Render(x2, y2);
}

void CBill::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y    

    DebugOut(L"state = %i\n", state);
    vy -= GAME_GRAVITY * dt;

    if (left && !right)
    {
        nx = -1;
    }
    else if (!left && right)
    {
        nx = 1;
    }
    if (vy < -GAME_GRAVITY * dt)
        SetState(BILL_STATE_RELEASE_JUMP);
    if (GetState(BILL_STATE_DIE))
    {
    }
    if (GetState(BILL_STATE_JUMP))
    {
        if (isOnPlatform)
        {
            vy = BILL_JUMP_SPEED_Y;
            isOnPlatform = false;
        }
    }
    else if (GetState(BILL_STATE_RELEASE_JUMP))
    {
        if (!isOnPlatform)
        {

        }
        else
        {
            if (isSwimming)
                SetState(BILL_STATE_SWIM_IDLE);
            else
                SetState(BILL_STATE_IDLE);
        }
    }
    if (GetState(BILL_STATE_LOOK_UP) || GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_SIT)||GetState(BILL_STATE_SWIM_SIT))
    {
        vx = 0;
    }
    else if ((GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_DOWN) || GetState(BILL_STATE_WALK_LOOK_UP)) || GetState(BILL_STATE_SWIM_WALK))
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
    else if (GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_SWIM_IDLE))
    {
        vx = 0;
        vy = 0;
    }
    if (vx > 0 && x > LEVEL_LENGTH - BILL_WIDTH) x = LEVEL_LENGTH - BILL_WIDTH;
    if (vx < 0 && x < 0 + BILL_WIDTH) x = 0 + BILL_WIDTH;

    isOnPlatform = false;
    CCollision::GetInstance()->Process(this, dt, Tree);
}

void CBill::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
    if (!GetState(BILL_STATE_SWIM_IDLE) && !GetState(BILL_STATE_SWIM_WALK) && !GetState(BILL_STATE_SWIM_SIT))
    {
        top = y + BILL_HEIGHT / 2;
        bottom = y - BILL_HEIGHT / 2;
        left = x - BILL_WIDTH / 2;
        right = x + BILL_WIDTH / 2;
    }
    else
    {
        top = y;
        bottom = y - BILL_HEIGHT / 2;
        left = x - BILL_WIDTH / 2;
        right = x + BILL_WIDTH / 2;
    }
}

void CBill::OnNoCollision(DWORD dt)
{
    if (isOnPlatform)
    {
        x += vx * dt;
        y += vy * dt;
    }
    else
    {
        x += vx * dt;
        y += vy * dt;
    }
}

void CBill::OnCollisionWith(LPCOLLISIONEVENT e)
{
    if (e->ny != 0 && e->obj->IsBlocking())
    {
        vy = 0;
        if (e->ny < 0)
        {
            if (dynamic_cast<CLand*>(e->obj))
            {
                CLand* land = dynamic_cast<CLand*>(e->obj);
                if (land->type == 3)
                {
                    isSwimming = true;
                }
                else
                {
                    isSwimming = false;
                }
            }
            isOnPlatform = true;
        }
    }
    else
        if (e->nx != 0 && e->obj->IsBlocking())
        {
            vx = 0;
        }

    if (dynamic_cast<CGreeder*>(e->obj))
        OnCollisionWithGreeder(e);
}

void CBill::OnCollisionWithGreeder(LPCOLLISIONEVENT e)
{
}

void CBill::SetState(int state)
{
    this->state = state;
}

void CBill::SetState(int keycode, int action)
{
    if (isBill)
    {
        switch (keycode)
        {
        case DIK_SPACE: // Jump
            JumpKey(action);
            break;

        case DIK_UP: // Look up
            UpKey(action);
            break;

        case DIK_DOWN: // Sit
            DownKey(action);
            break;

        case DIK_LEFT: // Go left
            LeftKey(action);
            break;

        case DIK_RIGHT: // Go right
            RightKey(action);
            break;
        }
    }
    else
    {
        switch (keycode)
        {
        case DIK_LSHIFT: // Jump
            JumpKey(action);
            break;

        case DIK_W: // Look up
            UpKey(action);
            break;

        case DIK_S: // Sit
            DownKey(action);
            break;

        case DIK_A: // Go left
            LeftKey(action);
            break;

        case DIK_D: // Go right
            RightKey(action);
            break;
        }
    }

    CGameObject::SetState(state);
}

void CBill::LeftKey(int action)
{
    switch (action)
    {
    case ON_KEY_DOWN:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_WALK);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_WALK);
        left = true;
        right = false;
        break;
    case ON_KEY_UP:
        if(GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_IDLE);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_IDLE);
        break;
    case KEY_STATE:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_WALK);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_WALK);
        left = true;
        right = false;
        break;
    }
}

void CBill::RightKey(int action)
{
    switch (action)
    {
    case ON_KEY_DOWN:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_SWIM_IDLE)|| GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_WALK);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_WALK);
        left = false;
        right = true;
        break;
    case ON_KEY_UP:
        if (GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_IDLE);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_IDLE);
        break;
    case KEY_STATE:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK))
            SetState(BILL_STATE_SWIM_WALK);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            SetState(BILL_STATE_WALK);
        left = false;
        right = true;
        break;
    }
}

void CBill::DownKey(int action)
{
    switch (action)
    {
    case ON_KEY_DOWN:
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK) || GetState(BILL_STATE_SWIM_SIT))
            SetState(BILL_STATE_SWIM_SIT);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
        {
            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_UP) || GetState(BILL_STATE_WALK_LOOK_DOWN))
                SetState(BILL_STATE_WALK_LOOK_DOWN);
            else
                SetState(BILL_STATE_SIT);
        }
        break;

    case ON_KEY_UP:
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK) || GetState(BILL_STATE_SWIM_SIT))
            SetState(BILL_STATE_SWIM_IDLE);
        else if (GetState(BILL_STATE_SIT))
            SetState(BILL_STATE_IDLE);
        else  if (GetState(BILL_STATE_WALK_LOOK_DOWN))
            SetState(BILL_STATE_WALK);
        break;

    case KEY_STATE:
        if(GetState(BILL_STATE_SWIM_IDLE)||GetState(BILL_STATE_SWIM_WALK)||GetState(BILL_STATE_SWIM_SIT))
            SetState(BILL_STATE_SWIM_SIT);
        else if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
        {
            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_UP) || GetState(BILL_STATE_WALK_LOOK_DOWN))
                SetState(BILL_STATE_WALK_LOOK_DOWN);
            else
                SetState(BILL_STATE_SIT);
        }
    }
}

void CBill::UpKey(int action)
{
    switch (action)
    {
    case ON_KEY_DOWN:
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK) || GetState(BILL_STATE_SWIM_SIT))
            break;
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
        if (GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_WALK) || GetState(BILL_STATE_SWIM_SIT))
            SetState(BILL_STATE_SWIM_SIT);
        break;
        if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
        {
            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_UP))
                SetState(BILL_STATE_WALK_LOOK_UP);
            else
                SetState(BILL_STATE_LOOK_UP);
        }
        break;
    }
}

void CBill::JumpKey(int action)
{
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
}