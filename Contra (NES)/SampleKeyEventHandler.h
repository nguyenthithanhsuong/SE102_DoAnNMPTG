#pragma once

#include "KeyEventHandler.h"
#include "debug.h"
#include "Game.h"
#include "Bill.h"
#include "Title.h"
#include "ID.h"

class CSampleKeyHandler: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};
