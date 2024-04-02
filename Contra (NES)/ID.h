#pragma once

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Contra (NES) testing"
#define WINDOW_ICON_PATH L"icon.ico"


#define BACKGROUND_COLOR D3DXCOLOR(255.0f/255, 255.0f/255, 255.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define LEVEL_LENGTH 800

#define ID_TEX_BILL 0
#define ID_TEX_MISC 10
#define ID_TEX_GREEDER 20
 
//toa do O doi xuong duoi ben trai - the gioi thuc, ko su dung ground_y khi co collision
//chi xai O tren trai cho ham ve/draw - the gioi ao
#define GROUND_Y 100.0f

#define TEXTURES_DIR L"textures"
#define TEXTURE_PATH_BILL TEXTURES_DIR "\\BillSprites.png"
#define TEXTURE_PATH_ENEMIES TEXTURES_DIR "\\Enemies.png"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\Misc.png"

//keyboard stuff
#define ON_KEY_UP 1
#define ON_KEY_DOWN 2
#define KEY_STATE 3

//LAND AND SKY STUFF

#define ID_ANI_LAND_0 2000
#define ID_ANI_LAND_1 2001
#define ID_ANI_LAND_2 2002
#define ID_ANI_LAND_3 2003
#define ID_ANI_LAND_4 2004
#define ID_ANI_LAND_5 2005
#define LAND_WIDTH 24

 //BILL STUFF

#define BILL_WIDTH 22.0f
#define BILL_HEIGHT 40.0f

#define BILL_START_X 30.0f
#define BILL_START_Y GROUND_Y + 50.0f

#define BILL_WALK_SPEED		0.1f
#define BILL_RUNNING_SPEED		0.2f

#define BILL_JUMP_SPEED_Y		0.45f

#define BILL_GRAVITY			0.0018f



#define BILL_STATE_IDLE			000

#define BILL_STATE_WALK	100

#define BILL_STATE_WALK_LOOK_UP	110

#define BILL_STATE_WALK_LOOK_DOWN 120

#define BILL_STATE_JUMP			130

#define BILL_STATE_RELEASE_JUMP    140

#define BILL_STATE_SIT			150

#define BILL_STATE_LOOK_UP		160



#define ID_ANI_BILL_IDLE_RIGHT 0000
#define ID_ANI_BILL_IDLE_LEFT 0001

#define ID_ANI_BILL_WALK_RIGHT 1000
#define ID_ANI_BILL_WALK_LEFT 1001

#define ID_ANI_BILL_WALK_LOOK_UP_RIGHT 1100
#define ID_ANI_BILL_WALK_LOOK_UP_LEFT 1101

#define ID_ANI_BILL_WALK_LOOK_DOWN_RIGHT 1200
#define ID_ANI_BILL_WALK_LOOK_DOWN_LEFT 1201

#define ID_ANI_BILL_JUMP_RIGHT 1300
#define ID_ANI_BILL_JUMP_LEFT 1301

#define ID_ANI_BILL_SIT_RIGHT 1500
#define ID_ANI_BILL_SIT_LEFT 1501

#define ID_ANI_BILL_LOOK_UP_RIGHT 1600
#define ID_ANI_BILL_LOOK_UP_LEFT 1601

// GREEDER STUFF

#define GREEDER_WIDTH 22.0f
#define GREEDER_HEIGHT 40.0f

#define GREEDER_START_X 50.0f
#define GREEDER_START_Y GROUND_Y

#define ID_ANI_GREEDER_RUN_LEFT 20010

#define GREEDER_RUNNING_SPEED		0.1f

