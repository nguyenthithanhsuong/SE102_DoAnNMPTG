#include "Game.h"
#include "debug.h"

void CGame::Draw(float x, float y, LPTEXTURE tex, RECT* rect, float alpha)
{
	if (tex == NULL) return;

	int spriteWidth = 0;
	int spriteHeight = 0;

	D3DX10_SPRITE sprite;

	sprite.pTexture = tex->getShaderResourceView();

	if (rect == NULL)
	{
		sprite.TexCoord.x = 0;
		sprite.TexCoord.y = 0;

		sprite.TexSize.x = 1.0f;
		sprite.TexSize.y = 1.0f;

		spriteWidth = tex->getWidth();
		spriteHeight = tex->getHeight();
	}
	else
	{
		sprite.TexCoord.x = rect->left / (float)tex->getWidth();
		sprite.TexCoord.y = rect->top / (float)tex->getHeight();

		spriteWidth = (rect->right - rect->left + 1);
		spriteHeight = (rect->bottom - rect->top + 1);

		sprite.TexSize.x = spriteWidth / (float)tex->getWidth();
		sprite.TexSize.y = spriteHeight / (float)tex->getHeight();
	}

	sprite.TextureIndex = 0;

	sprite.ColorModulate = D3DXCOLOR(1.0f, 1.0f, 1.0f, alpha);

	D3DXMATRIX matTranslation;
	D3DXMatrixTranslation(&matTranslation, sprite.TexCoord.x, sprite.TexCoord.y, 0.1f);

	// Scale the sprite to its correct width and height
	D3DXMATRIX matScaling;
	D3DXMatrixScaling(&matScaling, sprite.TexSize.x, sprite.TexSize.y, 1.0f);

	// Combine translation and scaling matrices
	D3DXMATRIX matWorld = matScaling * matTranslation;

	// Set the sprite's position and size
	sprite.matWorld = matWorld;

	spriteObject->DrawSpritesImmediate(&sprite, 1, 0, 0);
}

LPTEXTURE CGame::LoadTexture(LPCWSTR texturePath)
{
	ID3D10Resource* pD3D10Resource = NULL;
	ID3D10Texture2D* tex = NULL;

	D3DX10_IMAGE_INFO imageInfo;
	HRESULT hr = D3DX10GetImageInfoFromFile(texturePath, NULL, &imageInfo, NULL);
	if (FAILED(hr))
	{
		DebugOut((wchar_t*)L"[ERROR] D3DX10GetImageInfoFromFile failed for  file: %s with error: %d\n", texturePath, hr);
		return NULL;
	}

	D3DX10_IMAGE_LOAD_INFO info;
	ZeroMemory(&info, sizeof(D3DX10_IMAGE_LOAD_INFO));
	info.Width = imageInfo.Width;
	info.Height = imageInfo.Height;
	info.Depth = imageInfo.Depth;
	info.FirstMipLevel = 0;
	info.MipLevels = 1;
	info.Usage = D3D10_USAGE_DEFAULT;
	info.BindFlags = D3DX10_DEFAULT;
	info.CpuAccessFlags = D3DX10_DEFAULT;
	info.MiscFlags = D3DX10_DEFAULT;
	info.Format = imageInfo.Format;
	info.Filter = D3DX10_FILTER_NONE;
	info.MipFilter = D3DX10_DEFAULT;
	info.pSrcInfo = &imageInfo;

	hr = D3DX10CreateTextureFromFile(pD3DDevice,
		texturePath,
		&info,
		NULL,
		&pD3D10Resource,
		NULL);

	if (FAILED(hr))
	{
		DebugOut((wchar_t*)L"[ERROR] Failed to load texture file: %s with error: %d\n", texturePath, hr);
		return NULL;
	}

	pD3D10Resource->QueryInterface(__uuidof(ID3D10Texture2D), (LPVOID*)&tex);
	pD3D10Resource->Release();

	if (!tex) {
		DebugOut((wchar_t*)L"[ERROR] Failed to convert from ID3D10Resource to ID3D10Texture2D \n");
		return NULL;
	}
	D3D10_TEXTURE2D_DESC desc;
	tex->GetDesc(&desc);

	D3D10_SHADER_RESOURCE_VIEW_DESC SRVDesc;

	ZeroMemory(&SRVDesc, sizeof(SRVDesc));

	SRVDesc.Format = desc.Format;

	SRVDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURE2D;
	SRVDesc.Texture2D.MipLevels = desc.MipLevels;

	ID3D10ShaderResourceView* gSpriteTextureRV = NULL;

	pD3DDevice->CreateShaderResourceView(tex, &SRVDesc, &gSpriteTextureRV);

	DebugOut(L"[INFO] Texture loaded Ok from file: %s \n", texturePath);

	return new CTexture(tex, gSpriteTextureRV);
}


