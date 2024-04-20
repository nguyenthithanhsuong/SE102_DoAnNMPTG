#pragma once
#include <windows.h>

#include "MapRead.h"

extern Stage* stage1;
#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Bill.h"
#include "Greeder.h"
#include "Land.h"
#include "Title.h"

#include "SampleKeyEventHandler.h"
#include "ID.h"
#include "Tilemap.h"
#include "BinaryTree.h"

extern CBill* bill;
extern CBill* lance;
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
	void LoadGreeder();
	void LoadMap();
	void LoadTitle();
	void LoadOthers();
	void LoadStage1();
};