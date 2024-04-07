#pragma once
#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include "Texture.h"
#include "debug.h"
#include "KeyEventHandler.h"

#define MAX_FRAME_RATE 60
#define KEYBOARD_BUFFER_SIZE 1024
#define KEYBOARD_STATE_SIZE 256

class CGame
{
	static CGame* __instance;
	HWND hWnd;	

	//back buffer declaration
	int backBufferWidth = 0;
	int backBufferHeight = 0;

	//create d3dx10 device
	ID3D10Device* pD3DDevice = NULL;
	IDXGISwapChain* pSwapChain = NULL;
	ID3D10RenderTargetView* pRenderTargetView = NULL;
	ID3D10BlendState* pBlendStateAlpha = NULL;		

	//d3dx10 style sprite
	LPD3DX10SPRITE spriteObject;			

	//input
	LPDIRECTINPUT8       di;	       
	LPDIRECTINPUTDEVICE8 didv;	

	//keyboard processor
	BYTE  keyStates[KEYBOARD_STATE_SIZE];	
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];	

	//depth buffer
	ID3D10DepthStencilView* pDepthStencilView = NULL;
	ID3D10Texture2D* pDepthStencilBuffer = NULL;

	LPKEYEVENTHANDLER keyHandler;

	HINSTANCE hInstance;

	ID3D10SamplerState* pPointSamplerState;

public:
	void Init(HWND hWnd, HINSTANCE hInstance); //uses backbuffer to draw
	// Draw a portion or ALL the texture at position (x,y) on the screen. (x,y) is at the CENTER of the image
	// rect : if NULL, the whole texture will be drawn
	//        if NOT NULL, only draw that portion of the texture 
	void Draw(float x, float y, LPTEXTURE tex, RECT* rect = NULL, float alpha = 1.0f); 

	void Draw(float x, float y, LPTEXTURE tex, int l, int t, int r, int b, float alpha = 1.0f) 
	{
		/*RECT rect;
		rect.left = l;
		rect.top = t;
		rect.right = r;
		rect.bottom = b;
		this->Draw(x, y, tex, &rect, alpha);*/
	}

	LPTEXTURE LoadTexture(LPCWSTR texturePath);

	void InitKeyboard(LPKEYEVENTHANDLER handler);
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();
	void SetKeyHandler(LPKEYEVENTHANDLER handler) { keyHandler = handler; }

	//d3dx10 device processor
	ID3D10Device* GetDirect3DDevice() { return this->pD3DDevice; }
	IDXGISwapChain* GetSwapChain() { return this->pSwapChain; }
	ID3D10RenderTargetView* GetRenderTargetView() { return this->pRenderTargetView; }

	ID3DX10Sprite* GetSpriteHandler() { return this->spriteObject; }

	ID3D10BlendState* GetAlphaBlending() { return pBlendStateAlpha; };

	int GetBackBufferWidth() { return backBufferWidth; }
	int GetBackBufferHeight() { return backBufferHeight; }

	static CGame* GetInstance();

	void SetPointSamplerState();

	~CGame();
};
typedef CGame* LPGAME;

