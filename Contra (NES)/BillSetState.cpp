#include "Bill.h"
#include "Tilemap.h"
#include "ID.h"

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
            
            if (GetState(BILL_STATE_WALK) || GetState(BILL_STATE_IDLE))
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
                SetState(BILL_STATE_LOOK_UP);
            }
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_LOOK_UP))
            {
                SetState(BILL_STATE_IDLE);
            }
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_SIT) && !GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
            {
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
                SetState(BILL_STATE_SIT);
            break;
        case ON_KEY_UP:
            if (GetState(BILL_STATE_SIT))
                SetState(BILL_STATE_IDLE);
            break;
        case KEY_STATE:
            if (!GetState(BILL_STATE_JUMP) && !GetState(BILL_STATE_RELEASE_JUMP))
                SetState(BILL_STATE_SIT);
            break;
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
