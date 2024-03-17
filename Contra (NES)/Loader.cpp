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
	animations->Add(ID_ANI_BILL_WALKING_RIGHT, ani);

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
	animations->Add(ID_ANI_BILL_WALKING_LEFT, ani);

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

	// JUMP WALK LEFT
	animations->Add(ID_ANI_BILL_JUMP_RIGHT, ani);
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
	objects.push_back(bill);
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
			objects.push_back(land);
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
			objects.push_back(sky);
		}
	}
}
