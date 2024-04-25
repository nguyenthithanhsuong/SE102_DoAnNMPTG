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
        if (RenderShoot > 0)
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
                case (BILL_STATE_FALL):
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
                    aniId = ID_ANI_BILL_SWIM_LEFT_SHOOT;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_WALK):
                    aniId = ID_ANI_BILL_SWIM_LEFT_SHOOT;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_SIT):
                    aniId = ID_ANI_BILL_SWIM_UNDER;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_LOOK_UP):
                    aniId = ID_ANI_BILL_SWIM_LOOK_UP_LEFT;
                    y2 -= offset;
                    break;
                }

            else if (!left && right)
                switch (state)
                {
                case BILL_STATE_IDLE:
                    aniId = ID_ANI_BILL_IDLE_RIGHT_SHOOT;
                    break;
                case BILL_STATE_WALK:
                    aniId = ID_ANI_BILL_WALK_RIGHT_SHOOT;
                    break;
                case BILL_STATE_JUMP:
                    aniId = ID_ANI_BILL_JUMP_RIGHT;
                    break;
                case BILL_STATE_FALL:
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
                    aniId = aniId = ID_ANI_BILL_SWIM_RIGHT_SHOOT;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_WALK):
                    aniId = aniId = ID_ANI_BILL_SWIM_RIGHT_SHOOT;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_SIT):
                    aniId = ID_ANI_BILL_SWIM_UNDER;
                    y2 -= offset;
                    break;
                case (BILL_STATE_SWIM_LOOK_UP):
                    aniId = ID_ANI_BILL_SWIM_LOOK_UP_RIGHT;
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
                    aniId = ID_ANI_BILL_IDLE_LEFT;
                    break;
                case (BILL_STATE_WALK):
                    aniId = ID_ANI_BILL_WALK_LEFT;
                    break;
                case (BILL_STATE_JUMP):
                    aniId = ID_ANI_BILL_JUMP_LEFT;
                    break;
                case (BILL_STATE_FALL):
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
                case (BILL_STATE_SWIM_LOOK_UP):
                    aniId = ID_ANI_BILL_SWIM_LOOK_UP_LEFT;
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
                case BILL_STATE_FALL:
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
                case (BILL_STATE_SWIM_LOOK_UP):
                    aniId = ID_ANI_BILL_SWIM_LOOK_UP_RIGHT;
                    y2 -= offset;
                    break;
                }
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
            case (BILL_STATE_FALL):
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
                break;
            case (BILL_STATE_SWIM_IDLE):
                if (RenderShoot > 0)
                    aniId = ID_ANI_LANCE_SWIM_LEFT_SHOOT;
                else
                    aniId = ID_ANI_LANCE_SWIM_LEFT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_WALK):
                if (RenderShoot > 0)
                    aniId = ID_ANI_LANCE_SWIM_LEFT_SHOOT;
                else
                    aniId = ID_ANI_LANCE_SWIM_LEFT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_SIT):
                aniId = ID_ANI_LANCE_SWIM_UNDER;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_LOOK_UP):
                aniId = ID_ANI_BILL_SWIM_LOOK_UP_LEFT;
                y2 -= offset;
                break;

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
            case BILL_STATE_FALL:
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
            case (BILL_STATE_SWIM_IDLE):
                if (RenderShoot > 0)
                    aniId = ID_ANI_LANCE_SWIM_RIGHT_SHOOT;
                else
                    aniId = ID_ANI_LANCE_SWIM_RIGHT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_WALK):
                if (RenderShoot > 0)
                    aniId = ID_ANI_LANCE_SWIM_RIGHT_SHOOT;
                else
                    aniId = ID_ANI_LANCE_SWIM_RIGHT;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_SIT):
                aniId = ID_ANI_LANCE_SWIM_UNDER;
                y2 -= offset;
                break;
            case (BILL_STATE_SWIM_LOOK_UP):
                aniId = ID_ANI_BILL_SWIM_LOOK_UP_RIGHT;
                y2 -= offset;
                break;
            }
    }
    animations->Get(aniId)->Render(x2, y2);
}


void CBill::Update(DWORD dt)
{ //cap nhat: kiem tra dieu kien truoc khi doi x y    

    vy -= GAME_GRAVITY * dt;

    if (cooldown > 0)
        cooldown--;
    else
        cooldown = 0;

    if (RenderShoot > 0)
        RenderShoot--;
    else
        RenderShoot = 0;

    DebugOut(L"cooldown = % i, Render = % i\n", cooldown, RenderShoot);
    if (left && !right)
    {
        nx = -1;
    }
    else if (!left && right)
    {
        nx = 1;
    }
    if (vy < -GAME_GRAVITY * dt)
        SetState(BILL_STATE_FALL);
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
    else if (GetState(BILL_STATE_FALL))
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
    else if ((GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_DOWN) || GetState(BILL_STATE_WALK_LOOK_UP)) || GetState(BILL_STATE_SWIM_WALK) || GetState(BILL_STATE_SWIM_SIT))
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
    else if (GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_SWIM_IDLE) || GetState(BILL_STATE_SWIM_SHOOT))
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
    if (GetState(BILL_STATE_SIT))
    {
        top = y - BILL_HEIGHT / 3;
        bottom = y - BILL_HEIGHT / 2;
        left = x - BILL_WIDTH;
        right = x + BILL_WIDTH;
    }
    else if (!isSwimming)
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

        case DIK_RSHIFT: //shoot
            ShootKey(action);

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
        case DIK_F: 
            ShootKey(action);
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
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;

        if (isSwimming)
            SetState(BILL_STATE_SWIM_WALK);
        else
            SetState(BILL_STATE_WALK);
        left = true;
        right = false;
        break;


    case ON_KEY_UP:
        if(isSwimming)
            SetState(BILL_STATE_SWIM_IDLE);
        else
            SetState(BILL_STATE_IDLE);
        break;


    case KEY_STATE:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;

        if (isSwimming)
            SetState(BILL_STATE_SWIM_WALK);
        else
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
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;

        if (isSwimming)
            SetState(BILL_STATE_SWIM_WALK);
        else
            SetState(BILL_STATE_WALK);
        right = true;
        left = false;
        break;


    case ON_KEY_UP:
        if (isSwimming)
            SetState(BILL_STATE_SWIM_IDLE);
        else
            SetState(BILL_STATE_IDLE);
        break;


    case KEY_STATE:
        if (GetState(BILL_STATE_SWIM_SIT))
            break;
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;

        if (isSwimming)
            SetState(BILL_STATE_SWIM_WALK);
        else
            SetState(BILL_STATE_WALK);
        right = true;
        left = false;
        break;


    }
}

void CBill::DownKey(int action)
{
    switch (action)
    {
    case ON_KEY_DOWN:
        if (isSwimming)
        {
            SetState(BILL_STATE_SWIM_SIT);
            break;
        }
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;
        else
        {
            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_WALK_LOOK_UP) || GetState(BILL_STATE_WALK_LOOK_DOWN))
                SetState(BILL_STATE_WALK_LOOK_DOWN);
            else
                SetState(BILL_STATE_SIT);
        }
        break;

    case ON_KEY_UP:
        if (isSwimming)
            SetState(BILL_STATE_SWIM_IDLE);
        else if (GetState(BILL_STATE_SIT))
            SetState(BILL_STATE_IDLE);
        else  if (GetState(BILL_STATE_WALK_LOOK_DOWN))
            SetState(BILL_STATE_WALK);
        break;

    case KEY_STATE:
        if (isSwimming)
        {
            SetState(BILL_STATE_SWIM_SIT);
            break;
        }
        if (GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL))
            break;
        else
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
        if (isSwimming) {
            SetState(BILL_STATE_SWIM_LOOK_UP);
            break;
        }
        if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_FALL))
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
        else if (GetState(BILL_STATE_SWIM_LOOK_UP)) SetState(BILL_STATE_SWIM_IDLE);
        break;
    case KEY_STATE:
        if (isSwimming)
            break;
        if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_FALL))
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

        if (isSwimming)
            break;
        if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_WALK_LOOK_DOWN) || GetState(BILL_STATE_WALK_LOOK_UP))
        {
            SetState(BILL_STATE_JUMP);
        }
        break;
    case ON_KEY_UP:
        if (GetState(BILL_STATE_JUMP))
        {
            SetState(BILL_STATE_FALL);
        }
        break;
    case KEY_STATE:
        break;
    }
}

void CBill::ShootKey(int action)
{
    if (cooldown > 0)
    { }
    else
    {
        int gun_height = 4;
        CBullet* bullet = NULL;
        switch (action)
        {
        case ON_KEY_DOWN:
            float l, b, t, r;
            GetBoundingBox(l, t, r, b);
            if ((GetState(BILL_STATE_IDLE) || GetState(BILL_STATE_WALK)
                || GetState(BILL_STATE_JUMP) || GetState(BILL_STATE_FALL)
                || GetState(BILL_STATE_SIT) || GetState(BILL_STATE_SWIM_WALK))||GetState(BILL_STATE_SWIM_IDLE))
            {
                if (right && !left)
                    bullet = new CBullet(r, (b + t) / 2 + gun_height, 0, true);
                else if (left && !right)
                    bullet = new CBullet(l, (b + t) / 2 + gun_height, 180, true);
                else
                    break;
            }
            else if (GetState(BILL_STATE_LOOK_UP) || GetState(BILL_STATE_SWIM_LOOK_UP))
                if (right && !left)
                {
                    bullet = new CBullet((l + r) / 2 + 4, t, 90, true);
                }
                else if (left && !right)
                {
                    bullet = new CBullet((l + r) / 2 - 4, t, 90, true);
                }
                else
                {

                }
            else if (GetState(BILL_STATE_WALK_LOOK_UP))
            {
                if (right && !left)
                    bullet = new CBullet(r + 5, t, 45, true);
                else if (left && !right)
                    bullet = new CBullet(l - 5, t, 135, true);
                else
                    break;
            }
            else if (GetState(BILL_STATE_WALK_LOOK_DOWN))
            {
                if (right && !left)
                    bullet = new CBullet(r + 5, (t + b) / 2, 315, true);
                else if (left && !right)
                    bullet = new CBullet(l - 5, (t + b) / 2, 225, true);
                else
                    break;
            }
            else
                break;
            if (bullet != NULL)
            {
                Tree->Insert(bullet);
                cooldown = BILL_COOLDOWN;
                RenderShoot = BILL_COOLDOWN - 5;
            }
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_SWIM_SHOOT)) SetState(BILL_STATE_SWIM_IDLE);
            break;

        case KEY_STATE:
            break;
        }
    }
}
