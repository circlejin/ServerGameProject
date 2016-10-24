#include "Common.h"
#include "RenderManager.h"


namespace BONE_FRAMEWORK
{
	BOOL CRenderManager::InitializeMembers()
	{
		g_pD3D = NULL;
		g_pd3dDevice = NULL;
		g_pVB = NULL;

		return TRUE;
	}

	BOOL CRenderManager::ReleaseMembers()
	{
		if (g_pVB != NULL)
			g_pVB->Release();
		if (g_pd3dDevice != NULL)
			g_pd3dDevice->Release();
		if (g_pD3D != NULL)
			g_pD3D->Release();

		return TRUE;
	}

	HRESULT CRenderManager::InitD3D(HWND _hWnd)
	{
		if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
			return E_FAIL;

		D3DPRESENT_PARAMETERS d3dpp;
		
		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
			return E_FAIL;

		return S_OK;
	}

	HRESULT CRenderManager::InitVB()
	{
		CUSTOMVERTEX Vertices[] =
		{
			{ 150.0f, 50.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
			{ 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
			{ 50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, },
		};
		
		if (FAILED(g_pd3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, NULL)))
			return E_FAIL;

		VOID* pVertices;

		if (FAILED(g_pVB->Lock(0, sizeof(Vertices), (void**)&pVertices, 0)))
			return E_FAIL;

		memcpy(pVertices, Vertices, sizeof(Vertices));
		g_pVB->Unlock();

		return S_OK;
	}

	VOID CRenderManager::Render()
	{
		if (g_pd3dDevice == NULL)
			return;

		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

		if (SUCCEEDED(g_pd3dDevice->BeginScene()))
		{
			// ·»´õ¸µÇÒ ¾ÀÀº ¿©±â¼­ÇÑ´Ù
			g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
			g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
			// ¾À ·»´õ¸µ Á¾·á
			g_pd3dDevice->EndScene();
		}

		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	
}