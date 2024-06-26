#pragma once
#include <unordered_map>
#include <d3dx10.h>

#include "Texture.h"
#include "debug.h"
#include "Game.h"

using namespace std;

class CTextures
{
	static CTextures* __instance;

	unordered_map<int, LPTEXTURE> textures;

public:
	CTextures();
	void Add(int id, LPCWSTR filePath);
	LPTEXTURE Get(unsigned int i);
	void Clear();

	static CTextures* GetInstance();
};