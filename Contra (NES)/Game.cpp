#include "Game.h"

CGame* CGame::__instance = NULL;

void CGame::Init(HWND hWnd, HINSTANCE hInstance)
{
	this->hWnd = hWnd;
	this->hInstance = hInstance;

	RECT r;
	GetClientRect(hWnd, &r);

	backBufferWidth = r.right + 1;
	backBufferHeight = r.bottom + 1;

	DebugOut(L"[INFO] Window's client area: width= %d, height= %d\n", r.right - 1, r.bottom - 1);

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = backBufferWidth;
	swapChainDesc.BufferDesc.Height = backBufferHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = TRUE;

	HRESULT hr = D3D10CreateDeviceAndSwapChain(NULL,
		D3D10_DRIVER_TYPE_HARDWARE,
		NULL,
		0,
		D3D10_SDK_VERSION,
		&swapChainDesc,
		&pSwapChain,
		&pD3DDevice);

	if (hr != S_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] D3D10CreateDeviceAndSwapChain has failed %s %d", _W(__FILE__), __LINE__);
		return;
	}

	ID3D10Texture2D* pBackBuffer;
	hr = pSwapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), (LPVOID*)&pBackBuffer);
	if (hr != S_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] pSwapChain->GetBuffer has failed %s %d", _W(__FILE__), __LINE__);
		return;
	}

	hr = pD3DDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView);

	pBackBuffer->Release();
	if (hr != S_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] CreateRenderTargetView has failed %s %d", _W(__FILE__), __LINE__);
		return;
	}

	pD3DDevice->OMSetRenderTargets(1, &pRenderTargetView, NULL);

	D3D10_VIEWPORT viewPort;
	viewPort.Width = backBufferWidth;
	viewPort.Height = backBufferHeight;
	viewPort.MinDepth = 0.0f;
	viewPort.MaxDepth = 1.0f;
	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;
	pD3DDevice->RSSetViewports(1, &viewPort);


	D3D10_SAMPLER_DESC desc;
	desc.Filter = D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR;
	desc.AddressU = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.AddressV = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.AddressW = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.MipLODBias = 0;
	desc.MaxAnisotropy = 1;
	desc.ComparisonFunc = D3D10_COMPARISON_NEVER;
	desc.BorderColor[0] = 1.0f;
	desc.BorderColor[1] = 1.0f;
	desc.BorderColor[2] = 1.0f;
	desc.BorderColor[3] = 1.0f;
	desc.MinLOD = -FLT_MAX;
	desc.MaxLOD = FLT_MAX;

	pD3DDevice->CreateSamplerState(&desc, &this->pPointSamplerState);

	hr = D3DX10CreateSprite(pD3DDevice, 0, &spriteObject);

	if (hr != S_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] D3DX10CreateSprite has failed %s %d", _W(__FILE__), __LINE__);
		return;
	}

	D3DXMATRIX matProjection;

	// Create the projection matrix with the left-handed coordinate system
	D3DXMatrixOrthoOffCenterLH(&matProjection,
		0.0f,                                      // left
		static_cast<float>(backBufferWidth),      // right
		static_cast<float>(backBufferHeight),     // bottom
		0.0f,                                      // top
		0.1f,                                      // near plane
		10.0f);                                    // far plane

	// Apply a scaling transformation to flip the y-axis
	D3DXMATRIX matFlipY;
	D3DXMatrixScaling(&matFlipY, 1.0f, -1.0f, 1.0f);

	// Combine the projection matrix with the y-axis flipping matrix
	D3DXMATRIX finalProjection = matProjection * matFlipY;

	hr = spriteObject->SetProjectionTransform(&finalProjection);

	if (hr != S_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] SetProjectionTransform failed\n");
		return;
	}

	DebugOut((wchar_t*)L"[INFO] InitDirectX has been successful\n");

	D3D10_BLEND_DESC StateDesc;
	ZeroMemory(&StateDesc, sizeof(D3D10_BLEND_DESC));
	StateDesc.AlphaToCoverageEnable = FALSE;
	StateDesc.BlendEnable[0] = TRUE;
	StateDesc.SrcBlend = D3D10_BLEND_SRC_ALPHA;
	StateDesc.DestBlend = D3D10_BLEND_INV_SRC_ALPHA;
	StateDesc.BlendOp = D3D10_BLEND_OP_ADD;
	StateDesc.SrcBlendAlpha = D3D10_BLEND_ZERO;
	StateDesc.DestBlendAlpha = D3D10_BLEND_ZERO;
	StateDesc.BlendOpAlpha = D3D10_BLEND_OP_ADD;
	StateDesc.RenderTargetWriteMask[0] = D3D10_COLOR_WRITE_ENABLE_ALL;
	pD3DDevice->CreateBlendState(&StateDesc, &this->pBlendStateAlpha);

	DebugOut((wchar_t*)L"[INFO] InitDirectX has been successful\n");

	return;
}


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




void CGame::SetPointSamplerState()
{
	pD3DDevice->VSSetSamplers(0, 1, &pPointSamplerState);
	pD3DDevice->GSSetSamplers(0, 1, &pPointSamplerState);
	pD3DDevice->PSSetSamplers(0, 1, &pPointSamplerState);
}

int CGame::IsKeyDown(int KeyCode)
{
	return (keyStates[KeyCode] & 0x80) > 0;
}

void CGame::InitKeyboard(LPKEYEVENTHANDLER handler)
{
	HRESULT hr = DirectInput8Create(this->hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&di, NULL);
	if (hr != DI_OK)
	{
		DebugOut(L"[ERROR] DirectInput8Create failed!\n");
		return;
	}

	hr = di->CreateDevice(GUID_SysKeyboard, &didv, NULL);
	if (hr != DI_OK)
	{
		DebugOut(L"[ERROR] CreateDevice failed!\n");
		return;
	}

	hr = didv->SetDataFormat(&c_dfDIKeyboard);

	hr = didv->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE;

	hr = didv->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	hr = didv->Acquire();
	if (hr != DI_OK)
	{
		DebugOut(L"[ERROR] DINPUT8::Acquire failed!\n");
		return;
	}

	this->keyHandler = handler;

	DebugOut(L"[INFO] Keyboard has been initialized successfully\n");
}

void CGame::ProcessKeyboard()
{
	HRESULT hr;

	hr = didv->GetDeviceState(sizeof(keyStates), keyStates);
	if (FAILED(hr))
	{
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			HRESULT h = didv->Acquire();
			if (h == DI_OK)
			{
				DebugOut(L"[INFO] Keyboard re-acquired!\n");
			}
			else return;
		}
		else
		{
			DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
			return;
		}
	}

	keyHandler->KeyState((BYTE*)&keyStates);

	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	hr = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
		return;
	}

	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = keyEvents[i].dwOfs;
		int KeyState = keyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			keyHandler->OnKeyDown(KeyCode);
		else
			keyHandler->OnKeyUp(KeyCode);
	}
}


CGame::~CGame()
{
	pBlendStateAlpha->Release();
	spriteObject->Release();
	pRenderTargetView->Release();
	pSwapChain->Release();
	pD3DDevice->Release();
}

CGame* CGame::GetInstance()
{
	if (__instance == NULL) __instance = new CGame();
	return __instance;
}
