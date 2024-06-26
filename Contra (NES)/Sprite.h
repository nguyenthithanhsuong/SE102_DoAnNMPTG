#pragma once

#include "Texture.h"
#include "Game.h"
#include "Camera.h"

extern CCamera* Camera;

class CSprite
{
	int id;
	int left;
	int top;
	int right;
	int bottom;

	//sprites
	LPTEXTURE texture;
	D3DX10_SPRITE sprite;
	D3DXMATRIX matScaling;
public:
	CSprite(int id, int left, int top, int right, int bottom, LPTEXTURE tex);

	void Draw(float x, float y);
};

typedef CSprite* LPSPRITE;