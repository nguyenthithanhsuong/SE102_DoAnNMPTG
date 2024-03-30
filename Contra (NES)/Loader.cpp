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
	sprites->Add(10000, 716, 1, 779, 64, texBill);
	ani->Add(10000);
	animations->Add(ID_ANI_BILL_IDLE_RIGHT, ani);

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

	bill = new CBill(BILL_START_X, BILL_START_Y);
	Tree->Insert(bill);

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
}

void Loader::LoadLand()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texLand = textures->Get(ID_TEX_MISC);
	LPANIMATION ani;

	sprites->Add(20001, 2, 2 + 26 * 0, 25, 25, texLand);
	ani = new CAnimation(100);
	ani->Add(20001);
	animations->Add(ID_ANI_LAND_1, ani);

	sprites->Add(20002, 2, 2 + 26 * 1, 25, 25 + 26 * 1, texLand);
	ani = new CAnimation(100);
	ani->Add(20002);
	animations->Add(ID_ANI_LAND_2, ani);

	sprites->Add(20003, 2, 2 + 26 * 2, 25, 25 + 26 * 2, texLand);
	ani = new CAnimation(100);
	ani->Add(20003);
	animations->Add(ID_ANI_LAND_3, ani);

	sprites->Add(20004, 2, 2 + 26 * 3, 25, 25 + 26 * 3, texLand);
	ani = new CAnimation(100);
	ani->Add(20004);
	animations->Add(ID_ANI_LAND_4, ani);

	sprites->Add(20005, 2, 2 + 26 * 4, 25, 25 + 26 * 4, texLand);
	ani = new CAnimation(100);
	ani->Add(20005);
	animations->Add(ID_ANI_LAND_5, ani);

	Tilemap* tilemap = new Tilemap();
	tilemap->FetchTilemap();
	for (int i = 0; i < tilemap->row; i++)
	{
		for (int j = 0; j < tilemap->column; j++)
		{
			CLand* land = new CLand(0.0f + LAND_WIDTH * j, GROUND_Y - LAND_WIDTH * i);
			land->SetState(tilemap->tilemaparray[i][j]);
			Tree->Insert(land);

			land = new CLand(200.0f, GROUND_Y);
			land->SetState(3);
			Tree->Insert(land);

			land = new CLand(0.0f, GROUND_Y);
			land->SetState(3);
			Tree->Insert(land);
		}
	}
}

void Loader::LoadSky()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texSky = textures->Get(ID_TEX_MISC);
	LPANIMATION ani;

	sprites->Add(20000, 28, 54, 51, 77, texSky);
	ani = new CAnimation(100);
	ani->Add(20000);
	animations->Add(ID_ANI_LAND_0, ani);
	for (int i = 0; i <= int(SCREEN_HEIGHT / LAND_WIDTH); i++)
	{
		for (int j = 0; j <= int(LEVEL_LENGTH / LAND_WIDTH); j++)
		{
			CLand* sky = new CLand(0.0f + LAND_WIDTH * j, GROUND_Y + LAND_WIDTH * i);
			sky->SetState(0);
			Tree->Insert(sky);
		}
	}
}
