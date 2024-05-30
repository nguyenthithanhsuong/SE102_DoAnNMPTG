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
#include "Shooter.h"
#include "Turret.h"
#include "Canon.h"
#include "Boss1.h"
#include "Boss1_gun.h"
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
extern CShooter* shooter;
extern CTurret* turret;
extern CCanon* canon;
extern CBoss1* boss1;
extern CBoss1Gun* bossgun1;
extern CBoss1Gun* bossgun2;
extern CTitle* title;

extern CSampleKeyHandler* keyHandler;
extern QNode* Tree;

class Loader
{
public:
	void LoadBill();
	void LoadLance();
	void LoadGreeder();
	void LoadShooter();
	void LoadTurret();
	void LoadCanon();
	void LoadBoss1();
	void LoadMap();
	void LoadTitle();
	void LoadOthers();
	void LoadStage1();
};