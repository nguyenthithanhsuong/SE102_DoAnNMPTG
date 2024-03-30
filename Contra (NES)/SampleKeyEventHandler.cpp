#include "SampleKeyEventHandler.h"


extern CBill* bill;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	bill->SetState(KeyCode, ON_KEY_DOWN);
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	bill->SetState(KeyCode, ON_KEY_UP);
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		bill->SetState(DIK_RIGHT, KEY_STATE);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		bill->SetState(DIK_LEFT, KEY_STATE);
	}
	else
	{
	}
	if (game->IsKeyDown(DIK_UP))
	{
		bill->SetState(DIK_UP, KEY_STATE);
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		bill->SetState(DIK_DOWN, KEY_STATE);
	}
}