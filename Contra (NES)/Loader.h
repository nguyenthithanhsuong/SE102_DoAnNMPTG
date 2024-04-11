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
#include "Lance.h"
#include "Greeder.h"
#include "Land.h"
#include "Title.h"

#include "SampleKeyEventHandler.h"
#include "ID.h"
#include "Tilemap.h"
#include "BinaryTree.h"

extern CBill* bill;
extern CLance* lance;
extern CLand* land;
extern CGame* game;
extern CGreeder* greeder;
extern CTitle* title;

extern CSampleKeyHandler* keyHandler;
extern QNode* Tree;

class Loader
{
public:
	void LoadBill();
	void LoadLance();
	void LoadLand();
	void LoadSky();
	void LoadGreeder();
	void LoadMap();
	void LoadTitle();
};