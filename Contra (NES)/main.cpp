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
#include "Loader.h"
#include "Camera.h"

CBill* bill = NULL;
CLand* land = NULL;
CGame* game;
CGreeder* greeder = NULL;

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
	/*load.LoadSky();*/
	/*load.LoadLand();*/
	load.LoadMap();
	load.LoadBill();
	load.LoadGreeder();
}

bool IsNodeVisible(QNode* node, float camX, float camY) 
{
		float viewportLeft = camX;
		float viewportBottom = camY;
		float viewportRight = camX + SCREEN_WIDTH; // Correctly calculate right coordinate
		float viewportTop = camY + SCREEN_HEIGHT; // Correctly calculate bottom coordinate

		return !((node->rightx < viewportLeft - MAP_TILE_WIDTH) ||
			(node->leftx > viewportRight + MAP_TILE_WIDTH));
}

void RenderNode(QNode* node, float camX, float camY) {
	if (node->level == Tree->HighestLevel(Tree))
	{
		if (IsNodeVisible(node, camX, camY))
		{
			for (auto& obj : node->objects) {
				obj->Render();
			}
		}
	}
	else
	{
		RenderNode(node->left, camX, camY);
		RenderNode(node->right, camX, camY);
	}
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

	RenderNode(Tree, camX, camY);

	spriteHandler->End();
	pSwapChain->Present(0, 0);
}


void UpdateNodes(DWORD dt, QNode* node, float camX, float camY)
{
	float x=0, y=0;
	if (node->level == Tree->HighestLevel(Tree))
	{
		if (true/*IsNodeVisible(node, camX, camY)*/)
		{
			for (auto& obj : node->objects) {
				obj->Update(dt);
				if (obj == bill)
				{
					bill->GetPosition(x, y);
					Camera->Update(x, y);
				}
				node->Get(obj, node, Tree);
			}
		}
	}
	else
	{
		UpdateNodes(dt, node->left, camX, camY);
		UpdateNodes(dt, node->right, camX, camY);
	}
}
void Update(DWORD dt)
{
	float x, y;
	Camera->GetCamPos(x, y);
	UpdateNodes(dt, Tree, x, y);
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