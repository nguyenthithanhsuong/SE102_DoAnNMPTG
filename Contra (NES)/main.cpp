#include <windows.h>

#include "MapRead.h"

Stage* stage1 = new Stage();

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
#include "Title.h"
#include "Deleted.h";
#include "SampleKeyEventHandler.h"
#include "Tilemap.h"
#include "Loader.h"
#include "Camera.h"

int ObjectIDSet = 0;

CBill* bill = NULL;
CBill* lance = NULL;
CLand* land = NULL;
CGame* game;
CGreeder* greeder = NULL;
CShooter* shooter = NULL;
CCanon* canon = NULL;
CTurret* turret = NULL;
CBoss1* boss1 = NULL;
CBoss1Gun* bossgun1 = NULL;
CBoss1Gun* bossgun2 = NULL;
CTitle* title = NULL;
CBullet* bullet = NULL;

CCamera* Camera = new CCamera();
CSampleKeyHandler* keyHandler;

QNode* Tree = new QNode();

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void LoadResources()
{
	Loader load;
	load.LoadMap();
	load.LoadGreeder();
	load.LoadShooter();
	load.LoadTurret();
	load.LoadCanon();
	load.LoadBoss1();
	load.LoadTitle();
	load.LoadBill();
	load.LoadLance();
	load.LoadOthers();
	load.LoadStage1();
}

bool IsNodeVisible(QNode* node, float camX, float camY)
{
	float viewportLeft = camX;
	float viewportBottom = camY;
	float viewportRight = camX + Camera->cam_width; // Correctly calculate right coordinate
	float viewportTop = camY + Camera->cam_height; // Correctly calculate bottom coordinate

	return !((node->rightx < viewportLeft) ||
		(node->leftx > viewportRight));
}


void RenderNode(QNode* node, float camX, float camY) {

	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			for (auto& obj : node->objects)
			{
				if (IsNodeVisible(node, camX, camY) && !obj->IsDynamic)
					obj->Render();
			}
		}
		else
		{
			if (node->left != NULL)
				RenderNode(node->left, camX, camY);
			if (node->right != NULL)
				RenderNode(node->right, camX, camY);
		}
		for (auto& obj : node->objects)
		{
			if (obj->IsDynamic)
				obj->Render();
		}
	}
	else
		return;
}

void Render()
{
	CGame* g = CGame::GetInstance();
	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

	spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	FLOAT NewBlendFactor[4] = { 0,0,0,0 };
	pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

	// You can also update camera position here if necessary
	float camX, camY;
	Camera->GetCamPos(camX, camY);

	switch (title->scene)
	{
	case 0:
		title->Render();
		break;
	case 1:
		if (title->confirm == 2&&!title->LANCE_ADDED)
		{
			title->LANCE_ADDED = true;
			Tree->Insert(lance);
			title->confirm = 1;
		}
		RenderNode(Tree, camX, camY);
		break;
	}

	spriteHandler->End();
	pSwapChain->Present(0, 0);
}

void UpdateNodes(DWORD dt, QNode* node, float camX, float camY)
{
	float x = 0, y = 0;
	if (node != NULL)
	{
		if (node->level == Tree->HighestLevel(Tree))
		{
			if (IsNodeVisible(node, camX, camY))
			{
				for (auto& obj : node->objects) {
					obj->Update(dt);
					if (obj->IsDeleted(obj))
					{
						obj = new Deleted();
					}
					if (obj == bill)
					{
						bill->GetPosition(x, y);
						Camera->Update(x, y);
					}
					node->Get(obj, node, Tree);
					if (node->IsOnBoundary(obj) && obj->IsDynamic)
					{
						obj->Render();
					}
				}
			}
		}
		else
		{
			UpdateNodes(dt, node->left, camX, camY);
			UpdateNodes(dt, node->right, camX, camY);
		}
	}
	else
		return;
}

void Update(DWORD dt)
{
	float x, y;
	Camera->GetCamPos(x, y);

		switch (title->scene)
		{
		case 0:
			title->Update(dt);
			break;
		case 1:
			UpdateNodes(dt, Tree, x, y);
			break;
		}
	Render();
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		DWORD dt = (DWORD)(now - frameStart);
		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();
			Update(dt);
		}
		else
			Sleep(tickPerFrame - dt);
	}
	//a
	Tree->Clear(Tree);
	delete bill;
	delete land;
	delete game;
	return 1;
}


int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	SetDebugWindow(hWnd);

	game = CGame::GetInstance();
	game->Init(hWnd, hInstance);

	keyHandler = new CSampleKeyHandler();
	game->InitKeyboard(keyHandler);

	LoadResources();

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}