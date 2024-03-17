#pragma once
#include <windows.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Bill.h"
#include "Land.h"

#include "SampleKeyEventHandler.h"
#include "ID.h"
#include "Tilemap.h"

extern CBill* bill;
extern CLand* land;
extern CGame* game;

extern CSampleKeyHandler* keyHandler;

extern list<LPGAMEOBJECT> objects;

class Loader
{
public:
	void LoadBill();
	void LoadLand();
	void LoadSky();
};