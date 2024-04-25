#include "SampleKeyEventHandler.h"


extern CBill* bill;
extern CBill* lance;
extern CTitle* title;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	bill->SetState(KeyCode, ON_KEY_DOWN);
	lance->SetState(KeyCode, ON_KEY_DOWN);
	title->SetState(KeyCode, ON_KEY_DOWN);
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	bill->SetState(KeyCode, ON_KEY_UP);
	lance->SetState(KeyCode, ON_KEY_UP);
	title->SetState(KeyCode, ON_KEY_UP);
}

void CSampleKeyHandler::KeyState(BYTE* states)
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

	if (game->IsKeyDown(DIK_UP))
	{
		bill->SetState(DIK_UP, KEY_STATE);
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		bill->SetState(DIK_DOWN, KEY_STATE);
	}
	else if (game->IsKeyDown(DIK_RSHIFT))
	{
		bill->SetState(DIK_S, KEY_STATE);
	}


	if (game->IsKeyDown(DIK_D))
	{
		lance->SetState(DIK_D, KEY_STATE);
	}
	else if (game->IsKeyDown(DIK_A))
	{
		lance->SetState(DIK_A, KEY_STATE);
	}
	else
	{
	}
	if (game->IsKeyDown(DIK_W))
	{
		lance->SetState(DIK_W, KEY_STATE);
	}
	if (game->IsKeyDown(DIK_S))
	{
		lance->SetState(DIK_S, KEY_STATE);
	}


}