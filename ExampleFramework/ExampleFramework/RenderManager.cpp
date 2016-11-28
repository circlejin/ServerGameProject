#include "Common.h"
#include "RenderManager.h"


namespace BONE_FRAMEWORK
{
	BOOL CRenderManager::InitializeMembers()
	{
		d3d9 = NULL;
		d3dDevice = NULL;
		d3dSprite = NULL;

		return TRUE;
	}

	BOOL CRenderManager::ReleaseMembers()
	{
		if (d3dDevice != NULL)
			d3dDevice->Release();
		if (d3d9 != NULL)
			d3d9->Release();
		if (d3dSprite != NULL)
			d3dSprite->Release();

		return TRUE;
	}

	HRESULT CRenderManager::Create(HWND _hWnd)
	{
		if ((d3d9 = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
			return E_FAIL;

		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		if (FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3dDevice)))
			return E_FAIL;

		if (FAILED(D3DXCreateSprite(d3dDevice, &d3dSprite)))
			return E_FAIL;

		return S_OK;
	}

	BOOL CRenderManager::RenderStart()
	{
		if (d3dDevice == NULL)
			return FALSE;

		d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

		d3dDevice->BeginScene();

		d3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

		return TRUE;
	}

	VOID CRenderManager::RenderFinish()
	{
		d3dSprite->End();

		d3dDevice->EndScene();

		d3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	
}