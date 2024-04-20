#include "Loader.h"

void Loader::LoadBill()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_BILL, TEXTURE_PATH_BILL);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texBill = textures->Get(ID_TEX_BILL);
	LPANIMATION ani;
	ani = new CAnimation(100);

	//idle right
	sprites->Add(10000, 521, 1, 584, 64, texBill);
	ani = new CAnimation(100);
	ani->Add(10000);
	animations->Add(ID_ANI_BILL_IDLE_RIGHT, ani);

	//idle right SHOOT
	sprites->Add(12000, 521, 1, 584, 64, texBill);
	sprites->Add(12001, 716, 1, 779, 64, texBill);
	ani = new CAnimation(100);
	ani->Add(12000);
	ani->Add(12001);
	animations->Add(ID_ANI_BILL_IDLE_RIGHT_SHOOT, ani);

	//walk right
	sprites->Add(10001, 1, 1, 64, 64, texBill);
	sprites->Add(10002, 66, 1, 129, 64, texBill);
	sprites->Add(10003, 131, 1, 194, 64, texBill);
	sprites->Add(10004, 196, 1, 259, 64, texBill);
	sprites->Add(10005, 261, 1, 324, 64, texBill);
	sprites->Add(10006, 326, 1, 389, 64, texBill);
	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	ani->Add(10004);
	ani->Add(10005);
	ani->Add(10006);
	animations->Add(ID_ANI_BILL_WALK_RIGHT, ani);

	//walk right SHOOT
	sprites->Add(12001, 391, 1, 454, 64, texBill);
	sprites->Add(12002, 651, 1, 714, 64, texBill);
	sprites->Add(12003, 521, 1, 584, 64, texBill);
	ani = new CAnimation(100);
	ani->Add(12001);
	ani->Add(12002);
	ani->Add(12003);
	animations->Add(ID_ANI_BILL_WALK_RIGHT_SHOOT, ani);

	//idle left
	sprites->Add(10010, 456, 261, 519, 324, texBill);
	ani = new CAnimation(100);
	ani->Add(10010);
	animations->Add(ID_ANI_BILL_IDLE_LEFT, ani);

	//walk left
	sprites->Add(10011, 976, 262, 1039, 325, texBill);
	sprites->Add(10012, 911, 262, 974, 325, texBill);
	sprites->Add(10013, 846, 262, 909, 325, texBill);
	sprites->Add(10014, 781, 262, 844, 325, texBill);
	sprites->Add(10015, 716, 262, 779, 325, texBill);
	sprites->Add(10016, 651, 262, 714, 325, texBill);
	ani = new CAnimation(100);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	ani->Add(10016);
	animations->Add(ID_ANI_BILL_WALK_LEFT, ani);

	// JUMP WALK RIGHT
	sprites->Add(10021, 781, 66, 844, 129, texBill);
	sprites->Add(10022, 781 + 65, 66, 844 + 65, 129, texBill);
	sprites->Add(10023, 781 + 65 * 2, 66, 844 + 65 * 2, 129, texBill);
	sprites->Add(10024, 781 + 65 * 3, 66, 844 + 65 * 3, 129, texBill);
	ani = new CAnimation(100);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(ID_ANI_BILL_JUMP_RIGHT, ani);

	// JUMP WALK LEFT
	sprites->Add(10025, 196, 326, 259, 389, texBill);
	sprites->Add(10026, 196 - 65, 326, 259 - 65, 389, texBill);
	sprites->Add(10027, 196 - 65 * 2, 326, 259 - 65 * 2, 389, texBill);
	sprites->Add(10028, 196 - 65 * 3, 326, 259 - 65 * 3, 389, texBill);
	ani = new CAnimation(100);
	ani->Add(10025);
	ani->Add(10026);
	ani->Add(10027);
	ani->Add(10028);
	animations->Add(ID_ANI_BILL_JUMP_LEFT, ani);

	// LOOK UP RIGHT AND LEFT
	sprites->Add(10031, 781, 1, 844, 64, texBill);
	sprites->Add(10032, 196, 261, 259, 324, texBill);
	ani = new CAnimation(100);
	ani->Add(10031);
	animations->Add(ID_ANI_BILL_LOOK_UP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10032);
	animations->Add(ID_ANI_BILL_LOOK_UP_LEFT, ani);
	// SIT RIGHT/LEFT
	sprites->Add(10051, 911, 1, 974, 64, texBill);
	sprites->Add(10052, 66, 261, 129, 324, texBill);
	ani = new CAnimation(100);
	ani->Add(10051);
	animations->Add(ID_ANI_BILL_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10052);
	animations->Add(ID_ANI_BILL_SIT_LEFT, ani);

	// WALK LOOK UP RIGHT
	sprites->Add(10061, 1, 66, 64, 129, texBill);
	sprites->Add(10062, 66, 66, 129, 129, texBill);
	sprites->Add(10063, 131, 66, 194, 129, texBill);
	sprites->Add(10064, 196, 66, 259, 129, texBill);
	sprites->Add(10065, 261, 66, 324, 129, texBill);
	sprites->Add(10066, 326, 66, 389, 129, texBill);
	ani = new CAnimation(100);
	ani->Add(10061);
	ani->Add(10062);
	ani->Add(10063);
	ani->Add(10064);
	ani->Add(10065);
	ani->Add(10066);
	animations->Add(ID_ANI_BILL_WALK_LOOK_UP_RIGHT, ani);

	//WALK LOOK UP LEFT
	sprites->Add(10071, 976, 327, 1039, 390, texBill);
	sprites->Add(10072, 911, 327, 974, 390, texBill);
	sprites->Add(10073, 846, 327, 909, 390, texBill);
	sprites->Add(10074, 781, 327, 844, 390, texBill);
	sprites->Add(10075, 716, 327, 779, 390, texBill);
	sprites->Add(10076, 651, 327, 714, 390, texBill);
	ani = new CAnimation(100);
	ani->Add(10071);
	ani->Add(10072);
	ani->Add(10073);
	ani->Add(10074);
	ani->Add(10075);
	ani->Add(10076);
	animations->Add(ID_ANI_BILL_WALK_LOOK_UP_LEFT, ani);

	// WALK LOOK DOWN RIGHT
	sprites->Add(10081, 391, 66, 454, 129, texBill);
	sprites->Add(10082, 456, 66, 519, 129, texBill);
	sprites->Add(10083, 521, 66, 584, 129, texBill);
	sprites->Add(10084, 586, 66, 649, 129, texBill);
	sprites->Add(10085, 651, 66, 714, 129, texBill);
	sprites->Add(10086, 716, 66, 779, 129, texBill);
	ani = new CAnimation(100);
	ani->Add(10081);
	ani->Add(10082);
	ani->Add(10083);
	ani->Add(10084);
	ani->Add(10085);
	ani->Add(10086);
	animations->Add(ID_ANI_BILL_WALK_LOOK_DOWN_RIGHT, ani);

	//WALK LOOK DOWN LEFT
	sprites->Add(10091, 586, 327, 649, 390, texBill);
	sprites->Add(10092, 521, 327, 584, 390, texBill);
	sprites->Add(10093, 456, 327, 519, 390, texBill);
	sprites->Add(10094, 391, 327, 454, 390, texBill);
	sprites->Add(10095, 326, 327, 389, 390, texBill);
	sprites->Add(10096, 261, 327, 324, 390, texBill);
	ani = new CAnimation(100);
	ani->Add(10091);
	ani->Add(10092);
	ani->Add(10093);
	ani->Add(10094);
	ani->Add(10095);
	ani->Add(10096);
	animations->Add(ID_ANI_BILL_WALK_LOOK_DOWN_LEFT, ani);

	//swim right
	sprites->Add(10100, 66, 131  , 129, 194  , texBill);
	sprites->Add(10101, 131, 131  , 194, 194  , texBill);
	ani = new CAnimation(100);
	ani->Add(10100);
	ani->Add(10100);
	ani->Add(10101);
	ani->Add(10101);
	animations->Add(ID_ANI_BILL_SWIM_RIGHT, ani);

	//swim left
	sprites->Add(10110, 911, 391  , 974, 454  , texBill);
	sprites->Add(10111, 846, 391  , 909, 454  , texBill);
	ani = new CAnimation(100);
	ani->Add(10110);
	ani->Add(10110);
	ani->Add(10111);
	ani->Add(10111);
	animations->Add(ID_ANI_BILL_SWIM_LEFT, ani);

	//swim under
	sprites->Add(10120, 586, 131 , 649, 194  , texBill);
	sprites->Add(10121, 651, 131 , 714, 194  , texBill);
	ani = new CAnimation(100);
	ani->Add(10120);
	ani->Add(10120);
	ani->Add(10121);
	ani->Add(10121);
	animations->Add(ID_ANI_BILL_SWIM_UNDER, ani);


	bill = new CBill(BILL_START_X, BILL_START_Y, true);
	Tree->Insert(bill);
}

void Loader::LoadLance()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_LANCE, TEXTURE_PATH_LANCE);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texLance = textures->Get(ID_TEX_LANCE);
	LPANIMATION ani;
	ani = new CAnimation(100);

	//idle right
	sprites->Add(30000, 716, 1, 779, 64, texLance);
	ani->Add(30000);
	animations->Add(ID_ANI_LANCE_IDLE_RIGHT, ani);

	//walk right
	sprites->Add(30001, 1, 1, 64, 64, texLance);
	sprites->Add(30002, 66, 1, 129, 64, texLance);
	sprites->Add(30003, 131, 1, 194, 64, texLance);
	sprites->Add(30004, 196, 1, 259, 64, texLance);
	sprites->Add(30005, 261, 1, 324, 64, texLance);
	sprites->Add(30006, 326, 1, 389, 64, texLance);
	ani = new CAnimation(100);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30003);
	ani->Add(30004);
	ani->Add(30005);
	ani->Add(30006);
	animations->Add(ID_ANI_LANCE_WALK_RIGHT, ani);

	//idle left
	sprites->Add(30010, 456, 261, 519, 324, texLance);
	ani = new CAnimation(100);
	ani->Add(30010);
	animations->Add(ID_ANI_LANCE_IDLE_LEFT, ani);

	//walk left
	sprites->Add(30011, 976, 262, 1039, 325, texLance);
	sprites->Add(30012, 911, 262, 974, 325, texLance);
	sprites->Add(30013, 846, 262, 909, 325, texLance);
	sprites->Add(30014, 781, 262, 844, 325, texLance);
	sprites->Add(30015, 716, 262, 779, 325, texLance);
	sprites->Add(30016, 651, 262, 714, 325, texLance);
	ani = new CAnimation(100);
	ani->Add(30011);
	ani->Add(30012);
	ani->Add(30013);
	ani->Add(30014);
	ani->Add(30015);
	ani->Add(30016);
	animations->Add(ID_ANI_LANCE_WALK_LEFT, ani);

	// JUMP WALK RIGHT
	sprites->Add(30021, 781, 66, 844, 129, texLance);
	sprites->Add(30022, 781 + 65, 66, 844 + 65, 129, texLance);
	sprites->Add(30023, 781 + 65 * 2, 66, 844 + 65 * 2, 129, texLance);
	sprites->Add(30024, 781 + 65 * 3, 66, 844 + 65 * 3, 129, texLance);
	ani = new CAnimation(100);
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30023);
	ani->Add(30024);
	animations->Add(ID_ANI_LANCE_JUMP_RIGHT, ani);

	// JUMP WALK LEFT
	sprites->Add(30025, 196, 326, 259, 389, texLance);
	sprites->Add(30026, 196 - 65, 326, 259 - 65, 389, texLance);
	sprites->Add(30027, 196 - 65 * 2, 326, 259 - 65 * 2, 389, texLance);
	sprites->Add(30028, 196 - 65 * 3, 326, 259 - 65 * 3, 389, texLance);
	ani = new CAnimation(100);
	ani->Add(30025);
	ani->Add(30026);
	ani->Add(30027);
	ani->Add(30028);
	animations->Add(ID_ANI_LANCE_JUMP_LEFT, ani);

	// LOOK UP RIGHT AND LEFT
	sprites->Add(30031, 781, 1, 844, 64, texLance);
	sprites->Add(30032, 196, 261, 259, 324, texLance);
	ani = new CAnimation(100);
	ani->Add(30031);
	animations->Add(ID_ANI_LANCE_LOOK_UP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(30032);
	animations->Add(ID_ANI_LANCE_LOOK_UP_LEFT, ani);
	// SIT RIGHT/LEFT
	sprites->Add(30051, 911, 1, 974, 64, texLance);
	sprites->Add(30052, 66, 261, 129, 324, texLance);
	ani = new CAnimation(100);
	ani->Add(30051);
	animations->Add(ID_ANI_LANCE_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(30052);
	animations->Add(ID_ANI_LANCE_SIT_LEFT, ani);

	// WALK LOOK UP RIGHT
	sprites->Add(10061, 1, 66, 64, 129, texLance);
	sprites->Add(10062, 66, 66, 129, 129, texLance);
	sprites->Add(10063, 131, 66, 194, 129, texLance);
	sprites->Add(10064, 196, 66, 259, 129, texLance);
	sprites->Add(10065, 261, 66, 324, 129, texLance);
	sprites->Add(10066, 326, 66, 389, 129, texLance);
	ani = new CAnimation(100);
	ani->Add(10061);
	ani->Add(10062);
	ani->Add(10063);
	ani->Add(10064);
	ani->Add(10065);
	ani->Add(10066);
	animations->Add(ID_ANI_LANCE_WALK_LOOK_UP_RIGHT, ani);

	//WALK LOOK UP LEFT
	sprites->Add(10071, 976, 327, 1039, 390, texLance);
	sprites->Add(10072, 911, 327, 974, 390, texLance);
	sprites->Add(10073, 846, 327, 909, 390, texLance);
	sprites->Add(10074, 781, 327, 844, 390, texLance);
	sprites->Add(10075, 716, 327, 779, 390, texLance);
	sprites->Add(10076, 651, 327, 714, 390, texLance);
	ani = new CAnimation(100);
	ani->Add(10071);
	ani->Add(10072);
	ani->Add(10073);
	ani->Add(10074);
	ani->Add(10075);
	ani->Add(10076);
	animations->Add(ID_ANI_LANCE_WALK_LOOK_UP_LEFT, ani);

	// WALK LOOK DOWN RIGHT
	sprites->Add(10081, 391, 66, 454, 129, texLance);
	sprites->Add(10082, 456, 66, 519, 129, texLance);
	sprites->Add(10083, 521, 66, 584, 129, texLance);
	sprites->Add(10084, 586, 66, 649, 129, texLance);
	sprites->Add(10085, 651, 66, 714, 129, texLance);
	sprites->Add(10086, 716, 66, 779, 129, texLance);
	ani = new CAnimation(100);
	ani->Add(10081);
	ani->Add(10082);
	ani->Add(10083);
	ani->Add(10084);
	ani->Add(10085);
	ani->Add(10086);
	animations->Add(ID_ANI_LANCE_WALK_LOOK_DOWN_RIGHT, ani);

	//WALK LOOK DOWN LEFT
	sprites->Add(10091, 586, 327, 649, 390, texLance);
	sprites->Add(10092, 521, 327, 584, 390, texLance);
	sprites->Add(10093, 456, 327, 519, 390, texLance);
	sprites->Add(10094, 391, 327, 454, 390, texLance);
	sprites->Add(10095, 326, 327, 389, 390, texLance);
	sprites->Add(10096, 261, 327, 324, 390, texLance);
	ani = new CAnimation(100);
	ani->Add(10091);
	ani->Add(10092);
	ani->Add(10093);
	ani->Add(10094);
	ani->Add(10095);
	ani->Add(10096);
	animations->Add(ID_ANI_LANCE_WALK_LOOK_DOWN_LEFT, ani);

	lance = new CBill(LANCE_START_X, LANCE_START_Y, false);
}

void Loader::LoadGreeder()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_GREEDER, TEXTURE_PATH_ENEMIES);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texGreeder = textures->Get(ID_TEX_GREEDER);

	//run left
	sprites->Add(20011, 649, 17, 664, 48, texGreeder);
	sprites->Add(20012, 666, 17, 681, 48, texGreeder);
	sprites->Add(20013, 683, 17, 698, 48, texGreeder);
	sprites->Add(20014, 700, 17, 715, 48, texGreeder);
	sprites->Add(20015, 717, 17, 732, 48, texGreeder);
	sprites->Add(20016, 734, 17, 749, 48, texGreeder);

	LPANIMATION ani;
	ani = new CAnimation(50);
	ani->Add(20011);
	ani->Add(20012);
	ani->Add(20013);
	ani->Add(20014);
	ani->Add(20015);
	ani->Add(20016);
	animations->Add(ID_ANI_GREEDER_RUN_LEFT, ani);

	//run right
	sprites->Add(20017, 908 - 664, 459, 908 - 649, 490, texGreeder);
	sprites->Add(20018, 908 - 681, 459, 908 - 666, 490, texGreeder);
	sprites->Add(20019, 908 - 698, 459, 908 - 683, 490, texGreeder);
	sprites->Add(20020, 908 - 715, 459, 908 - 700, 490, texGreeder);
	sprites->Add(20021, 908 - 732, 459, 908 - 717, 490, texGreeder);
	sprites->Add(20022, 908 - 749, 459, 908 - 734, 490, texGreeder);
	ani = new CAnimation(50);
	ani->Add(20017);
	ani->Add(20018);
	ani->Add(20019);
	ani->Add(20020);
	ani->Add(20021);
	ani->Add(20022);
	animations->Add(ID_ANI_GREEDER_RUN_RIGHT, ani);
}

void Loader::LoadMap()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MAP_STAGE_1, TEXTURE_PATH_STAGE_1_MAP);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texMAP = textures->Get(ID_TEX_MAP_STAGE_1);
	LPANIMATION ani;

	for (int i = 0; i < 103; i++)
	{
		sprites->Add(30000 + i, 0 + 32 * i, 0, 31 + 32 * i, 31, texMAP);
		ani = new CAnimation(100);
		ani->Add(30000 + i);
		animations->Add(ID_ANI_STAGE_1_0 + i, ani);
	}

	Tilemap* tilemap = new Tilemap();
	tilemap->FetchTilemap();
	for (int i = 0; i < tilemap->row; i++)
	{
		for (int j = 0; j < tilemap->column; j++)
		{
			CLand* land = new CLand(10.0f + MAP_TILE_WIDTH * j, SCREEN_HEIGHT - MAP_TILE_WIDTH * i - MAP_TILE_WIDTH * 3 / 2);
			land->SetState(tilemap->tilemaparray[i][j]);
			Tree->Insert(land);
		}
	}
}

void Loader::LoadTitle()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_TITLE, TEXTURE_PATH_TITLE);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texTitle = textures->Get(ID_TEX_TITLE);
	LPANIMATION ani;

	//BG
	sprites->Add(40041, 0, 0, 194, 207, texTitle);
	ani = new CAnimation(100);
	ani->Add(40041);
	animations->Add(ID_ANI_TITLE_RUN_RIGHT, ani);

	//Choice1
	sprites->Add(40011, 29, 214, 93, 220, texTitle);
	ani = new CAnimation(100);
	ani->Add(40011);
	animations->Add(ID_MENU1, ani);

	//Choice2
	sprites->Add(40021, 105, 214, 177, 220, texTitle);
	ani = new CAnimation(100);
	ani->Add(40021);
	animations->Add(ID_MENU2, ani);

	//Badge
	sprites->Add(40031, 0, 213, 15, 222, texTitle);
	ani = new CAnimation(100);
	ani->Add(40031);
	animations->Add(ID_BADGE, ani);

	title = new CTitle(TITLE_START_X, TITLE_START_Y, TITLE_SPEED);
}

void Loader::LoadOthers()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_BULLET, TEXTURE_PATH_MISC);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texBullet = textures->Get(ID_TEX_BULLET);
	LPANIMATION ani;
	ani = new CAnimation(100);

	//idle right
	sprites->Add(10000, 591, 22, 593, 25, texBullet);
	ani->Add(10000);
	animations->Add(ID_ANI_BULLET, ani);
}

void Loader::LoadStage1()
{
	CGreeder* greeder;
	for (int i = 0; i < stage1->MobCount; ++i)
	{
		switch (stage1->Mobs[i].type)
		{
		case 1:
			greeder = new CGreeder(stage1->Mobs[i].x, stage1->Mobs[i].y, GREEDER_RUNNING_SPEED);
			Tree->Insert(greeder);
			break; // Add break statement to exit the switch block
		default:
			break;
		}
	}
}
